#include "devices/keithley_2410.h"

const QMap<QString,DeviceParameterConstraint> Keithley_2410::_deviceParamMap = {
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READONLY)},
    {"R",DeviceParameterConstraint("R", 0.0, 0.0, READONLY)},
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)}
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

void Keithley_2410::init(){
    MeasurementDevice::init(_deviceName, interfaceName,_deviceParamMap);
}


void Keithley_2410::setOutputState(bool on){
    if (!_outputOn&&on){
        emit scpiCommand("OUT1");
    }
    if (_outputOn&&!on){
        emit scpiCommand("OUT0");
    }
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
    if (paramName=="I"){
        scpiCommandString = ":MEAS:CURR?";
    }
    if (paramName=="R"){
        scpiCommandString = ":MEAS:RES?";
    }
     if (paramName=="V"){
        scpiCommandString = ":MEAS:VOLT?";
    }
    return scpiCommandString;
}

QString Keithley_2410::translateSet(QString paramName, double paramValue){
    QString scpiCommandString = "";
    if (paramName=="I"){
        scpiCommandString = ":SOUR:CURR ";
    }
    if (paramName=="R"){
        scpiCommandString = ":SOUR:FREQ ";
    }
    if (paramName=="V"){
        scpiCommandString = ":SOUR:VOLT ";
    }
    return scpiCommandString;
}
double Keithley_2410::translateInc(QString receivedString){
    QString message = receivedString;
    //message.chop(0); // chop 2: the '\r' and the measurement unit
    //bool ok = false;
    QStringList wert1=message.split(",");
    double val = wert1[0].toDouble();//toDouble(&ok);
    //double val1 = wert1[1].toDouble();
    //double val2 = wert1[2].toDouble();
    //if (!ok){
    //return NAN;
    //}
    return val;
}
double Keithley_2410::translateInc1(QString receivedString){
    QString message = receivedString;
    //message.chop(0); // chop 2: the '\r' and the measurement unit
    //bool ok = false;
    QStringList wert1=message.split(",");
    int x=wert1.size();
    if(wert1.size()>1)
    //if (wert1[1]!=0)
    {
     double val1 = wert1[1].toDouble();
     return val1;
    }
    else{//double val1=0.0;
        double val1=wert1[0].toDouble();
    return val1;}
    //double val = wert1[0].toDouble();//toDouble(&ok);
    //double val2 = wert1[2].toDouble();
    //qDebug()<<"TEST1"<<wert1<<val1;//<<val2;
    //if (!ok){
    //    return NAN;
    //}
    //return val1;
}