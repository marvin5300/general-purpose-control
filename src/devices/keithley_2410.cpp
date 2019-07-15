#include "keithley_2410.h"

const QString Keithley_2410::getDeviceName(){
    return deviceName;
}

const QString Keithley_2410::getInterfaceName(){
    return interfaceName;
}

void Keithley_2410::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
}

void Keithley_2410::connectRS232(){
    MeasurementDevice::connectRS232(interfaceName, baudRate);
}
