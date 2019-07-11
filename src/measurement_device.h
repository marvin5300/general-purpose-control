#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <QGroupBox>

class Measurement_Device : public QGroupBox
{
    Q_OBJECT

signals:
    void scpiCommand(QString command);
    void disconnectRS232(QString portName);

public:
    explicit Measurement_Device(QWidget *parent = 0);

public slots:
    void onReceivedMessage(QString message);
    void onConnectionStatusChanged(bool connected);

protected:
    void connectRS232();
    void init();
    QString portName, deviceName;
    quint32 baudRate;
    QStringList ports;
    bool correctDeviceConnected = false;
};

#endif // MEASUREMENT_DEVICE_H
