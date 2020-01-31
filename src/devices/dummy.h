#ifndef DUMMY_H
#define DUMMY_H
#include "../measurementdevice.h"

class Dummy : public MeasurementDevice
{
    Q_OBJECT
public slots:
    void onReceivedMessage(QString message);
    void queueMeasure(quint64 count)override;

public:
    //using MeasurementDevice::MeasurementDevice;
    Dummy();
    const QString getInterfaceName()const;
    const QString getDeviceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const{return QMap<QString,DeviceParameterConstraint>();}
    void setScanParameter(MeasurementValue value){}
    void connectBus();

private:
    void init();
    const QString deviceName = "not selected";
    bool checkDevice(QString message);
};

#endif // DUMMY_H
