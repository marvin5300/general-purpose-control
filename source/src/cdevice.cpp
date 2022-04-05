#include <cdevice.h>


CDevice::CDevice()
    :m_logger(this, "LoggerProberComm"), m_serialPort(this), m_synchCommConsumer("",  &m_blockBuffer, &m_reserved, &m_free, this),
      m_synchCommProducer(&m_blockBuffer, &m_reserved, &m_free, this), m_reserved(0), m_free(SYNCHBUFFER_LEN)
{
    m_readTimeOut.setSingleShot(true);
    initConnections();
}

CDevice::CDevice(QString _deviceName, QSerialPort::BaudRate _baudRate, QSerialPort::Parity _parity, QSerialPort::DataBits _dataBits,
                 QSerialPort::StopBits _stopBits, QSerialPort::FlowControl _flowControl)
    :m_logger(this,m_loggerFileName), m_serialPort(this), m_synchCommConsumer("",  &m_blockBuffer, &m_reserved, &m_free,this),
      m_synchCommProducer(&m_blockBuffer, &m_reserved, &m_free, this), m_reserved(0), m_free(SYNCHBUFFER_LEN)
{
    m_deviceName = _deviceName;
     m_readTimeOut.setSingleShot(true);
    m_loggerFileName = QCoreApplication::applicationDirPath() + "/LOGGER_" + m_deviceName;
    m_serialPort.setBaudRate(_baudRate);
    m_serialPort.setParity(_parity);
    m_serialPort.setDataBits(_dataBits);
    m_serialPort.setStopBits(_stopBits);
    m_serialPort.setFlowControl(_flowControl);
    initConnections();
}

CDevice::~CDevice()
{

}

void CDevice::initConnections(void)
{
    // connect signals and slots
    // m_synchyomm >> m_logger
    connect(&m_synchCommConsumer, &CSynchCommConsumer::logger, &m_logger, &CLogger::write);
    connect(&m_synchCommConsumer, &CSynchCommConsumer::response, this, &CDevice::on_synchResponse);
    connect(&m_synchCommConsumer, &CSynchCommConsumer::error, this, &CDevice::on_synchError);
    connect(&m_synchCommConsumer, &CSynchCommConsumer::timeout, this, &CDevice::on_synchTimeout);
    connect(&m_readTimeOut, &QTimer::timeout, this, &CDevice::readDone);
    connect(&m_synchCommProducer, &CSynchCommProducer::commandAdded, &m_synchCommConsumer, &CSynchCommConsumer::sendRequest);
    connect(&m_synchCommConsumer, &CSynchCommConsumer::serialPortIsConnected,this,&CDevice::connected);
    connect(&m_synchCommConsumer, &CSynchCommConsumer::bufferSizeChanged,this,&CDevice::bufferSizeChanged);
    connect(&m_synchCommProducer, &CSynchCommProducer::bufferSizeChanged,this,&CDevice::bufferSizeChanged);
}
QSerialPort * CDevice::getSerialPort(void)
{
    return &m_serialPort;
}

QString CDevice::getDeviceName(void)
{
    return m_deviceName;
}


void CDevice::setDeviceName(QString _deviceName)
{
    m_deviceName = _deviceName;
}

void CDevice::setSelectedDevice(QTableWidget * _tableWidget)
{
    QList<QTableWidgetSelectionRange> selectedDevice;
    int row = 0;
    QTableWidgetItem *item;
    selectedDevice = _tableWidget->selectedRanges();
    row = selectedDevice.begin()->topRow();
    // read port name
    item = _tableWidget->item(row,PORT_NAME);
    m_serialPort.setPortName(item->text());
    m_synchCommConsumer.setPortName(item->text());
    qDebug() << "selected Portname: " << m_serialPort.portName();

}

QString  CDevice::getSelectedDevicePort(QTableWidget * _tableWidget)
{
    QList<QTableWidgetSelectionRange> selectedDevice;
    QTableWidgetItem *item;
    QString * devicePort = new QString("");
    int row = 0;

    selectedDevice = _tableWidget->selectedRanges();
    if(!selectedDevice.isEmpty())
    {
        row = selectedDevice.begin()->topRow();
        item = _tableWidget->item(row,PORT_NAME);
        *devicePort = item->text();
    }

    return *devicePort;
}

int CDevice::getSynchBufferSize(void)
{
    return m_synchSendBuffer.size();
}

// synch communication --------------------------------------------------------------
void CDevice::connectDeviceToThread(QThread * _consumer, QThread * _producer)
{
    m_synchCommConsumer.setup(*_consumer, &m_synchSendBuffer, 5000, SYNCHBUFFER_LEN);
    m_synchCommProducer.setup(*_producer, &m_synchSendBuffer, SYNCHBUFFER_LEN);
}

