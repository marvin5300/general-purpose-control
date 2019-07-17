#include "keithley_2000.h"

const QMap<QString,DeviceParameterConstraint> Keithley_2000::deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READONLY)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2000::Keithley_2000(QString _interfaceName)
    : Keithley_2xxx(_interfaceName){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2000::getDeviceParameterConstraints()const{
    return deviceParamMap;
}

const QString Keithley_2000::getDeviceName()const{
    return deviceName;
}

const QString Keithley_2000::getInterfaceName()const{
    return interfaceName;
}

void Keithley_2000::init(){
    MeasurementDevice::init(deviceName, interfaceName);
}

void Keithley_2000::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
}

void Keithley_2000::connectRS232(){
    MeasurementDevice::connectRS232(interfaceName, baudRate);
}
