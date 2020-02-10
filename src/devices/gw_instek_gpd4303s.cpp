#include <src/devices/gw_instek_gpd4303s.h>

const QMap<QString,DeviceParameterConstraint> GW_INSTEK_GPD4303S::_deviceParamMap = {
    {"V",DeviceParameterConstraint("V1", 0.0, 30, READWRITE)},
    {"V",DeviceParameterConstraint("V2", 0.0, 30, READWRITE)},
    {"V",DeviceParameterConstraint("V3", 0.0, 10, READWRITE)},
    {"V",DeviceParameterConstraint("V4", 0.0, 5, READWRITE)},
    {"I",DeviceParameterConstraint("I1", 0.0, 3, READWRITE)},
    {"I",DeviceParameterConstraint("I2", 0.0, 3, READWRITE)},
    {"I",DeviceParameterConstraint("I3", 0.0, 3, READWRITE)},
    {"I",DeviceParameterConstraint("I4", 0.0, 3, READWRITE)}
};

GW_INSTEK_GPD4303S::GW_INSTEK_GPD4303S(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> GW_INSTEK_GPD4303S::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString GW_INSTEK_GPD4303S::getInterfaceName()const{
    return interfaceName;
}

void GW_INSTEK_GPD4303S::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}

QString GW_INSTEK_GPD4303S::translateMeas(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V"){
        scpiCommandString = "VOUT1?";
    }
    if (paramName=="I"){
        scpiCommandString = "IOUT1?";
    }
    return scpiCommandString;
}

QString GW_INSTEK_GPD4303S::translateSet(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V"){
        scpiCommandString = "VSET1:";
    }
    if (paramName=="I"){
        scpiCommandString = "ISET1:";
    }
    return scpiCommandString;
}
