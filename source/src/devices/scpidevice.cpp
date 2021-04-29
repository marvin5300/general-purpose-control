#include "devices/scpidevice.h"
#include "serial.h"
#include "ui_measurementdevice.h"
#include <QThread>
#include <QVector>

void ScpiDevice::queueMeasure(quint64 number){
    measureID = number;
    qDebug()<<"queueMeasure";
    activeMeasParams.clear();
    for (int i = 0; i < ui->parameterTableWidget->rowCount(); i++){
        auto item = ui->parameterTableWidget->item(i,0);
        if (item->checkState()){
            activeMeasParams.append(item->text());
        }
    }
    if (activeMeasParams.size()==0){
        emit measureReady(deviceName(),measureID);
    }
    if (!correctDeviceConnected){
        return;
    }
    for (int i = 0; i < activeMeasParams.size(); i++){
        emit scpiCommand(translateMeas(activeMeasParams.at(i)));
    }
}

void ScpiDevice::setScanParameter(MeasurementValue value){
    qDebug() << "setScanParameter: device status "<<correctDeviceConnected <<" deviceName: "<<deviceName();
    if (!correctDeviceConnected){
        return;
    }
    if (value.name!=""&&deviceParamMap().value(value.name).mode>1){
        emit scpiCommand(QString(translateSet(value.name, value.value)+"%1").arg(value.value));
        emit scanParameterReady(deviceName(),0);
    }else{
        emit scanParameterReady(deviceName(),0);
    }
}


void ScpiDevice::onReceivedMessage(QString message){
    if (!correctDeviceConnected){
        if (checkDevice(message)==false){

        }
        return;
    }
    // build measurement values and send them
    if (activeMeasParams.isEmpty()){
        qDebug() << "expected no message, got '"<< message <<"'";
        return;
    }
    double val = translateInc(message);
    double val1 = translateInc1(message);
    if (val1 !=0)
    {
       measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val,val1));
    }else
    {
        measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val));
    }

    //measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val,val1));
    qDebug() <<"TEST!"<<message<<val<<val1;
    if (activeMeasParams.isEmpty()){
        emit measuredValues(deviceName(),measureResults,measureID);
        emit measureReady(deviceName(),measureID);
        measureResults.clear();
    }
}

bool ScpiDevice::checkDevice(QString message){
    if (!correctDeviceConnected){ // first queued message is "*IDN?" and this should return the device name
        if (message.contains(deviceName())){
            correctDeviceConnected = true;
            setUiConnectionState(true);
        }else{
            correctDeviceConnected = false;
            setUiConnectionState(false);
        }
        qDebug() << "device name: " << deviceName() << " device status... correct device?" << correctDeviceConnected;
    }
    return correctDeviceConnected;
}

void ScpiDevice::connectBus(){
    connectSerial(interfaceName,baudRate);
}

void ScpiDevice::connectSerial(QString _interfaceName, quint32 _baudRate) {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    Serial *serialConnection = new Serial(_interfaceName, _baudRate, terminator());
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(this, &ScpiDevice::closeConnection, serialConnection, &Serial::closeConnection);
    connect(serialThread, &QThread::started, serialConnection, &Serial::makeConnection);
    //connect(serialConnection, &Serial::serialRestart, this, &MainWindow::connectSerial);
    connect(serialConnection, &Serial::connectionStatus, this, &ScpiDevice::onConnectionStatusChanged);

    // connect all send/receive messages
    connect(this, &ScpiDevice::scpiCommand, serialConnection, &Serial::sendScpiCommand);
    connect(serialConnection, &Serial::receivedMessage, this, &ScpiDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the Serial makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}
