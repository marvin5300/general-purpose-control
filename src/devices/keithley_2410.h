#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"


class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public:
    explicit Keithley_2410(QString _interfaceName);
    const QString getInterfaceName()const;
    const QString getDeviceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QList<MeasurementValue> getMeasures();
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
