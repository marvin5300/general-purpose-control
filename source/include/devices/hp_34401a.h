#ifndef HP_34401A_H
#define HP_34401A_H

#include <devices/scpidevice.h>

class HP_34401A : public ScpiDevice
{
    Q_OBJECT

public:
    explicit HP_34401A(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "HP 34401A";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // HP_34401A_H
