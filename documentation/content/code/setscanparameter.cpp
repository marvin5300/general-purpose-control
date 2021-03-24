void ScpiDevice::setScanParameter(MeasurementValue value) {
    if (!correctDeviceConnected) {
        return;
    }
    if (value.name != "" && deviceParamMap().value(value.name).mode > 1) {
        emit scpiCommand(QString(translateSet(value.name, value.value) + "%1").arg(value.value));
        emit scanParameterReady(deviceName(), 0);
    }
    else {
        emit scanParameterReady(deviceName(), 0);
    }
}
