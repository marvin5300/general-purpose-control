#include "keithley_2xxx.h"

Keithley_2xxx::Keithley_2xxx(QWidget *parent) :
    MeasurementDevice(parent)
{

}

void Keithley_2xxx::onReceivedMessage(QString message){
    MeasurementDevice::onReceivedMessage(message);
    // do additional stuff
}
