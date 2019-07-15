#include "keithley_2000.h"

Keithley_2000::Keithley_2000(QString _interfaceName)
    : Keithley_2xxx(_interfaceName){
    init();
}

const QString Keithley_2000::getDeviceName(){
    return deviceName;
}

const QString Keithley_2000::getInterfaceName(){
    return interfaceName;
}

void Keithley_2000::init(){
    MeasurementDevice::init(deviceName);
}

void Keithley_2000::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
}

void Keithley_2000::connectRS232(){
    MeasurementDevice::connectRS232(interfaceName, baudRate);
}
