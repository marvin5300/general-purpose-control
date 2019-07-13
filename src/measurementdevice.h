#ifndef MEASUREMENT_DEVICE_H
#define MEASUREMENT_DEVICE_H

#include <QGroupBox>

// this class is made assuming all devices use rs232 serial connection on scpi message base

class MeasurementDevice : public QGroupBox
{
    Q_OBJECT

signals:
    void scpiCommand(QString command);
    void disconnectRS232(QString portName);
    void closeConnection();

public:
    explicit MeasurementDevice(QString _portName, quint32 _baudRate = 9600, QWidget *parent = 0);
    const QString deviceName;

public slots:
    virtual void onReceivedMessage(QString message);
    virtual void onConnectionStatusChanged(bool connected);
    void setPort(QString _portName);
    void exit();

protected:
    void connectRS232();
    QString portName;
    quint32 baudRate;
    bool correctDeviceConnected = false;
};

#endif // MEASUREMENT_DEVICE_H
