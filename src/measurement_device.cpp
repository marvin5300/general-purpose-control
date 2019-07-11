#include "measurement_device.h"
#include "rs232.h"
#include <QThread>

Measurement_Device::Measurement_Device(QWidget *parent) :
    QGroupBox(parent)
{
#if defined(Q_OS_WIN)
    for (quint8 i = 1; i < 100; i++){
        ports << QString("COM"+(int)i);
    }
#else
    for (quint8 i = 0; i < 100; i++){
        ports << QString("/dev/ttyACM"+(int)i);
    }
#endif
}

void Measurement_Device::onReceivedMessage(QString message){
    if (!correctDeviceConnected){
        if (message.contains(deviceName)){
            correctDeviceConnected = true;
            onConnectionStatusChanged(true);
        }else{

        }
    }
}

void Measurement_Device::onConnectionStatusChanged(bool connected){

}

void Measurement_Device::connectRS232() {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(portName, baudRate);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    // connect all signals not coming from Daemon to gps
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &Measurement_Device::onConnectionStatusChanged);
    connect(this, &Measurement_Device::disconnectRS232, serialConnection, &RS232::closeConnection);

    // connect all send/receive messages
    connect(this, &Measurement_Device::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &Measurement_Device::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
}
