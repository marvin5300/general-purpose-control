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
    ui->closeButton->setStyleSheet(":!hover{ border-image: url(:/res/close1.png)}:hover{ border-image: url(:/res/close2.png);}");
    connect(ui->closeButton, &QPushButton::clicked, this, &MeasurementDevice::exit);
    ui->deviceNameSelectBox->setModel(DeviceManager::getAllDeviceNameModel());
    connect(ui->deviceNameSelectBox, &QComboBox::currentTextChanged, this, &MeasurementDevice::onDeviceSelectionChanged);
}

quint32 MeasurementDevice::getLocalId(){
    return localId;
}

MeasurementDevice::~MeasurementDevice()
{
    delete ui;
}

void MeasurementDevice::onReceivedMessage(QString message){

}

void MeasurementDevice::checkDevice(QString _deviceName, QString message){
    if (!correctDeviceConnected){ // first queued message is "*IDN?" and this should return the device name
        if (message.contains(_deviceName)){
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
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);
    connect(this, &MeasurementDevice::disconnectRS232, serialConnection, &RS232::closeConnection);

    // connect all send/receive messages
    connect(this, &MeasurementDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}

void MeasurementDevice::setInterface(QString _interfaceName){
    emit closeConnection();
    interfaceName = _interfaceName;
    connectRS232();
}

void MeasurementDevice::onDeviceSelectionChanged(QString _deviceName){

}

void MeasurementDevice::exit(){
    //QPointer<MeasurementDevice> thisObject = this;
    DeviceManager::removeDevice(this);
    emit closeConnection();
    this->deleteLater();
}
