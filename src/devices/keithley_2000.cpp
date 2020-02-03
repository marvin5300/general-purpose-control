#include <src/devices/keithley_2000.h>

const QMap<QString,DeviceParameterConstraint> Keithley_2000::deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READONLY)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2000::Keithley_2000(QString _interfaceName, quint32 _baudRate, QWidget *parent) : ScpiDevice(_interfaceName){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2000::getDeviceParameterConstraints()const{
    return deviceParamMap;
}

const QString Keithley_2000::getInterfaceName()const{
    return interfaceName;
}

void Keithley_2000::init(){
    MeasurementDevice::init(_deviceName, interfaceName,deviceParamMap);
}

