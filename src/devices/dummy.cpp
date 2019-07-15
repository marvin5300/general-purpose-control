#include "dummy.h"

Dummy::Dummy()
    : MeasurementDevice("default")
{
    init();
}

const QString Dummy::getDeviceName(){
    return deviceName;
}

const QString Dummy::getInterfaceName(){
    return QString("not selected");
}

void Dummy::onReceivedMessage(QString message){
}

void Dummy::connectRS232(){
}


void Dummy::init(){
    MeasurementDevice::init(deviceName, interfaceName);
}
