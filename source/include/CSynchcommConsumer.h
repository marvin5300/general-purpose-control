#ifndef CSYNCHCOMM_H
#define CSYNCHCOMM_H

#include <CLogger.h>

#include <QThread>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>
#include <QSerialPort>
#include <QTime>
#include <QSemaphore>

#define COMM_ERR_LIMIT 3

class CSynchCommConsumer : public QObject
{
    Q_OBJECT
public:
    explicit CSynchCommConsumer( QString _portName, QMutex * _ptrBlockBuffer, QSemaphore * _reserved, QSemaphore * _free, QObject *parent = nullptr);
    void setup(QThread & _thread, QList<QByteArray> * _request,  int _waitTimeOut, int _bufferLen);
    void clearCommErr(void);
    signals:
        void response(const QString &s);
        void error(const QString &s);
        void timeout(const QString &s);
        void logger(const QString &s);

    private:
        QString m_portName;
        QList<QByteArray> *  m_ptrRequest;
        int m_waitTimeout = 500;
        QMutex m_mutex;
        QWaitCondition m_cond;
        bool m_quit = false;
        bool m_isWorking = false;
        bool m_commError = false;
        int m_commErrorFailed = 0;
        QMutex * m_ptrBlockBuffer;
        QSemaphore * m_ptrReserved;
        QSemaphore * m_ptrFree;
    public:
       QString getPortName();
       void setPortName(QString _portName);
       void quit(void);
       void wakeUp();
       void setQuitBit(bool _bit);
       bool getQuitBit(void);
  signals:
       void serialPortIsConnected(bool _connected);
       void bufferSizeChanged(int _bufferSize);
public slots:
       void sendRequest(void);
};

#endif // CSYNCHCOMM_H
