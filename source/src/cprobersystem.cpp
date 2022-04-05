#include <cprobersystem.h>


CProberSystem::CProberSystem(void)
    : CDevice()
{
    m_cycReadPos.setSingleShot(false);
    m_cycReadPos.setInterval(m_interval);

    initProberConnections();

}

CProberSystem::CProberSystem(QString _deviceName, QPlainTextEdit * _readDataDisp, QWidget * _loggerDisp)
    :CDevice()
{
    //m_ptrProberLogger = new CLogger(this, m_loggerFileName, _loggerDisp);
    m_deviceName = _deviceName;
    qDebug() << "ProberLogger Path: " << m_loggerFileName;
    m_responseDisplay = _readDataDisp;
    m_cycReadPos.setSingleShot(false);
    m_cycReadPos.setInterval(m_interval);

   initProberConnections();

}

CProberSystem::CProberSystem(QString _deviceName, QSerialPort::BaudRate _baudRate, QSerialPort::Parity _parity, QSerialPort::DataBits _dataBits,
                             QSerialPort::StopBits _stopBits, QSerialPort::FlowControl _flowControl, QPlainTextEdit * _readDataDisp, QPlainTextEdit *_loggerDisp)
    :CDevice()
{
    m_deviceName = _deviceName;
    qDebug() << "ProberLogger Path: " << m_loggerFileName;
    m_serialPort.setBaudRate(_baudRate);
    m_serialPort.setParity(_parity);
    m_serialPort.setDataBits(_dataBits);
    m_serialPort.setStopBits(_stopBits);
    m_serialPort.setFlowControl(_flowControl);

    m_responseDisplay = _readDataDisp;
    m_cycReadPos.setSingleShot(false);
    m_cycReadPos.setInterval(m_interval);

    initProberConnections();

}


CProberSystem::~CProberSystem(void)
{
    // free dynamic created QString array in searchDevice method
    //delete m_foundDevices;


    // close serial port
    if(m_serialPort.isOpen())
    {
        m_serialPort.close();
    }

}

void CProberSystem::initProberConnections(void)
{
    // m_serial >> this
    connect(&m_serialPort, &QSerialPort::readyRead, this, &CProberSystem::readData);
    // m_synchCommConsumer << this
    connect(this, &CProberSystem::addCommand,&m_synchCommProducer,&CSynchCommProducer::on_addCommand);
    // m_synchCommConsumer >> this
    connect(&m_synchCommConsumer, &CSynchCommConsumer::response, this, &CProberSystem::on_response);
    // m_cycReadPos >> this
    connect(&m_cycReadPos, &QTimer::timeout, this, &CProberSystem::on_timeoutCycReadPos);
}

CPosition   CProberSystem::getActPosition(void)
 {
     return m_actPosition;
 }

void CProberSystem::setReadPosInterval(unsigned int _interval)
{
    m_interval = _interval;
    m_cycReadPos.setInterval(m_interval);
}

// SLOTS -----------------------------------------------------
unsigned int CProberSystem::on_asynchReadChuckPosition(CPosition * _readPosition)
{
    int writtenBytes = 0;
    QByteArray command = "ReadChuckPosition";
    m_asynchReadBuffer.clear();
    m_readDone = false;
    QByteArray reply;
    if(m_serialPort.isOpen())
    {
        if(m_serialPort.isWritable())
        {
            // synchronous write command
            writtenBytes = m_serialPort.write(command);
            // wait for data written
            while(m_serialPort.waitForBytesWritten(2000))
                ;
            // check if write cmd was ok
            if(writtenBytes > 0)
            {
               m_logger.write("sent: " + command);
               qDebug() << writtenBytes << " bytes were sent";
               //write message to logger
               m_logger.write("reply: " + m_asynchReadBuffer);

               qDebug() << "data recived";
               return 0;
            }else{
                m_logger.write("write error while ReadChuckPosition command");
                qDebug() << "write error";
                return 1;
            }
        }else{
            m_logger.write(" Port is not writeable");
            qDebug() << "Port is not writeable";
            return 2;
        }
    }
    return 3;
}

void CProberSystem::startCyclPosRead(void)
{
    m_cycReadPos.start();
}

void CProberSystem::stopCycPosRead(void)
{
    m_cycReadPos.stop();
}

bool CProberSystem::isCycPosReadActive(void)
{
    return m_cycReadPos.isActive();
}

unsigned int CProberSystem::on_synchReadChuckPos(const QString _readChuckPos)
{
    if(_readChuckPos == "ReadChuckPosition")
    {
        emit addCommand(_readChuckPos.toUtf8());
        return NO_ERROR;
    }else{
        return INPUTERROR_READPOS;
    }
}

