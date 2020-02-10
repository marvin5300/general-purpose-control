#ifndef VOLTCRAFT_PSP1803_H
#define VOLTCRAFT_PSP1803_H

#include <src/devices/scpidevice.h>

class Voltcraft_PSP1803 : public ScpiDevice
{
    Q_OBJECT

public:
    explicit Voltcraft_PSP1803(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = nullptr);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "PSP1803";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // VOLTCRAFT_PSP1803_H
