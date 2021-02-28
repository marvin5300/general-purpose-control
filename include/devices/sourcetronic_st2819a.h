#ifndef SOURCETRONIC_ST2819A_H
#define SOURCETRONIC_ST2819A_H

#include "devices/scpidevice.h"

class SourceTronic_ST2819A : public ScpiDevice
{
    Q_OBJECT

public:
    explicit SourceTronic_ST2819A(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString getInterfaceName()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "ST2819A";
    static const QMap<QString, DeviceParameterConstraint> _deviceParamMap;
    QMap<QString, DeviceParameterConstraint> deviceParamMap(){return _deviceParamMap;}
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // SOURCETRONIC_ST2819A_H
