
const QMap<QString,DeviceParameterConstraint> Keithley_2410::_deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

QString Keithley_2410::translateMeas(QString paramName){
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

QString Keithley_2410::translateSet(QString paramName, double paramValue){
    QString scpiMsgString = "";
    ...
    return scpiMsgString;
}

double translateInc(QString receivedString){
    double val = 0.;
    ...
    return val;
}
