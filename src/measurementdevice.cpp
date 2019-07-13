#include "measurementdevice.h"
#include "rs232.h"
#include <QThread>

MeasurementDevice::MeasurementDevice(QString _portName, quint32 _baudRate, QWidget *parent) :
    QGroupBox(parent)
{
}

void MeasurementDevice::onReceivedMessage(QString message){
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

void MeasurementDevice::connectRS232() {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(portName, baudRate);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(this, &MeasurementDevice::closeConnection, serialConnection, &RS232::closeConnection);
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &MeasurementDevice::onConnectionStatusChanged);
    connect(this, &MeasurementDevice::disconnectRS232, serialConnection, &RS232::closeConnection);

    // connect all send/receive messages
    connect(this, &MeasurementDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}

void MeasurementDevice::setPort(QString _portName){
    emit closeConnection();
    portName = _portName;
    connectRS232();
}

void MeasurementDevice::exit(){
    emit closeConnection();
    this->deleteLater();
}
