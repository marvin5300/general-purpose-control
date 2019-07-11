#include "rs232.h"
#include <sstream>
#include <iostream>
#include <QDebug>
//#include <iomanip>
#include <QThread>

RS232::RS232(QString _portName, quint32  _baudRate, QString _deviceName, QObject *parent) : QObject(parent)
{
    portName = _portName;
    baudRate = _baudRate;
    deviceName = _deviceName;
}

void RS232::makeConnection() {
    // this function gets called with a signal from client-thread

    if (!serialPort.isNull()) {
        serialPort.clear();
    }
    serialPort = new QSerialPort(portName);
    serialPort->setBaudRate(baudRate);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setDataBits(QSerialPort::Data8);
    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << (QObject::tr("Failed to open port %1, error: %2\ntrying again in %3 seconds\n")
            .arg(portName)
            .arg(serialPort->errorString())
            .arg(timeout));
        serialPort.clear();
        QThread::usleep(timeout);
        //emit serialRestart(portName, baudRate);
        emit connectionStatus(false, portName);
        this->deleteLater();
        return;
    }
    connect(serialPort, &QSerialPort::readyRead, this, &RS232::onReadyRead);
    serialPort->clear(QSerialPort::AllDirections);
    sendScpiCommand("*IDN?");
}

void RS232::onReadyRead() {
    // this function gets called when the serial port emits readyRead signal
    QByteArray temp = serialPort->readAll();
    for (int i=0; i<temp.size(); i++) {
        buffer+=temp.data()[i];
    }
    //if (buffer.empty()){
        //std::cout << "\nread: " << std::flush;
    //    emit receivedMessage("received: ");
    //}
    //std::cout << temp.toStdString();
    //emit receivedMessage(QString::fromStdString(temp.toStdString()));
    while (scanMessage(buffer)) {};
}

bool RS232::scanMessage(std::string& buffer){
    // Reads the buffer and returns true if a complete message is found.
    // If so: removes it from the buffer and starts the processing of this message.
    std::string message = "";
    for (std::string::size_type  i = 0; i < buffer.size(); i++){
        if (buffer[i]==terminator){
            buffer.erase(0, message.size()+1);
            if (!message.empty()){
                emit receivedMessage(QString::fromStdString(message+"\n"));
                processMessage(message);
                return true;
            }
        }
        message += buffer[i];
    }
    return false;
}

void RS232::processMessage(std::string& message){
    if (!correctDeviceConnected){
        QString someString = QString::fromStdString(message);
        if (someString.contains(deviceName)){
            correctDeviceConnected = true;
            emit connectionStatus(true, portName);
        }else{
            closeConnection(portName);
        }
    }
// here comes all the fun stuff to do with parsing messages from the device
}

void RS232::sendScpiCommand(QString command){
    if (serialPort.isNull()) {
        return;
    }
    //std::cout << "\nsend:" << (command.toStdString()+terminator) << std::endl;
    //emit receivedMessage(QString(command + terminator + "\n"));
    serialPort->write((command.toStdString()+""+terminator).c_str(), command.length()+1);
}

void RS232::closeConnection(QString _portName){
    if (_portName == portName){
        closeSerialPort();
        emit connectionStatus(false, portName);
        this->deleteLater();
    }
}

void RS232::closeSerialPort(){
    if (!serialPort.isNull()){
        serialPort->close();
        serialPort.clear();
    }
}
