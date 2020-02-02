#ifndef KEITHLEY_2XXX_H
#define KEITHLEY_2XXX_H

#include "../measurementdevice.h"
#include <QDebug>
#include <QList>
#include <QQueue>

class Keithley_2xxx : public MeasurementDevice
{
public:
    using MeasurementDevice::MeasurementDevice;
public slots:
    void onReceivedMessage(QString message);
    void queueMeasure(quint64 number);
    void connectBus();
    void setScanParameter(MeasurementValue value);
protected:
    void measure();
    bool checkDevice(QString message);
    void connectRS232(QString _interfaceName, quint32 _baudRate);
    static const QMap<QString, DeviceParameterConstraint> deviceParamMap;
    QString translateMeas(QString paramName);
    QString translateSet(QString paramName);
    quint64 measureID;
    QQueue<QString> activeMeasParams;
    QList<MeasurementValue> measureResults;
};

#endif // KEITHLEY_2XXX_H
