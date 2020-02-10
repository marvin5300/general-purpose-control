#include <src/devices/scpidevice.h>
#include <src/rs232.h>
#include <QThread>
#include <QVector>
#include <ui_measurementdevice.h>

void ScpiDevice::queueMeasure(quint64 number){
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

void ScpiDevice::setScanParameter(MeasurementValue value){
    //qDebug() << "setScanParameter: device status "<<correctDeviceConnected <<" deviceName: "<<deviceName();
    if (!correctDeviceConnected){
        return;
    }
    if (value.name!=""&&deviceParamMap().value(value.name).mode>1){
        emit scpiCommand(QString(translateSet(value.name)+"%1").arg(value.value));
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
    double val = 0.;
    bool ok = false;
    val = message.toDouble(&ok);
    if (!ok){
        return;
    }
    measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val));
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
            setUiConnectionState(false);
        }
        qDebug() << "device name: " << deviceName() << " device status... correct device?" << correctDeviceConnected;
    }
}

void ScpiDevice::connectBus(){
    connectRS232(interfaceName,baudRate);
}

void ScpiDevice::connectRS232(QString _interfaceName, quint32 _baudRate) {
    // here is where the magic threading happens look closely
    QThread *serialThread = new QThread();
    RS232 *serialConnection = new RS232(_interfaceName, _baudRate);
    serialConnection->moveToThread(serialThread);
    // connect all signals about quitting
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(this, &ScpiDevice::closeConnection, serialConnection, &RS232::closeConnection);
    connect(serialThread, &QThread::started, serialConnection, &RS232::makeConnection);
    //connect(serialConnection, &RS232::serialRestart, this, &MainWindow::connectRS232);
    connect(serialConnection, &RS232::connectionStatus, this, &ScpiDevice::onConnectionStatusChanged);

    // connect all send/receive messages
    connect(this, &ScpiDevice::scpiCommand, serialConnection, &RS232::sendScpiCommand);
    connect(serialConnection, &RS232::receivedMessage, this, &ScpiDevice::onReceivedMessage);

    // after thread start there will be a signal emitted which starts the RS232 makeConnection function
    serialThread->start();
    emit scpiCommand(QString("*IDN?")); // standard message to ask for device information
}
