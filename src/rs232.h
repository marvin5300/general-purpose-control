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
    explicit RS232(QString _portName, quint32 _baudRate = 9600,
                   char _terminator = 0x0a,
                   QSerialPort::FlowControl _flowControl = QSerialPort::NoFlowControl,
                   QSerialPort::StopBits _stopBits = QSerialPort::OneStop,
                   QSerialPort::DataBits _dataBits = QSerialPort::Data8,
                   QSerialPort::Parity _parity = QSerialPort::NoParity,
                   QObject *parent = nullptr);

signals:
    void receivedMessage(QString message);
    void connectionStatus(bool connected);

public slots:
    void onReadyRead();
    void makeConnection();
    void sendScpiCommand(QString command);
    void closeConnection();

private slots:
    bool scanMessage(std::string& buffer);

private:
    QPointer<QSerialPort> serialPort;
    void closeSerialPort();
    QString portName;
    std::string buffer = "";
    quint32 baudRate; // usually 9600
    char terminator; // usually <LF> "linefeed" in ascii
    QSerialPort::FlowControl flowControl; // usually NoFlowControl
    QSerialPort::StopBits stopBits; // usually OneStop
    QSerialPort::DataBits dataBits; // usually Data8 (8 Bits)
    QSerialPort::Parity parity; // usually NoParity
    unsigned int timeout = 5000; // ms
    void processMessage(std::string& message);
};

#endif // RS232_H
