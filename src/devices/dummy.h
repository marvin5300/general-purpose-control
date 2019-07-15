#ifndef DUMMY_H
#define DUMMY_H
#include "../measurementdevice.h"

class Dummy : public MeasurementDevice
{
    Q_OBJECT
public slots:
    void onReceivedMessage(QString message);

public:
    //using MeasurementDevice::MeasurementDevice;
    Dummy();
    const QString getInterfaceName();
    const QString getDeviceName();

private:
    void init();
    void connectRS232();
    const QString deviceName = "not selected";
};

#endif // DUMMY_H
