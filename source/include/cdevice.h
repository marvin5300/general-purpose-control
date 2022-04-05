#ifndef CDEVICE_H
#define CDEVICE_H

#include <CLogger.h>
#include <EnumHelper.h>
#include <CPosition.h>
#include <CSynchcommConsumer.h>
#include <CSynchcommProducer.h>
#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QApplication>
#include <QString>
#include <QTableWidget>
#include <QTimer>




// defines -----------------
#define COLUMNS 3

//
#define PORT_NAME 0
#define VENDOR_ID 1
#define PRODUCT_ID 2

// timer
#define READ_TIMEOUT 500 // in ms

// synch comm
#define SYNCHBUFFER_LEN 9


class CDevice : public QObject
{
    Q_OBJECT
protected:
    // communication
    QString m_deviceName;
    QSerialPort m_serialPort;
    QString (*m_availableDevices)[COLUMNS] = {}; // Port name, Vendor ID, Product ID
    int m_availablePorts = 0;
    QByteArray m_asynchReadBuffer;
    bool m_readDone = false;
    QTimer m_readTimeOut;
    // synch comm
    CSynchCommConsumer m_synchCommConsumer;
    CSynchCommProducer m_synchCommProducer;
    QList<QByteArray> m_synchSendBuffer;        // impelemt as QQueue Class
    QList<QByteArray> m_synchReadBuffer;        // implement as Queue Class
    QMutex m_blockBuffer;
    QSemaphore m_reserved;
    QSemaphore m_free;
    //logger
    QString m_loggerFileName = QCoreApplication::applicationDirPath() + "/Logger.txt";
    CLogger m_logger;

    // visualisation
    QPlainTextEdit * m_responseDisplay = nullptr;

public:

    CDevice();
    CDevice(QString _deviceName, QSerialPort::BaudRate _baudRate, QSerialPort::Parity _parity, QSerialPort::DataBits _dataBits,
            QSerialPort::StopBits _stopBits, QSerialPort::FlowControl _flowControl);
    ~CDevice();
    //general
    void initConnections(void);
    void setDeviceName(QString _deviceName);
    void setDisplayLogger(QPlainTextEdit * _logger);
    QSerialPort * getSerialPort(void);
    void setSelectedDevice(QTableWidget * _tableWidget);
    QString getSelectedDevicePort(QTableWidget * _tableWidget);
    QString getDeviceName(void);
    const CSynchCommConsumer * const getSynchCommConsumer(void);
    void quitConsumer(void);
    void wakeUpConsumer(void);

    const CSynchCommProducer * const getSynchCommProducer(void);
    void quitProducer(void);
    void wakeUpProducer(void);
    void connectDeviceToThread(QThread * _consumer, QThread * _producer);
    int getSynchBufferSize(void);
    // communication
    unsigned int searchForDevice(void);
    unsigned int connectDevice(QString _portName, QSerialPort::BaudRate _baudRate,
                                              QSerialPort::Parity _parity, QSerialPort::DataBits _dataBits, QSerialPort::StopBits _stopBits
                                              , QSerialPort::FlowControl _flowControl);
    unsigned int sendString(QPlainTextEdit * _msgToSend);
    unsigned int disconnectDevice(void);
    // synch comm

    // visualisation
    void setResponseDisplay(QPlainTextEdit * _responseDisp);
    void displayFoundDevices(QTableWidget * _tableWidget);
    void displayReadData(void);

signals:
    void error(QString _windowTitle, QString _windowText);
    void warning(QString _windowTitle, QString _windowText);
    void information(QString _windowTitle, QString _windowText);
    void dataToDisplay(QByteArray _data);
    void connected(bool connected);
    void displayResponse(QString readData);
    void bufferSizeChanged(int _bufferSize);
    void stopStateMachine();
private slots:

public slots:
    virtual unsigned int readData(void);
    virtual unsigned int readDone(void);
    // synch comm
    unsigned int on_synchResponse(QString response);
    void on_synchError(const QString &s);
    void on_synchTimeout(const QString &s);
    void on_threadStarted(void);


};

#endif // CDEVICE_H
