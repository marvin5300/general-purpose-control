#ifndef HAMEG_HM8143_H
#define HAMEG_HM8143_H

#include <src/devices/scpidevice.h>

class Hameg_HM8143 : public ScpiDevice
{
    Q_OBJECT
public:
    explicit Hameg_HM8143(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "Hameg HM8143";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // HAMEG_HM8143_H
