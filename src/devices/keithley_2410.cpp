#include "keithley_2410.h"

const QMap<QString,DeviceParameterConstraint> Keithley_2410::deviceParamMap;

Keithley_2410::Keithley_2410(QString _interfaceName)
    : Keithley_2xxx(_interfaceName){
    init();
}

const QMap<QString,DeviceParameterConstraint> Keithley_2410::getDeviceParameterConstraints()const{
    return deviceParamMap;
}

const QString Keithley_2410::getDeviceName()const{
    return deviceName;
}

const QString Keithley_2410::getInterfaceName()const{
    return interfaceName;
}

const QList<MeasurementValue> Keithley_2410::getMeasures(){
    return QList<MeasurementValue>();
}

MeasurementValue Keithley_2410::getMeasure(QString valueName){

}

void Keithley_2410::setScanParameter(MeasurementValue value){

}

void Keithley_2410::init(){
    MeasurementDevice::init(deviceName, interfaceName,deviceParamMap);
}

void Keithley_2410::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
}

void Keithley_2410::connectRS232(){
    MeasurementDevice::connectRS232(interfaceName, baudRate);
}
