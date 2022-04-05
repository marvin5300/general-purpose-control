#ifndef CMEASUREMENTCONTROL_H
#define CMEASUREMENTCONTROL_H

#include <GlobalConsts.h>
#include <cprobersystem.h>
#include <cmeasurementdevice.h>

#include <QObject>
#include <QMutex>
#include <QString>
#include <QObject>
#include <QStateMachine>
#include <QFinalState>
#include <QLabel>
#include <QPushButton>
#include <QThread>
#include <QTimer>
#include <QDateTime>


// define states
#define STATE_MOVECHUCK_Z 10
#define STATE_MOVECHUCK_XY 20
#define STATE_MOVECHUCK_FINALPOS 30
#define STATE_MEASURING 40
#define STATE_CHECK_MEASUREMENT 50



class CMeasurementControl : public QObject
{
    Q_OBJECT
private:
    QStateMachine m_machine;
    QState * m_s1;
    QState * m_s2;
    QState * m_s3;
    QState * m_s4;
    QState * m_s5;
    QFinalState * m_finalState;

    // device interfaces
    CProberSystem * m_ptrProber = nullptr;
    CMeasurementDevice * m_ptrMeasDev = nullptr;

    // threads
    QThread * m_consumer;
    QThread * m_producer;

    // measurement positions
    unsigned int m_row = 0;
    unsigned int m_column = 0;
    QList<QList<CPosition>> m_postionTable;
    double m_zPreValue, m_zFinalValue;
    QString m_chuckZVelocity = "20"; // Chuck Velocity  in %
    QString m_chuckXYVelocity = "40"; // Chuck Velocity  in %

    // visualisation
    QPushButton * m_ptrPushButton_GoOn = nullptr;
    QLabel * m_ptrlabel_ActState = nullptr;
    QDateTime m_dateTime;       // current date time for file names
    QString m_paramNamInFile;   // parameter name in File for current Measurement

    // measurement running
    bool m_ongoingMeasurement;
    // off delay after measurement done
    QTimer m_offdelay;



public:
    CMeasurementControl(CProberSystem * _ptrProber, QLabel * _ptrLabel_ActState, QPushButton * _ptrPushButton_GoOn);
    ~CMeasurementControl();

    void setProber(CProberSystem * _ptrProber);
    void setMeasurementDevice(CMeasurementDevice * _ptrMeasDev);
    void setActStateLabel(QLabel * _ptrLabel);
    void setGoOnButton(QPushButton * _ptrPushButton);
    //void setPositions(QList<QList<CPosition>> _positions);
    const QStateMachine * const getStateMachine(void);
    void setThreads(QThread * _consumer, QThread * _producer);
    void setReadPosInterval(unsigned int _interval);
    void setChuckVelocity(QString _velocity);


private slots:
    void on_moveToPrePosition(void);
    void on_moveToMeasurePosition(void);
    void on_startMeasurement(void);
    void on_machineStarted(void);
    void on_s2Exited(void);

    void on_increaseRow(void);
    void on_s3Exited(void);
    void on_checkMeasurementStatus(void);
    void on_timeoutCycReadPos(void);
    void on_stateMachineFinished(void);

public slots:
     void on_startStateMachine(void);
     void on_stopStateMachine(void);
     void on_runningChanged(bool _running);
     void on_parameterNameChanged(QString _parameterName);
     void on_zValuePrePosChanged(double _zValue);
     void on_zValueFinalPosChanged(double _zValue);
     void on_positionChanged(int _row, int _column, CPosition _pos);
     void on_requestMeasurementControlData(void);
     void on_ongoingMeasurementChanged(bool _ongoingMeasurement);
     void on_measurementFinished(void);
     

signals:
    void requestMoveChuckXY(double _xPos, double _yPos, QString _posRef, QString _unit, QString _velocity);
    void requestMoveChuckZ(double _zPos, QString _posRef, QString _unit, QString _velocity);
    void requestReadChuckPos(const QString _readChukPosCmd = "ReadChuckPosition");
    void continueMeasurement(void);
    void finishMeasurement(void);
    void requestZValue(int _index = 0);
    void requestInXYPosition(void);
    void requestInZPosition(void);
    void warning(QString _windowTitle, QString _windowText);
    void information(QString _windowTitle, QString _windowText);
    void stateMachineRunningChanged(bool _running);
    void measurePositionChanged(int _row, int _column);
    void startMeasurement(void);
    void informationPopUp(QString _windowTitle, QString _windowText);
    void createFile(QString _filename);
    void measurementFinished(void);
    void measurementControlData(QList<QList<CPosition>> _positionList, double _zPreValue, double _zFinalValue);
    void stopMeasurement(void);
};

#endif // CMEASUREMENTCONTROL_H
