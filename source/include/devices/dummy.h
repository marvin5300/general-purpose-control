#ifndef DUMMY_H
#define DUMMY_H

#include "devices/scpidevice.h"

/**
* @brief Placeholder for other devices.
* Like other MeasurementDevice objects it has a device name.
* It states "not selected".
*/
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
    const QString deviceName() {return _deviceName;}
    void connectBus() override{}

private:
    void init();
    const QString _deviceName = "not selected";
};

#endif // DUMMY_H
