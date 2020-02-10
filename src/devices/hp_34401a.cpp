#include <src/devices/hp_34401a.h>

const QMap<QString,DeviceParameterConstraint> HP_34401A::_deviceParamMap = {
};

HP_34401A::HP_34401A(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> HP_34401A::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString HP_34401A::getInterfaceName()const{
    return interfaceName;
}

void HP_34401A::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}
