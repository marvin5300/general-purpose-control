#include "measurementdevice.h"
#include "ui_measurementdevice.h"
#include "devicemanager.h"
#include "rs232.h"
#include <QThread>

quint64 MeasurementDevice::globalIdCounter = 0;

MeasurementDevice::MeasurementDevice(QString _portName, quint32 _baudRate, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MeasurementDevice)
{
    ui->setupUi(this);
    interfaceName = _portName;
    baudRate = _baudRate;
    localId = globalIdCounter;
    globalIdCounter++;
    this->setFrameShadow(QFrame::Plain);
    this->setFrameShape(QFrame::StyledPanel);
    this->setMidLineWidth(1);
    ui->settingsTableWidget->setFrameShadow(QTableWidget::Plain);
    ui->settingsTableWidget->setFrameShape(QTableWidget::StyledPanel);
    ui->settingsTableWidget->setStyleSheet("border: none;");
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &MeasurementDevice::exit);
    ui->deviceNameSelectBox->setModel(DeviceManager::getAllDeviceNameModel());
    ui->interfaceNameSelectBox->setModel(DeviceManager::getAllInterfaceNameModel());
}

void MeasurementDevice::init(QString _deviceName, QString _interfaceName){
    ui->deviceNameSelectBox->setCurrentIndex(ui->deviceNameSelectBox->findText(_deviceName));
    connect(ui->deviceNameSelectBox, &QComboBox::currentTextChanged, this, &MeasurementDevice::onDeviceSelectionChanged);
    ui->interfaceNameSelectBox->setCurrentIndex(ui->interfaceNameSelectBox->findText(_interfaceName));
    connect(ui->interfaceNameSelectBox, &QComboBox::currentTextChanged, this, &MeasurementDevice::onInterfaceSelectionChanged);
    //interfaceName = _interfaceName;
    if (_interfaceName!="not selected"&&_interfaceName!=""){
        connectRS232();
    }else{
        ui->deviceNameSelectBox->setStyleSheet("color: black;");
        ui->interfaceNameSelectBox->setStyleSheet("color: black;");
    }
}

const quint64 MeasurementDevice::getLocalId(){
    return localId;
}

MeasurementDevice::~MeasurementDevice()
{
    delete ui;
}

void MeasurementDevice::onReceivedMessage(QString message){
    checkDevice(message);
}

void MeasurementDevice::checkDevice(QString message){
    if (!correctDeviceConnected){ // first queued message is "*IDN?" and this should return the device name
        if (message.contains(deviceName)){
            correctDeviceConnected = true;
            onConnectionStatusChanged(true);
        }else{
            onConnectionStatusChanged(false);
        }
    }
}

void MeasurementDevice::onConnectionStatusChanged(bool connected){
    // should connect to signalise the gui that connection is established or not

}

void MeasurementDevice::setUiConnectionState(bool connected){
    if (connected){
        ui->deviceNameSelectBox->setStyleSheet("color: green;");
        ui->interfaceNameSelectBox->setStyleSheet("color: green;");
    }else{
        ui->deviceNameSelectBox->setStyleSheet("color: red;");
        ui->interfaceNameSelectBox->setStyleSheet("color: red;");
    }
}

void MeasurementDevice::connectRS232(QString _interfaceName, quint32 _baudRate) {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(_interfaceName, _baudRate);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(this, &MeasurementDevice::closeConnection, serialConnection, &RS232::closeConnection);
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &MeasurementDevice::onConnectionStatusChanged);
    connect(serialConnection, &RS232::connectionStatus, this, &MeasurementDevice::setUiConnectionState);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // connect all send/receive messages
    connect(this, &MeasurementDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}

void MeasurementDevice::onInterfaceSelectionChanged(QString _interfaceName){
    emit closeConnection();
    interfaceName = _interfaceName;
    DeviceManager::actualizeDeviceNameModel();
    if (_interfaceName!="not selected"&&_interfaceName!=""){
        connectRS232();
    }else{
        ui->deviceNameSelectBox->setStyleSheet("color: black;");
        ui->interfaceNameSelectBox->setStyleSheet("color: black;");
    }
}

void MeasurementDevice::onDeviceSelectionChanged(QString _newDeviceName){
    // create new device on same location but different subclass
    emit deviceSelectionChange(QPointer<MeasurementDevice>(this),_newDeviceName, interfaceName);
    exit();
}

void MeasurementDevice::exit(){
    //QPointer<MeasurementDevice> thisObject = this;
    DeviceManager::removeDevice(this);
    emit closeConnection();
    this->deleteLater();
}
