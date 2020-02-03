#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include <src/devices/scpidevice.h>


class Keithley_2410 : public ScpiDevice
{
    Q_OBJECT

public:
    Keithley_2410(QString _interfaceName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QString getInterfaceName()const;
    const QString getDeviceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QString deviceName() {return _deviceName;}

public slots:
    //void onReceivedMessage(QString message);
    //void queueMeasure(quint64 count);

private:
    void init();
    const QString _deviceName = "MODEL 2410";
    static const QMap<QString, DeviceParameterConstraint> deviceParamMap;
    QMap<QString, MeasurementValue> valuesMap;
    //using Keithley_2xxx::checkDevice;
};

#endif // KEITHLEY_2410_H
