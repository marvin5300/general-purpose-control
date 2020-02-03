#ifndef SOURCETRONIC_ST2819A_H
#define SOURCETRONIC_ST2819A_H

#include <src/devices/scpidevice.h>

class SourceTronic_ST2819A : public ScpiDevice
{
    Q_OBJECT

public:
    SourceTronic_ST2819A(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    static const QMap<QString, DeviceParameterConstraint> deviceParamMap;
    const QString getInterfaceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString deviceName() {return _deviceName;}

private:
    void init();
    const QString _deviceName = "ST2819A";
};

#endif // SOURCETRONIC_ST2819A_H
