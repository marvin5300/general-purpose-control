#include <devices/keithley_2000.h>

const QMap<QString,DeviceParameterConstraint> Keithley_2000::_deviceParamMap = {
    {"V",DeviceParameterConstraint("V", 0.0, 0.0, READWRITE)},
    {"I",DeviceParameterConstraint("I", 0.0, 0.0, READWRITE)},
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
void Keithley_2000::setOutputState(bool on){
    if (!_outputOn&&on){
        emit scpiCommand("OUT1");
    }
    if (_outputOn&&!on){
        emit scpiCommand("OUT0");
    }
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

QString Keithley_2000::translateSet(QString paramName, double paramValue){
    QString scpiCommandString = "";
    if (paramName=="C"){
        scpiCommandString = "VOLT ";
    }
    if (paramName=="I"){
        scpiCommandString = "CURR ";
    }
    if (paramName=="F"){
        scpiCommandString = "FREQ ";
    }
    return scpiCommandString;
}
double Keithley_2000::translateInc(QString receivedString){
    QString message = receivedString;
    //message.chop(0); // chop 2: the '\r' and the measurement unit
    //bool ok = false;
    QStringList wert1=message.split(",");
    double val = wert1[0].toDouble();//toDouble(&ok);
    //double val1 = wert1[1].toDouble();
    //double val2 = wert1[2].toDouble();
    //
    //if (!ok){
    //    return NAN;
    //}
    return val;
}
double Keithley_2000::translateInc1(QString receivedString){
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
   // qDebug()<<"TEST1"<<wert1<<val1;//<<val2;
    //if (!ok){
    //    return NAN;
    //}
    //return val1;
}
