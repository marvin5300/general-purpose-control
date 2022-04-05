#include "CSynchcommProducer.h"
#include <QDebug>

CSynchCommProducer::CSynchCommProducer(QMutex * _ptrBlockBuffer, QSemaphore * _reserved, QSemaphore * _free, QObject *parent)
    : QObject{parent}, m_ptrBlockBuffer(_ptrBlockBuffer), m_ptrReserved(_reserved), m_ptrFree(_free)
{

}

void CSynchCommProducer::setup(QThread & _thread, QList<QByteArray> * _request, int _bufferLen)
{

   // connect(&_thread, &QThread::started, this, &CSynchCommProducer::fillBuffer);
    moveToThread(&_thread);
    m_ptrRequest = _request;

}

void CSynchCommProducer::fillBuffer(void)
{
    int currentSize = m_ptrRequest->size();
    bool currentSizeHasChanged = false;

    while(!m_quit)
    {
        m_mutex.lock();
        if(currentSize != m_ptrRequest->size())
        {
            currentSize = m_ptrRequest->size();
            currentSizeHasChanged = true;
        }else{
            currentSizeHasChanged = false;
        }
        if(m_ptrRequest == nullptr)
        {
            emit error("No buffer is available");
        }
        m_mutex.unlock();

        if(m_ptrReserved->available() == 0)
        {
          emit bufferIsFilled(true);
        }

    }

}

void CSynchCommProducer::quit(void)
{
    m_quit = true;
}

void CSynchCommProducer::wakeUp()
{
    m_cond.wakeOne();
}

 void CSynchCommProducer::on_addCommand(QByteArray _command)
 {
     m_mutex.lock();
     m_commandRequested = true;
     m_command = _command + "\r";
     m_mutex.unlock();

     // if requested data has changed add item to list
     if(m_commandRequested)
     {
         m_ptrFree->acquire();               // take one coin from free semaphore
         m_ptrBlockBuffer->lock();           // mutual exclusion to buffer access
         // critical part
         m_ptrRequest->insert(0,m_command);  // write to send buffer
         emit commandAdded();
         emit bufferSizeChanged(m_ptrRequest->size());
         qDebug() << "Producer added --" +  QString(_command) + "-- to job list ";
         m_commandRequested = false;         // command written to buffer

         m_ptrBlockBuffer->unlock();         // free buffer access
         m_ptrReserved->release();           // creates one coin for reserved semaphore
     }

 }
