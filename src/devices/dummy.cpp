#include <src/devices/dummy.h>

Dummy::Dummy()
    : MeasurementDevice("not selected")
{
    init();
}

const QString Dummy::getInterfaceName()const{
    return QString("not selected");
}

void Dummy::onReceivedMessage(QString message){
}

void Dummy::init(){
    MeasurementDevice::init(_deviceName, interfaceName);
}

void Dummy::queueMeasure(quint64 count){

}
