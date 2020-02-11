#include <src/devices/gw_instek_gpd4303s.h>
#include <math.h>

const QMap<QString,DeviceParameterConstraint> GW_INSTEK_GPD4303S::_deviceParamMap = {
    {"V1",DeviceParameterConstraint("V1", 0.0, 30, READWRITE)},
    {"V2",DeviceParameterConstraint("V2", 0.0, 30, READWRITE)},
    {"V3",DeviceParameterConstraint("V3", 0.0, 10, READWRITE)},
    {"V4",DeviceParameterConstraint("V4", 0.0, 5, READWRITE)},
    {"I1",DeviceParameterConstraint("I1", 0.0, 3, READWRITE)},
    {"I2",DeviceParameterConstraint("I2", 0.0, 3, READWRITE)},
    {"I3",DeviceParameterConstraint("I3", 0.0, 3, READWRITE)},
    {"I4",DeviceParameterConstraint("I4", 0.0, 3, READWRITE)}
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

void GW_INSTEK_GPD4303S::setOutputState(bool on){
    if (!_outputOn&&on){
        emit scpiCommand("OUT1");
    }
    if (_outputOn&&!on){
        emit scpiCommand("OUT0");
    }
}

QString GW_INSTEK_GPD4303S::translateMeas(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V1"){
        scpiCommandString = "VOUT1?";
    }
    if (paramName=="V2"){
        scpiCommandString = "VOUT2?";
    }
    if (paramName=="V3"){
        scpiCommandString = "VOUT3?";
    }
    if (paramName=="V4"){
        scpiCommandString = "VOUT4?";
    }
    if (paramName=="I1"){
        scpiCommandString = "IOUT1?";
    }
    if (paramName=="I2"){
        scpiCommandString = "IOUT2?";
    }
    if (paramName=="I3"){
        scpiCommandString = "IOUT3?";
    }
    if (paramName=="I4"){
        scpiCommandString = "IOUT4?";
    }
    return scpiCommandString;
}

QString GW_INSTEK_GPD4303S::translateSet(QString paramName){
    QString scpiCommandString = "";
    if (paramName=="V1"){
        scpiCommandString = "VSET1:";
    }
    if (paramName=="V2"){
        scpiCommandString = "VSET2:";
    }
    if (paramName=="V3"){
        scpiCommandString = "VSET3:";
    }
    if (paramName=="V4"){
        scpiCommandString = "VSET4:";
    }
    if (paramName=="I1"){
        scpiCommandString = "ISET1:";
    }
    if (paramName=="I2"){
        scpiCommandString = "ISET2:";
    }
    if (paramName=="I3"){
        scpiCommandString = "ISET3:";
    }
    if (paramName=="I4"){
        scpiCommandString = "ISET4:";
    }
    return scpiCommandString;
}

double GW_INSTEK_GPD4303S::translateInc(QString receivedString){
    QString message = receivedString;
    message.chop(1); // chop 1 because it always provides the measurement unit too
    bool ok = false;
    double val = message.toDouble(&ok);
    if (!ok){
        return NAN;
    }
    return val;
}
