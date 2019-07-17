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
    const QString getInterfaceName()const;
    const QString getDeviceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const{return QMap<QString,DeviceParameterConstraint>();}

private:
    void init();
    void connectRS232();
    const QString deviceName = "not selected";
};

#endif // DUMMY_H
