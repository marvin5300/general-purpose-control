const QStringList DeviceManager::deviceNameList({
                                           "MODEL 2000",
                                           "MODEL 2410",
                                           "ST2819A"
                                           // ...
    });
QPointer<MeasurementDevice> DeviceManager::getDevice(QString deviceName, QString portName) {
    static QPointer<MeasurementDevice> device;
    if (deviceName == "not selected") {
        device = new Dummy();
    }
    if (deviceName == deviceNameList.at(0)) {
        device = new Keithley_2000(portName);
    }
    // ...
}