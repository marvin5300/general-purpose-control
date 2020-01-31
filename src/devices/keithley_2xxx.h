#ifndef KEITHLEY_2XXX_H
#define KEITHLEY_2XXX_H

#include "../measurementdevice.h"

class Keithley_2xxx : public MeasurementDevice
{
public:
    using MeasurementDevice::MeasurementDevice;
public slots:
    void onReceivedMessage(QString message);
    void queueMeasure(quint64 count);
    void connectBus();
protected:
    bool checkDevice(QString message);
    void connectRS232(QString _interfaceName, quint32 _baudRate);
};

#endif // KEITHLEY_2XXX_H
