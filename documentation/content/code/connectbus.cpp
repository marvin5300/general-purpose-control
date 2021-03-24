void ScpiDevice::connectBus(){
    connectSerial(interfaceName,baudRate);
}

void ScpiDevice::connectSerial(QString _interfaceName, quint32 _baudRate) {
    QThread *serialThread = new QThread();
    Serial *serialConnection = new Serial(_interfaceName, _baudRate, terminator());
    serialConnection->moveToThread(serialThread);
    connect(serialThread, &QThread::finished, serialThread, &QThread::deleteLater);
    connect(this, &ScpiDevice::closeConnection, serialConnection, &Serial::closeConnection);
    connect(serialThread, &QThread::started, serialConnection, &Serial::makeConnection);
    connect(serialConnection, &Serial::connectionStatus, this, &ScpiDevice::onConnectionStatusChanged);
    connect(this, &ScpiDevice::scpiCommand, serialConnection, &Serial::sendScpiCommand);
    connect(serialConnection, &Serial::receivedMessage, this, &ScpiDevice::onReceivedMessage);
    serialThread->start();
    emit scpiCommand(QString("*IDN?"));
}
