#ifndef CSYNCHCOMMPRODUCER_H
#define CSYNCHCOMMPRODUCER_H

#include <QObject>
#include <QThread>
#include <QWaitCondition>
#include <QMutex>
#include <QSemaphore>

class CSynchCommProducer : public QObject
{
    Q_OBJECT
private:
    QList<QByteArray> *  m_ptrRequest;
    QWaitCondition m_cond;
    bool m_quit = false;
    bool m_commandRequested = false;
    bool m_blocked = false;
    QByteArray m_command;
    QMutex m_mutex;
    QMutex * m_ptrBlockBuffer;
    QSemaphore * m_ptrReserved;
    QSemaphore * m_ptrFree;
public:
    explicit CSynchCommProducer(QMutex * _ptrBlockBuffer, QSemaphore * _reserved, QSemaphore * _free, QObject *parent = nullptr);
    void setup(QThread & _thread, QList<QByteArray> * _request, int _bufferLen);
    void quit(void);
    void wakeUp();
signals:
    void error(const QString &s);
    void bufferIsFilled(bool _bufferIsFilled);
    void bufferSizeChanged(int _bufferSize);
    void commandAdded(void);
public slots:
    void fillBuffer(void);
    void on_addCommand(QByteArray _command);

};

#endif // CSYNCHCOMMPRODUCER_H