const CSynchCommConsumer * const CDevice::getSynchCommConsumer(void){
    return &m_synchCommConsumer;
}

void CDevice::quitConsumer(void)
{
    m_synchCommConsumer.quit();
}

void CDevice::wakeUpConsumer(void)
{
    m_synchCommConsumer.wakeUp();
}

const CSynchCommProducer * const CDevice::getSynchCommProducer(void)
{
    return &m_synchCommProducer;
}

void CDevice::quitProducer(void)
{
    m_synchCommProducer.quit();
}
void CDevice::wakeUpProducer(void)
{
    m_synchCommProducer.wakeUp();
}

// communication --------------------------------------------------------------------------------------

unsigned int CDevice::searchForDevice(void)
{
    // search for port
    m_availablePorts = QSerialPortInfo::availablePorts().length();
    qDebug() << "Number of available ports: " << m_availablePorts;
    this->m_logger.write("Number of available ports: " + QString::number(m_availablePorts));
    m_availableDevices = new QString[m_availablePorts][COLUMNS];

    // check if ports was found
    if(m_availablePorts>0){
        // read device name, vendor ID and product ID for every found device
        int i = 0;
        foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
        {
            for(int j = 0; j< COLUMNS;j++){
                switch(j) {
                    case 0: // set device name
                        m_availableDevices[i][j] = serialPortInfo.portName();
                        qDebug() << "Nr." << i << " Port name: " << m_availableDevices[i][j];
                        break;
                    case 1: // set vendor ID
                        m_availableDevices[i][j] = QString::number(serialPortInfo.vendorIdentifier());
                        qDebug() << "Nr." << i << " Vendor ID: " << m_availableDevices[i][j];
                        break;
                    case 2: // set product ID
                        m_availableDevices[i][j] = QString::number(serialPortInfo.productIdentifier());
                        qDebug() << "Nr." << i << " Product ID: " << m_availableDevices[i][j];

                        break;
                }
            }
            i++;
        }

        return 0; // devices were found
    }else{
        emit warning("Warning", "No devices found!");
        m_logger.write("No devices were found");
        return 1;
    }
}

unsigned int CDevice::connectDevice(QString _portName, QSerialPort::BaudRate _baudRate,
                                          QSerialPort::Parity _parity, QSerialPort::DataBits _dataBits, QSerialPort::StopBits _stopBits
                                          , QSerialPort::FlowControl _flowControl)
{
    // close port if it is opened
    if(m_serialPort.isOpen())
        m_serialPort.close();

    if(!_portName.isEmpty() && !m_serialPort.isOpen()){
        //open and configure the port
        m_serialPort.setPortName(_portName);
        m_synchCommConsumer.setPortName(_portName);


        // first open the port, then configure
        if(m_serialPort.open(QSerialPort::ReadWrite))
        {
            // congifuration - has to fit to the partner
            // Baud rate
            m_serialPort.setBaudRate(_baudRate);
            qDebug() << "Set baudrate" << m_serialPort.baudRate();
            // Parity
            m_serialPort.setParity(_parity);
            qDebug() << "Set parity" <<  m_serialPort.parity();
            // Data bits
            m_serialPort.setDataBits(_dataBits);
            //ptrSerialPort->setDataBits(QSerialPort::Data8);
            qDebug() << "Set data bits" << m_serialPort.dataBits();
            // Stop bits
            m_serialPort.setStopBits(_stopBits);
            qDebug() << "Set stop bits" << m_serialPort.stopBits();
            // Flow Control
            m_serialPort.setFlowControl(_flowControl);
            qDebug() << "Set stop bits" << m_serialPort.flowControl();

            emit information("Information", "Connected to " + m_serialPort.portName());
            m_logger.write("Connected to " + m_serialPort.portName());
            connect(&m_serialPort, &QSerialPort::readyRead, this, &CDevice::readData);
            emit connected(true);
            return 0; // connected, no errors
        }else{

            // give a warning if not available
            emit warning("Warning", "Error while open serial port: " + EnumHelper::toString(m_serialPort.error()));
            return 1; // could not connected
        }
    }else{
        emit information("Information", "Port name is not valid");
        return 2; // no device selected
    }
}

unsigned int CDevice::disconnectDevice(void){

    if(m_serialPort.isOpen()){
        m_serialPort.close();

        // wait for closed
        while(m_serialPort.isOpen()){;}
        emit information("Information", "Device on Port " + m_serialPort.portName() + "is disconnected");
        m_logger.write("Disconnected from " + m_serialPort.portName());
         emit connected(false);
        return 0;
    }else{
        emit information("Information", "No device to disconnect");
        return 1;
    }
}

