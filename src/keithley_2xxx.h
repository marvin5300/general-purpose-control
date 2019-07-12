#ifndef KEITHLEY_2XXX_H
#define KEITHLEY_2XXX_H

#include "measurementdevice.h"

class Keithley_2xxx : public MeasurementDevice
{
public:
    using MeasurementDevice::MeasurementDevice;

public slots:
    void onReceivedMessage(QString message);
};

#endif // KEITHLEY_2XXX_H
