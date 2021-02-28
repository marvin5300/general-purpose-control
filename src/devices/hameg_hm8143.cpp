#include "devices/hameg_hm8143.h"

const QMap<QString,DeviceParameterConstraint> Hameg_HM8143::_deviceParamMap = {
};

Hameg_HM8143::Hameg_HM8143(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> Hameg_HM8143::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString Hameg_HM8143::getInterfaceName()const{
    return interfaceName;
}

void Hameg_HM8143::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}
