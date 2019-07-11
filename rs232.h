#ifndef RS232_H
#define RS232_H

#include <QObject>
#include <QSerialPort>
#include <string>
#include <QPointer>

/* supported baudrates:
 * 57600
 * 38400
 * 19200
 *  9600
 *  4800
 *  2400
 *  1200
 *   600
 *   300
 */

class RS232 : public QObject
{
    Q_OBJECT
public:
    explicit RS232(QString _portName, quint32 _baudRate, QString _deviceName, QObject *parent = nullptr);

signals:
    void serialRestart(QString _portName, quint32 _baudRate);
    void receivedMessage(QString message);
    void connectionStatus(bool connected, QString _portName);

public slots:
    void onReadyRead();
    void makeConnection();
    void sendScpiCommand(QString command);
    void closeConnection(QString _portName);

private slots:
    bool scanMessage(std::string& buffer);

private:
    QPointer<QSerialPort> serialPort;
    void closeSerialPort();
    QString portName;
    QString deviceName;
    std::string buffer = "";
    quint32 baudRate = 9600;
    unsigned int timeout = 5000; // ms
    char terminator = 0x0a; // <LF> "linefeed" in ascii
    bool correctDeviceConnected = false;
    void processMessage(std::string& message);
};

#endif // RS232_H
