#include "devices/sourcetronic_st2819a.h"

const QMap<QString,DeviceParameterConstraint> SourceTronic_ST2819A::_deviceParamMap = {
    {"C",DeviceParameterConstraint("C", 0.0, 0.0, READONLY)},
};

SourceTronic_ST2819A::SourceTronic_ST2819A(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> SourceTronic_ST2819A::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString SourceTronic_ST2819A::getInterfaceName()const{
    return interfaceName;
}

void SourceTronic_ST2819A::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
    // initialize scpiCommand("...");
}