unsigned int CProberSystem::on_requestMoveChuckXY(double _xPos, double _yPos, QString _posRef, QString _unit, QString _velocity)
{
    int writtenBytes = 0;
    QByteArray command = 0;
    QString strCommand;
    QByteArray reply;
    unsigned char invalidParameter;

    // input check of parameters
    // check if posRef Valid
    if(_posRef == "H"             // abs from home
            || _posRef == "Z"       // abs from zero
            || _posRef == "C"       // abs from center
            || _posRef == "R")      // rel from current
    {
        ;
    }else{
        return INPUTERROR_POSREF;
    }

    // check if unit valid
    if(_unit == "Y"
            || _unit == "I"
            || _unit == "E")
    {
        ;
    }else{
        return INPUTERROR_UNIT;
    }

    // check if velocity valid
    for(QString::const_iterator i = _velocity.begin(); i < _velocity.end(); i++)
    {
       if(!i->isDigit())
           return INPUTERROR_VELOCITY;
    }
    // check if velocity is in range
    if(_velocity.toInt() < 1
            || _velocity.toInt() > 100)
        return INPUTERROR_VELOCITY;

    m_setPosition.setXpos(_xPos);
    m_setPosition.setYpos(_yPos);
    m_inXYPosition = false;
    emit notInXYPosition();
    // send if no input error
     strCommand = "MoveChuck " + QString::number(_xPos) + " " + QString::number(_yPos)
                + " " + _posRef.toUpper() + " " + _unit.toUpper() + " " + _velocity;
        command = strCommand.toUtf8();
        emit addCommand(command);
        return NO_ERROR;
}

unsigned int CProberSystem::on_requestMoveChuckZ(double _zPos, QString _posRef, QString _unit, QString _velocity)
{
    int writtenBytes = 0;
    QByteArray command = 0;
    QString strCommand;
    QByteArray reply;
    unsigned char invalidParameter;

    // input check of parameters
    // check if posRef Valid
    if(_posRef == "H"             // abs from home
            || _posRef == "Z"       // abs from zero
            || _posRef == "C"       // abs from center
            || _posRef == "R")      // rel from current
    {
        ;
    }else{
        return INPUTERROR_POSREF;
    }

    // check if unit valid
    if(_unit == "Y"
            || _unit == "I"
            || _unit == "E")
    {
        ;
    }else{
        return INPUTERROR_UNIT;
    }

    // check if velocity valid
    for(QString::const_iterator i = _velocity.begin(); i < _velocity.end(); i++)
    {
       if(!i->isDigit())
           return INPUTERROR_VELOCITY;
    }
    // check if velocity is in range
    if(_velocity.toInt() < 1
            || _velocity.toInt() > 100)
        return INPUTERROR_VELOCITY;

    m_setPosition.setZpos(_zPos);
    m_inZPosition = false;
    emit notInZPosition();
    // send if no input error
     strCommand = "MoveChuckZ " + QString::number(_zPos) + " " + _posRef.toUpper() + " " + _unit.toUpper() + " " + _velocity;
        command = strCommand.toUtf8();
        emit addCommand(command);
        return NO_ERROR;
}

unsigned int CProberSystem::on_response(const QString &_response)
{
    unsigned int conversion = 0;
    //check if response is a position
    conversion = CPosition::qStringToPosition(_response,&m_actPosition);
    if(!conversion)
    {
        if((qAbs(m_setPosition.getZpos() - m_actPosition.getZpos()) < EPSYLON)
                && !m_inZPosition )
        {
            m_inZPosition = true;
            emit inZPosition();
            qDebug() << "in Z Position emitted";
        }

        if((qAbs(m_setPosition.getXpos() - m_actPosition.getXpos()) < EPSYLON)
            && (qAbs(m_setPosition.getYpos() - m_actPosition.getYpos()) < EPSYLON)
                && !m_inXYPosition )
        {
            m_inXYPosition = true;
            emit inXYPosition();
            qDebug() << "in XY position emitted";
        }
        emit actPosition(m_actPosition); // send updated act position
        qDebug() << "position coversion succeed";
        return 0; // conversion succeed
     }
    qDebug() << "position conversion failed";
    return 1; // conversion failed --> no position data
}

void CProberSystem::on_timeoutCycReadPos(void)
{
    emit addCommand(QByteArray("ReadChuckPosition"));
}

void CProberSystem::on_requestInPosition(void)
{
    if((qAbs(m_setPosition.getZpos() - m_actPosition.getZpos()) < EPSYLON))
    {
        m_inZPosition = true;
        emit inZPosition();
    }
    if((qAbs(m_setPosition.getXpos() - m_actPosition.getXpos()) < EPSYLON)
        && (qAbs(m_setPosition.getYpos() - m_actPosition.getYpos()) < EPSYLON))
    {
        m_inXYPosition = true;
        emit inXYPosition();
    }
}

// visualisation

void CProberSystem::displayActPosition(CPositionVisuXYZ * _actPosition)
{
    _actPosition->getTextEditX()->setText(QString::number(this->m_actPosition.getXpos()));
    _actPosition->getTextEditY()->setText(QString::number(this->m_actPosition.getYpos()));
    _actPosition->getTextEditZ()->setText(QString::number(this->m_actPosition.getZpos()));


}