unsigned int CDevice::sendString(QPlainTextEdit * _msgToSend)
{

    //Test qstringToPosition
    QByteArray Position1 = "0:1147.7 48.8 3891.5";
    QByteArray Position2 = "0:50.1 4713.3 73.9";
    CPosition pos1, pos2, pos3;

    qDebug() << "String: " << CPosition::positionToQByteArray(pos1);

    // clear read display
    if(m_responseDisplay!=nullptr)
        m_responseDisplay->clear();
    // clear read buffer
    m_asynchReadBuffer.clear();

    QByteArray data = _msgToSend->toPlainText().toLocal8Bit();
    data = data +"\r";
    int writtenBytes;

    // clear display for new response
    if(m_responseDisplay != 0)
        m_responseDisplay->clear();

   if (m_serialPort.isOpen())
   {
       if(m_serialPort.isWritable())
       {
           writtenBytes = m_serialPort.write(data);
           //int col = 0x0000ff;
           //plainTextEdit_Logger->setForeground(QBrush((Qt::GlobalColor)col));
           m_logger.write("sent: " + _msgToSend->toPlainText());
           if(1>=writtenBytes){
                qDebug() <<  writtenBytes << "byte was sent";
           }else{
               qDebug() <<  writtenBytes << "bytes were sent";
           }
           qDebug() << data << "were sent";
           return 0; // data were written
       }else{
           emit warning("Warnung", "Port could not be written");
           qDebug() << "Serial port is not writeable";
           return 1; //port is not writable
       }

   }else{
       qDebug() << "port is not open because:" << EnumHelper::toString(m_serialPort.error());
       emit warning("Warning", "Port could not be opened!");
       return 2; // port could not be opened
   }
}


// logger -----------------------------------------------------------

void CDevice::setDisplayLogger(QPlainTextEdit * _logger)
{
    m_logger.setPlainTextEdit(_logger);
}

// visualisation -----------------------------------------------------

void CDevice::displayFoundDevices(QTableWidget * _tableWidget)
{
    QTableWidgetItem * newItem;
    if(m_availablePorts>0){
        // fill tableWidget with found devices
        for(int i = 0; i < m_availablePorts; i++)
        {
            for(int j = 0; j< COLUMNS;j++){
                switch(j) {
                    case 0: // set device name
                        newItem = new QTableWidgetItem();
                        newItem->setText(m_availableDevices[i][j]);
                        _tableWidget->setItem(i, j, newItem);
                        qDebug() << "Port name Item:" << newItem->text();
                        qDebug() << "Port name String:" << m_availableDevices[i][j];
                        break;
                    case 1: // set vendor ID
                        newItem = new QTableWidgetItem();
                        newItem->setText(m_availableDevices[i][j]);
                        _tableWidget->setItem(i,j,newItem);
                        qDebug() << "Vendor ID:" << newItem->text();
                         qDebug() << "Vendor ID String:" << m_availableDevices[i][j];
                        break;
                    case 2: // set product ID
                        newItem = new QTableWidgetItem();
                        newItem->setText(m_availableDevices[i][j]);
                        _tableWidget->setItem(i,j,newItem);
                        qDebug() << "Product ID:" << newItem->text();
                        qDebug() << "Product ID String:" << m_availableDevices[i][j];
                        break;
                }
            }
        }
    }
}


void CDevice::setResponseDisplay(QPlainTextEdit *_responseDisp)
{
   m_responseDisplay = _responseDisp;
}


// slots -----------------------------------------------------------

 // public slots
unsigned int CDevice::readData(void)
{
    quint64 numberOfBytes;
    QByteArray data = "";
    m_readDone = false;
    data = m_serialPort.readAll();
    m_logger.write("reply: " + QString(data));
    m_asynchReadBuffer += data;
    qDebug() << "data recived " ;
    m_readTimeOut.start(READ_TIMEOUT);
    //QTimer::singleShot(READ_TIMEOUT, Qt::TimerType::PreciseTimer,this, &CDevice::readDone);
    return 0;

}

unsigned int CDevice::readDone(void)
{
    emit displayResponse(QString(m_asynchReadBuffer));
    qDebug() << "readDone emit displayResponse occoured";
    return 0;
}

unsigned int CDevice::on_synchResponse(QString response)
{
    //if(m_synchReadBuffer.size() > SYNCHBUFFER_LEN)
    //{
    //    m_synchReadBuffer.removeLast();
    //}

    m_synchReadBuffer.insert(0, response.toUtf8());
    emit displayResponse(response);
    qDebug() << "onSynch emit displayResponse occoured";
    return 0;
}

void CDevice::on_synchError(const QString &s)
{
    emit error("Error", s);
}

void CDevice::on_synchTimeout(const QString &s)
{
    emit stopStateMachine();
    emit error("Error", s);
}

void CDevice::on_threadStarted(void)
{
    m_synchCommConsumer.clearCommErr();
}
