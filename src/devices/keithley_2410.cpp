#include <src/devices/keithley_2410.h>

const QMap<QString,DeviceParameterConstraint> Keithley_2410::deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2410::Keithley_2410(QString _interfaceName, quint32 _baudRate, QWidget *parent) : ScpiDevice(_interfaceName){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2410::getDeviceParameterConstraints()const{
    return deviceParamMap;
}

const QString Keithley_2410::getInterfaceName()const{
    return interfaceName;
}

void Keithley_2410::init(){
    MeasurementDevice::init(_deviceName, interfaceName,deviceParamMap);
}

