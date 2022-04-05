#include <devices/voltcraft_psp1803.h>

const QMap<QString,DeviceParameterConstraint> Voltcraft_PSP1803::_deviceParamMap = {
};

Voltcraft_PSP1803::Voltcraft_PSP1803(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> Voltcraft_PSP1803::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString Voltcraft_PSP1803::getInterfaceName()const{
    return interfaceName;
}

void Voltcraft_PSP1803::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}
