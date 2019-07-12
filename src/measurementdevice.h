#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <QGroupBox>

//
class MeasurementDevice : public QGroupBox
{
    Q_OBJECT

signals:
    void scpiCommand(QString command);
    void disconnectRS232(QString portName);

public:
    explicit MeasurementDevice(QWidget *parent = 0);

public slots:
    virtual void onReceivedMessage(QString message);
    virtual void onConnectionStatusChanged(bool connected);

protected:
    void connectRS232();
    QString portName, deviceName;
    quint32 baudRate;
    QStringList ports;
    bool correctDeviceConnected = false;
};

#endif // MEASUREMENT_DEVICE_H
