#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"


class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public slots:
    void onReceivedMessage(QString message);

public:
    explicit Keithley_2410(QString _interfaceName);
    const QString getInterfaceName()const;
    const QString getDeviceName()const;
    const QMap<QString,DeviceParameterConstraint> getDeviceParameterConstraints()const;
    const QList<MeasurementValue> getMeasures();
    void setScanParameter(MeasurementValue value);

private:
    void init();
    void connectRS232();
    const QString deviceName = "MODULE 2410";
    static const QMap<QString, DeviceParameterConstraint> deviceParamMap;
    QMap<QString, MeasurementValue> valuesMap;
};

#endif // KEITHLEY_2410_H
