#include "dummy.h"

Dummy::Dummy()
    : MeasurementDevice("not selected")
{
    init();
}

const QString Dummy::getDeviceName()const{
    return deviceName;
}

const QString Dummy::getInterfaceName()const{
    return QString("not selected");
}

void Dummy::onReceivedMessage(QString message){
}

void Dummy::init(){
    MeasurementDevice::init(deviceName, interfaceName);
}

void Dummy::queueMeasure(quint64 count){

}

bool Dummy::checkDevice(QString message){
    return false;
}

void Dummy::connectBus(){

}
