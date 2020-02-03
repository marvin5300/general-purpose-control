#ifndef SCPIDEVICE_H_H
#define SCPIDEVICE_H_H

#include <src/measurementdevice.h>
#include <QDebug>
#include <QList>
#include <QQueue>

// all devices that use the scpi protocol (commands look like ':TRIGer:SOURce EXTernal')

class ScpiDevice : public MeasurementDevice
{
    Q_OBJECT
signals:
    void scpiCommand(QString command);
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

#endif // SCPIDEVICE_H_H
