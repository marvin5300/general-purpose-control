#include "dummy.h"

Dummy::Dummy()
    : MeasurementDevice("default")
{

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
