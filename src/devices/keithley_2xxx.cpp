#include "keithley_2xxx.h"
#include <src/rs232.h>
#include <QThread>
#include <QVector>

void Keithley_2xxx::queueMeasure(quint64 number){
    measureID = number;
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

void Keithley_2xxx::setScanParameter(MeasurementValue value){
    //qDebug() << "setScanParameter: device status "<<correctDeviceConnected <<" deviceName: "<<deviceName();
    emit scanParameterReady(deviceName(),0);
    if (!correctDeviceConnected){
        return;
    }
    if (value.name!=""){
        emit scpiCommand(QString(translateSet(value.name)+" %1").arg(value.value));
        emit scpiCommand(":CONF?");
    }
}

QString Keithley_2xxx::translateMeas(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V"){
        scpiCommandString = ":MEAS:VOLT?";
    }
    if (paramName=="I"){
        scpiCommandString = ":MEAS:CURR?";
    }
    if (paramName=="R"){
        scpiCommandString = ":MEAS:RES?";
    }
    return scpiCommandString;
}

QString Keithley_2xxx::translateSet(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V"){
        scpiCommandString = ":CONF:VOLT";
    }
    if (paramName=="I"){
        scpiCommandString = ":CONF:CURR";
    }
    return scpiCommandString;
}

void Keithley_2xxx::onReceivedMessage(QString message){
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
    double val = 0.;
    bool ok = false;
    val = message.toDouble(&ok);
    if (!ok){
        qDebug() << "could not convert '" << message << "' to double";
        if (message.contains("CURR")||message.contains("VOLT")||message.contains("RES")){
            emit scanParameterReady(deviceName(),measureID);
        }
        return;
    }
    measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val));
    if (activeMeasParams.isEmpty()){
        emit measuredValues(deviceName(),measureResults,measureID);
        emit measureReady(deviceName(),measureID);
        measureResults.clear();
    }
}

bool Keithley_2xxx::checkDevice(QString message){
    if (!correctDeviceConnected){ // first queued message is "*IDN?" and this should return the device name
        if (message.contains(deviceName())){
            correctDeviceConnected = true;
            setUiConnectionState(true);
        }else{
            setUiConnectionState(false);
        }
        qDebug() << "device name: " << deviceName() << " device status... correct device?" << correctDeviceConnected;
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

    // connect all send/receive messages
    connect(this, &MeasurementDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &MeasurementDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}
