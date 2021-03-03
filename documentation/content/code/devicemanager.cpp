const QStringList DeviceManager::deviceNameList({
                                           "MODEL 2000",
                                           "MODEL 2410",
                                           "ST2819A",
                                           "DMM4020",
                                           "PSP1803",
                                           "RIGOL DSA1030A",
                                           "HP 34401A",
                                           "Hameg HM8143",
                                           "GPD-4303S"
    });

QPointer<MeasurementDevice> DeviceManager::getDevice(QString deviceName, QString portName) {
    static QPointer<MeasurementDevice> device;
    if (deviceName == "not selected") {
        device = new Dummy();
    }
    if (deviceName == deviceNameList.at(0)) {
        device = new Keithley_2000(portName);
    }
    if (deviceName == deviceNameList.at(1)) {
        device = new Keithley_2410(portName);
    }
    if (deviceName == deviceNameList.at(2)) {
        device = new SourceTronic_ST2819A(portName);
    }
    if (deviceName == deviceNameList.at(3)) {
        device = new Tektronix_DMM4020(portName);
    }
    if (deviceName == deviceNameList.at(4)) {
        device = new Voltcraft_PSP1803(portName);
    }
    if (deviceName == deviceNameList.at(5)) {
        device = new RIGOL_DSA1030A(portName);
    }
    if (deviceName == deviceNameList.at(6)) {
        device = new HP_34401A(portName);
    }
    if (deviceName == deviceNameList.at(7)) {
        device = new Hameg_HM8143(portName);
    }
    if (deviceName == deviceNameList.at(8)) {
        device = new GW_INSTEK_GPD4303S(portName);
    }
    activeDevicesList.append(device);
    return device;
}