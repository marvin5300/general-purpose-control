#ifndef SERIAL_H
#define SERIAL_H

#include <QObject>
#include <QSerialPort>
#include <string>
#include <QPointer>

/**
* Serial interface (UART) class that uses QSerialPort.
* This class only knows basic serial communication. 
*/
class Serial : public QObject
{
    Q_OBJECT
public:
    explicit Serial(QString _portName, quint32 _baudRate = 9600,
                   char _terminator = 0x0a,
                   QSerialPort::FlowControl _flowControl = QSerialPort::NoFlowControl,
                   QSerialPort::StopBits _stopBits = QSerialPort::OneStop,
                   QSerialPort::DataBits _dataBits = QSerialPort::Data8,
                   QSerialPort::Parity _parity = QSerialPort::NoParity,
                   QObject *parent = nullptr);

signals:
    /**
    * @brief Signal that contains a full message from the device.
    * Emitted after message parsed from buffer.
    * Must be connected outside of this class.
    */
    void receivedMessage(QString message);

    /**
    * @brief Sends information about connection state e.g. if not connected after timeout.
    * Usually uart connections do not give information about connected state. 
    * However, this will emit disconnected if wrong permissions or wrong portname.
    */
    void connectionStatus(bool connected);

public slots:
    /**
    * @brief This function gets called when the serial port emits readyRead signal
    * Must be connected to QSerialPort which happens in makeConnection().
    */
    void onReadyRead();

    /**
    * @brief This function gets called with a signal from client-thread
    * Creates a new QSerialPort and connects the signals for read/write.
    */
    void makeConnection();

    /**
    * @brief Sends a QString via open serial port.
    * This slot has to be connected outside of this class.
    * It will append a 'terminator' char at the end of each sent message. (LF : linefeed per default).
    * Terminator char can be selected in the constructor of serial.
    */
    void sendScpiCommand(QString command);

    /**
    * @brief Calls closeSerialPort(). Then deletes Serial object (this).
    */
    void closeConnection();

private:
    /**
    * @brief Reads the buffer and returns true if a complete message is found.
    * If so: removes it from the buffer and starts the processing of this message.
    * Determines complete message by waiting for terminator char.
    * This function should be reevaluated for different terminator chars for sending and receiving.
    */
    bool scanMessage(std::string& buffer);

    QPointer<QSerialPort> serialPort;

    /**
    * @bbrief Closes connection and deletes QSerialPort object. 
    */
    void closeSerialPort();
    QString portName;
    std::string buffer = "";

    /**
    * Default is 9600 baud
    */
    quint32 baudRate; // usually 9600

    /**
    * Default is LF (0x0a)
    */
    char terminator; // usually <LF> "linefeed" in ascii

    /**
    * Default is no flow control
    */
    QSerialPort::FlowControl flowControl; // usually NoFlowControl
    
    /**
    * Default is 1 stop bit.
    */
    QSerialPort::StopBits stopBits; // usually OneStop

    /**
    * Default is 8 bits.
    */
    QSerialPort::DataBits dataBits; // usually Data8 (8 Bits)

    /**
    * Default is no parity
    */
    QSerialPort::Parity parity; // usually NoParity

    /**
    * timeout in seconnds
    */
    unsigned int timeout = 5000; // s
};

#endif // SERIAL_H
