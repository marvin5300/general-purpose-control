#include "keithley_2xxx.h"
#include <src/rs232.h>
#include <QThread>

void Keithley_2xxx::queueMeasure(quint64 count){

}

void Keithley_2xxx::onReceivedMessage(QString message){
    if (checkDevice(message)==false){
        return;
    }
    // build measurement values and send them
}

bool Keithley_2xxx::checkDevice(QString message){
    if (!correctDeviceConnected){ // first queued message is "*IDN?" and this should return the device name
        if (message.contains(deviceName)){
            correctDeviceConnected = true;
            onConnectionStatusChanged(true);
        }else{
            onConnectionStatusChanged(false);
        }
    }
}

void Keithley_2xxx::connectBus(){
    connectRS232(interfaceName,baudRate);
}

void Keithley_2xxx::connectRS232(QString _interfaceName, quint32 _baudRate) {
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

    // connect all send/receive messages
    connect(this, &MeasurementDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}
