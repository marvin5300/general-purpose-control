#include "CSynchcommConsumer.h"
#include "cdevice.h"
#include <QDebug>

CSynchCommConsumer::CSynchCommConsumer(QString _portName, QMutex * _ptrBlockBuffer, QSemaphore * _reserved, QSemaphore * _free, QObject * parent )
    : m_portName(_portName), m_ptrBlockBuffer(_ptrBlockBuffer), m_ptrReserved(_reserved), m_ptrFree(_free)
{

}


void CSynchCommConsumer::setup(QThread & thread, QList<QByteArray> * _request, int _waitTimeOut, int bufferLen)
{
    moveToThread(&thread);
    m_ptrRequest = _request;
    m_waitTimeout = _waitTimeOut;
}

QString CSynchCommConsumer::getPortName(void)
{
    return m_portName;
}

void CSynchCommConsumer::setPortName(QString _portName)
{
    m_portName = _portName;
}

 void CSynchCommConsumer::quit(void)
 {
     m_quit = true;
 }

void CSynchCommConsumer::sendRequest(void)
{
    QSerialPort m_serialPort;

    bool currentPortNameChanged = false;
    QString currentRequest = "";


    m_mutex.lock();
    QString currentPortName;
    if (currentPortName != m_portName) {
        currentPortName = m_portName;
        currentPortNameChanged = true;
    }

    if (currentPortNameChanged) {
                m_serialPort.close();
                m_serialPort.setPortName(currentPortName);

                if (!m_serialPort.open(QIODevice::ReadWrite)) {
                    emit error(tr("Can't open %1, error code %2")
                               .arg(m_portName).arg(m_serialPort.error()));
                    return;
                  }else{
                    emit serialPortIsConnected(true);
                }
    }
    int currentWaitTimeout = m_waitTimeout;
    m_mutex.unlock();


    m_ptrReserved->acquire();                   // get a resevred semaphore coin
    m_ptrBlockBuffer->lock();                   // lock buffer acces
    if(!m_ptrRequest->isEmpty())
    {
        currentRequest = m_ptrRequest->takeLast();  // take last to send
        if(m_ptrRequest->size() > 2)
        {
                m_ptrRequest->removeAt(m_ptrRequest->size()-1);        // remove last item from list
                emit bufferSizeChanged(m_ptrRequest->size());
        }
        qDebug() << "Consumer sent --" + currentRequest + "-- command";

    }
    m_ptrBlockBuffer->unlock();                 // unlock buffer access
    m_ptrFree->release();                       // release free coin


    if(!currentRequest.isEmpty()){
        // write request
        const QByteArray requestData = currentRequest.toUtf8();
        m_serialPort.write(requestData);
        if (m_serialPort.waitForBytesWritten(m_waitTimeout)) {
            emit logger("data sent: " + currentRequest);
        }else {
            if(!m_commError && m_commErrorFailed >= COMM_ERR_LIMIT)
            {
                emit timeout(tr("Wait write request timeout %1")
                             .arg(QTime::currentTime().toString()));
                m_commError = true;
            }else if(!m_commError && m_commErrorFailed < COMM_ERR_LIMIT){
                m_commErrorFailed++;
            }

            emit logger("error: " + tr("Wait write request timeout %1")
                        .arg(QTime::currentTime().toString()));
        }

        // read response
        if (m_serialPort.waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = m_serialPort.readAll();
            while (m_serialPort.waitForReadyRead(10))
                responseData += m_serialPort.readAll();
            const QString response = QString::fromUtf8(responseData);
            emit this->response(response);
            emit logger("data recived: " + response);
            m_commError = false;
        } else {
           //if(!m_commError)
           //{
           //    emit timeout(tr("Wait read response timeout %1")
           //                 .arg(QTime::currentTime().toString()));
           //    m_commError = true;
           //}

            emit logger("error: " + tr("Wait read response timeout %1")
                        .arg(QTime::currentTime().toString()));
        }
    }
}

void CSynchCommConsumer::wakeUp()
{
    m_mutex.lock();
    m_cond.wakeOne();
    m_mutex.unlock();
}

void CSynchCommConsumer::setQuitBit(bool _bit)
{
    m_quit = _bit;
}

bool CSynchCommConsumer::getQuitBit(void)
{
    return m_quit;
}

void CSynchCommConsumer::clearCommErr(void)
{
  m_commErrorFailed = 0;
  m_commError = false;
}
