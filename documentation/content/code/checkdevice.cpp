bool ScpiDevice::checkDevice(QString message){
    if (!correctDeviceConnected){
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
