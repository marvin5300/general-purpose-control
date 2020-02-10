#include <src/devices/keithley_2000.h>

const QMap<QString,DeviceParameterConstraint> Keithley_2000::_deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READONLY)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2000::Keithley_2000(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2000::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString Keithley_2000::getInterfaceName()const{
    return interfaceName;
}

void Keithley_2000::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}

QString Keithley_2000::translateMeas(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V"){
        scpiCommandString = ":MEAS:VOLT?";
    }
    if (paramName=="I"){
        scpiCommandString = ":MEAS:CURR?";
    }
    if (paramName=="R"){
        scpiCommandString = ":MEAS:RES?";
    }
    return scpiCommandString;
}

