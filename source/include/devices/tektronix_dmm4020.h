#ifndef TEKTRONIX_DMM4020_H
#define TEKTRONIX_DMM4020_H

#include <devices/scpidevice.h>

class Tektronix_DMM4020 : public ScpiDevice
{
    Q_OBJECT

public:
    explicit Tektronix_DMM4020(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "DMM4020";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // TEKTRONIX_DMM4020_H
