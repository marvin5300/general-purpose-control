#include "devices/keithley_2410.h"

const QMap<QString,DeviceParameterConstraint> Keithley_2410::_deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)}
};

Keithley_2410::Keithley_2410(QString _interfaceName, quint32 _baudRate, QWidget *parent)
    : ScpiDevice(_interfaceName,_baudRate,parent){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2410::getDeviceParameterConstraints()const{
    return _deviceParamMap;
}

const QString Keithley_2410::getInterfaceName()const{
    return interfaceName;
}

/*
void Keithley_2410::onReceivedMessage(QString message){
    if (!correctDeviceConnected){
        if (checkDevice(message)==false){

        }
        return;
    }
    // build measurement values and send them
    if (activeMeasParams.isEmpty()){
        qDebug() << "expected no message, got '"<< message <<"'";
        return;
    }
    double val = 0.;
    bool ok = false;
    val = message.toDouble(&ok);
    if (!ok){
        qDebug() << "could not convert '" << message << "' to double";
        if (message.contains("CURR")||message.contains("VOLT")||message.contains("RES")){
            emit scanParameterReady(deviceName(),measureID);
        }
        return;
    }
    measureResults.append(MeasurementValue(activeMeasParams.takeFirst(),val));
    if (activeMeasParams.isEmpty()){
        emit measuredValues(deviceName(),measureResults,measureID);
        emit measureReady(deviceName(),measureID);
        measureResults.clear();
    }
}
*/

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

void Keithley_2410::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}

