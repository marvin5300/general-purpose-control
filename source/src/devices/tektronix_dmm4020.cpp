#include "devices/tektronix_dmm4020.h"

const QMap<QString,DeviceParameterConstraint> Tektronix_DMM4020::_deviceParamMap = {
};

Tektronix_DMM4020::Tektronix_DMM4020(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> Tektronix_DMM4020::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString Tektronix_DMM4020::getInterfaceName()const{
    return interfaceName;
}

void Tektronix_DMM4020::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}
