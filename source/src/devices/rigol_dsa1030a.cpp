#include <devices/rigol_dsa1030a.h>

const QMap<QString,DeviceParameterConstraint> RIGOL_DSA1030A::_deviceParamMap = {
};

RIGOL_DSA1030A::RIGOL_DSA1030A(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> RIGOL_DSA1030A::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString RIGOL_DSA1030A::getInterfaceName()const{
    return interfaceName;
}

void RIGOL_DSA1030A::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}
