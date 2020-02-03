#ifndef DUMMY_H
#define DUMMY_H

#include <src/devices/scpidevice.h>

class Dummy : public MeasurementDevice
{
    Q_OBJECT
public slots:
    void onReceivedMessage(QString message);
    void queueMeasure(quint64 count)override;

public:
    Dummy();
    const QString getInterfaceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const{return QMap<QString,DeviceParameterConstraint>();}
    void setScanParameter(MeasurementValue value){value = value;}
    void connectBus(){}
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "not selected";
};

#endif // DUMMY_H
