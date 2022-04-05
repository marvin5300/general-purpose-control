#ifndef CPROBERSYSTEM_H
#define CPROBERSYSTEM_H

#include <GlobalConsts.h>
#include <CLogger.h>
#include <EnumHelper.h>
#include <cdevice.h>
#include <CPositionVisuXYZ.h>


#include <QSerialPort>
#include <QSerialPortInfo>
#include <QObject>
#include <CPosition.h>
#include <QPlainTextEdit>
#include <QDebug>
#include <QTableWidgetItem>
#include <QApplication>
#include <QLabel>
#include <QMessageBox>
#include <QPointer>
#include <QBitArray>


// defines -----------------
#define EPSYLON 0.2 // difference while in Position signal
//
#define PORT_NAME 0
#define VENDOR_ID 1
#define PRODUCT_ID 2

// return value errors
#define NO_ERROR 0
#define WRITE_ERROR 1
#define PORT_NOT_WRITEABLE 2
#define PORT_NOT_OPEN 3
#define INPUTERROR_POSREF 4
#define INPUTERROR_UNIT 5
#define INPUTERROR_VELOCITY 6
#define INPUTERROR_READPOS 7

// -------------------------


class CProberSystem : public CDevice
{
    Q_OBJECT
    private:
        // attributes
        // motion
        CPosition m_actPosition;
        CPosition m_setPosition;
        CPosition m_startPosition;
        bool m_inZPosition = false;
        bool m_inXYPosition = false;
        // timer for readChuckPos request
        QTimer m_cycReadPos;
        unsigned int m_interval = 3000; //ms
        // visualisation

        // logger


    public:
        // methods
        CProberSystem(void);
        CProberSystem(QString _deviceName, QPlainTextEdit * _readDataDisp = nullptr, QWidget *_loggerDisp = nullptr);
        CProberSystem(QString _deviceName, QSerialPort::BaudRate _baudRate = QSerialPort::Baud9600,
                      QSerialPort::Parity _parity = QSerialPort::NoParity, QSerialPort::DataBits _dataBits = QSerialPort::Data8,
                      QSerialPort::StopBits _stopBits = QSerialPort::OneStop, QSerialPort::FlowControl _flowControl = QSerialPort::NoFlowControl,
                      QPlainTextEdit * _display = nullptr, QPlainTextEdit *_loggerDisp = nullptr);

        ~CProberSystem(void);
        //general
        CPosition getActPosition(void);
        void setReadPosInterval(unsigned int _interval);
        void initProberConnections(void);
        // communication
        void startCyclPosRead(void);
        void stopCycPosRead(void);
        bool isCycPosReadActive(void);
        // motion -------

        // visualisation

        // logger

    signals:
        void inPosition(void);
        void addCommand(QByteArray _command);
        void inZPosition(void);
        void inXYPosition(void);
        void notInZPosition(void);
        void notInXYPosition(void);
        void actPosition(CPosition _position );
    private slots:
        void on_timeoutCycReadPos(void);
    public slots:
        // communication
        //unsigned int readDone(void) override;

        // motion
        unsigned int on_asynchReadChuckPosition(CPosition * _readPosition = nullptr);                                   // can be used as slot or as usal method
        unsigned int on_synchReadChuckPos(const QString _readChuckPos);
        unsigned int on_requestMoveChuckXY(double _xPos, double _yPos, QString _posRef, QString _unit, QString _velocity);      // can be used as slot or as usal method
        unsigned int on_requestMoveChuckZ(double _zPos, QString _posRef, QString _unit, QString _velocity);
        unsigned int on_response(const QString &_response);
        void on_requestInPosition(void);
        // visualisation
        void displayActPosition(CPositionVisuXYZ * _actPosition);

};

#endif // CPROBERSYSTEM_H
