#ifndef CPROBERVISU_H
#define CPROBERVISU_H

#include <GlobalConsts.h>
#include <EnumHelper.h>
#include <cprobersystem.h>
#include <CPositionVisuXYZ.h>
#include <CPositionVisuXY.h>
#include <CPosition.h>
#include <cmeasurementcontrol.h>

#include <QWidget>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QTextEdit>
#include <QLabel>
#include <QTableWidget>
#include <QObject>
#include <QMetaObject>
#include <QStatusBar>
#include <QGridLayout>
#include <QPointer>

// defines -----------------------
// PAGE_CONNECTION_TEST
#define LABEL_XTOP 10
#define LABEL_YTOP 10
#define YSPACE 40
#define XSPACE 20
#define LABEL_WIDTH_1 100
#define LABEL_WIDTH_2 200
#define LABEL_HEIGHT_1 30

#define PUSHBUTTON_WIDTH 140
#define PUSHBUTTON_HEIGHT 30
#define PUSHBUTTON_XSPACE 10

#define COMBOBOX_XPOS 120
#define COMBOBOX_WIDTH 150
#define COMBOBOX_HEIGHT 30

#define DEVICESEARCH_XPOS 300
#define TABLE_YPOS 80
#define TABLE_HEIGHT 150

#define CONNECT_STATE_YPOS 240

#define LABEL_SENDMSG_YPOS 260
#define TEXTEDIT_SEND_YPOS 300
#define TEXTEDIT_SEND_WIDTH 150
#define TEXTEDIT_SEND_HEIGHT 50
#define TEXTEDIT_SEND_XSPACE 50
#define PUSHBUTTON_SEND_YSPACE 30
#define TEXTEDIT_REPLY_WIDTH 200

// PAGE_MANUALCONTROL
#define TEXTEDIT_ACTPOS_XPOS 50
#define TEXTEDIT_ACTPOS_YPOS 50
#define TEXTEDIT_SETPOS_XPOS 50
#define TEXTEDIT_SETPOS_YPOS 400
#define TEXTEDIT_MC_WIDTH 100
#define TEXTEDIT_MC_HEIGHT 30
#define TEXTEDIT_MC_XSPACE 30

#define PUSHBUTTON_MC_YSPACE 10

#define LABEL_MC_ACTPOS_YPOS 25
#define LABEL_MC_SETPOS_YPOS 175

#define LABEL_MC_SYNCHCOMM_STATE_YPOS 90

#define LABEL_INPOSITIONZ_X 90
#define LABEL_INPOSITIONZ_Y 125
#define LABEL_INPOSITIONZ_WIDTH 150
#define LABEL_INPOSITIONZ_HEIGHT 30

#define LABEL_INPOSITIONXY_X 90
#define LABEL_INPOSITIONXY_Y 150
#define LABEL_INPOSITIONXY_WIDTH 150
#define LABEL_INPOSITIONXY_HEIGHT 30

#define LABEL_INPOSITIONZRECT_X 50
#define LABEL_INPOSITIONZRECT_Y 125
#define LABEL_INPOSITIONZRECT_WIDTH 20
#define LABEL_INPOSITIONZRECT_HEIGHT 20

#define LABEL_INPOSITIONXYRECT_X 50
#define LABEL_INPOSITIONXYRECT_Y 150
#define LABEL_INPOSITIONXYRECT_WIDTH 20
#define LABEL_INPOSITIONXYRECT_HEIGHT 20
// PAGE_STATE_MACHINE
#define LABEL_STATE_MACHINE_X 200
#define LABEL_STATE_MACHINE_Y 25
#define LABEL_STATE_MACHINE_WIDTH 275
#define LABEL_STATE_MACHINE_HEIGHT 25

#define TEXTEDIT_SPACE_Y 10

#define POSITIONS_SPACE_X 75

#define PUSHBUTTON_SM_START_X 25
#define PUSHBUTTON_SM_START_Y 25
#define PUSHBUTTON_SM_START_WIDTH 100
#define PUSHBUTTON_SM_START_HEIGHT 25

// PAGE_LOGGER
#define LOGGER_XPOS 50
#define LOGGER_YPOS 50
#define LOGGER_WIDTH 400
#define LOGGER_HEIGHT 300

#define LABEL_LOGGER_XPOS 50
#define LABEL_LOGGER_YPOS 20
#define LABEL_LOGGER_WIDTH 200
#define LABEL_LOGGER_HEIGHT 30


class CProberVisu : public QTabWidget
{
    Q_OBJECT
private:

    // pointer to tab pages
    QWidget * page_ConnectionTest;
    QWidget * page_ManualControl;
    QWidget * page_StateMachine;
    QWidget * page_Logger;

    // group boxes
    QGroupBox * gb_portSettings;
    QGroupBox * gb_deviceSearch;
    QGroupBox * gb_textMessage;
    QGroupBox * gb_proberState;
    QGroupBox * gb_manualControl;
    QGroupBox * gb_synchComm;
    QGroupBox * gb_stateMachineControl;
    QGroupBox * gb_stateMachinePositions;

    // pointer to gridLayouts
    QGridLayout * gridPageConnection;
    QGridLayout * gridLayout_PortSettings;
    QGridLayout * gridLayout_DeviceSearch;
    QGridLayout * gridLayout_SendTextMsg;
    QGridLayout * gridPageManualControl;
    QGridLayout * gridLayout_proberState;
    QGridLayout * gridLayout_manualControl;
    QGridLayout * gridLayout_synchComm;
    QGridLayout * gridPageStateMachine;
    QGridLayout * gridLayout_stateMachineControl;
    QGridLayout * gridLayout_stateMachinePositions;
    QVBoxLayout * vboxLayout_logger;

    // combo boxes
    QComboBox * comboBox_BaudRate;
    QComboBox * comboBox_Parity;
    QComboBox * comboBox_Databits;
    QComboBox * comboBox_Stopbits;
    QComboBox * comboBox_Flowcontrol;
    QComboBox * comboBox_MeasParam;

    // labels
    QLabel * label_PortSettings;
    QLabel * label_BaudRate;
    QLabel * label_Parity;
    QLabel * label_Databits;
    QLabel * label_Stopbits;
    QLabel * label_Flowcontrol;
    QLabel * label_DeviceSearch;
    QLabel * label_ConnectState;
    QLabel * label_ConnectionMsg;
    QLabel * label_SendTextMsg;
    QLabel * label_ProberLogger;
    QLabel * label_ActXPos;
    QLabel * label_ActYPos;
    QLabel * label_ActZPos;
    QLabel * label_SetXPos;
    QLabel * label_SetYPos;
    QLabel * label_SetZPos;
    QLabel * label_PosRef;
    QLabel * label_Unit;
    QLabel * label_Velocity;
    QLabel * label_SynchComm;
    QLabel * label_SynchCommState;
    QLabel * label_StateMachineActState;
    QLabel * label_Pos00;
    QLabel * label_Pos01;
    QLabel * label_Pos02;
    QLabel * label_Pos10;
    QLabel * label_Pos11;
    QLabel * label_Pos12;
    QLabel * label_Pos20;
    QLabel * label_Pos21;
    QLabel * label_Pos22;
    QLabel * label_inZPositionText;
    QLabel * label_inZPositionRectangle;
    QLabel * label_inXYPositionText;
    QLabel * label_inXYPositionRectangle;
    QLabel * label_inZPositionTextSM;
    QLabel * label_inZPositionRectangleSM;
    QLabel * label_inXYPositionTextSM;
    QLabel * label_inXYPositionRectangleSM;
    QLabel * label_bufferSize;
    QLabel * label_zPrePos;
    QLabel * label_zFinalPos;
    QLabel * label_MeasurementParam;

    // push buttons
    QPushButton * pushButton_Search;
    QPushButton * pushButton_Connect;
    QPushButton * pushButton_Disconnect;
    QPushButton * pushButton_Send;
    QPushButton * pushButton_ReadChuckPosition;
    QPushButton * pushButton_StartSynchRead;
    QPushButton * pushButton_StopSynchRead;
    QPushButton * pushButton_MoveChuckXY;
    QPushButton * pushButton_MoveChuckZ;
    QPushButton * pushButton_StartStateMachine;
    QPushButton * pushButton_goOn;
    QPushButton * pushButton_StopStateMachine;

    // table widget
    QTableWidget * tableWidget_Devices;

    // text edits
    QTextEdit * textEdit_SetXpos;
    QTextEdit * textEdit_SetYpos;
    QTextEdit * textEdit_SetZpos;
    QTextEdit * textEdit_PosRef;
    QTextEdit * textEdit_Unit;
    QTextEdit * textEdit_Velocity;
    QTextEdit * textEdit_xPos00;
    QTextEdit * textEdit_yPos00;
    QTextEdit * textEdit_zPos00;
    QTextEdit * textEdit_xPos01;
    QTextEdit * textEdit_yPos01;
    QTextEdit * textEdit_zPos01;
    QTextEdit * textEdit_xPos02;
    QTextEdit * textEdit_yPos02;
    QTextEdit * textEdit_zPos02;
    QTextEdit * textEdit_xPos10;
    QTextEdit * textEdit_yPos10;
    QTextEdit * textEdit_zPos10;
    QTextEdit * textEdit_xPos11;
    QTextEdit * textEdit_yPos11;
    QTextEdit * textEdit_zPos11;
    QTextEdit * textEdit_xPos12;
    QTextEdit * textEdit_yPos12;
    QTextEdit * textEdit_zPos12;
    QTextEdit * textEdit_xPos20;
    QTextEdit * textEdit_yPos20;
    QTextEdit * textEdit_zPos20;
    QTextEdit * textEdit_xPos21;
    QTextEdit * textEdit_yPos21;
    QTextEdit * textEdit_zPos21;
    QTextEdit * textEdit_xPos22;
    QTextEdit * textEdit_yPos22;
    QTextEdit * textEdit_zPos22;
    QTextEdit * textEdit_JoblistSize;
    QTextEdit * textEdit_zPrePos;
    QTextEdit * textEdit_zFinalPos;

    // plainTextEdits
    QPlainTextEdit * plaintextEdit_Msg;
    QPlainTextEdit * plaintextEdit_Reply;
    QPlainTextEdit * plainTextEdit_Logger;

    // combobox texts
    const QStringList m_databits = { EnumHelper::toString(QSerialPort::Data5),
                                   EnumHelper::toString(QSerialPort::Data6),
                                   EnumHelper::toString(QSerialPort::Data7),
                                   EnumHelper::toString(QSerialPort::Data8)
                                    };

    const QStringList m_bauds = { EnumHelper::toString(QSerialPort::Baud1200),
                                 EnumHelper::toString(QSerialPort::Baud2400),
                                 EnumHelper::toString(QSerialPort::Baud4800),
                                 EnumHelper::toString(QSerialPort::Baud9600),
                                 EnumHelper::toString(QSerialPort::Baud19200),
                                    };


    const QStringList m_parities = {EnumHelper::toString(QSerialPort::NoParity),
                                  EnumHelper::toString(QSerialPort::EvenParity),
                                  EnumHelper::toString(QSerialPort::OddParity),
                                  EnumHelper::toString(QSerialPort::SpaceParity),
                                  EnumHelper::toString(QSerialPort::MarkParity)
                                    };
    const QStringList m_stopbits = {EnumHelper::toString(QSerialPort::OneStop),
                                  EnumHelper::toString(QSerialPort::OneAndHalfStop),
                                  EnumHelper::toString(QSerialPort::TwoStop)
                                    };

    const QStringList m_flowControl = {EnumHelper::toString(QSerialPort::NoFlowControl),
                                    EnumHelper::toString(QSerialPort::HardwareControl),
                                    EnumHelper::toString(QSerialPort::SoftwareControl)
                                    };

    const QStringList m_measParams = { QString("Thresholdvoltage Vgs"),
                                        QString("Drain Source Leckage Idss"),
                                        QString("Gate Source Leckage Igss"),
                                        QString("Input Capacitance Ciss"),
                                        QString("Output Capacitance Coss"),
                                        QString("Feedback Capacitance Crss")
                                        };
    // cprober pointer
    CProberSystem * m_ptrProber = nullptr;
    // thread pointers for synch comm
    QThread *  consumerThread;
    QThread * producerThread;

    double m_zPrePos;
    double m_zFinalPos;
    // position visu xy
    CPositionVisuXY * positionVisu_00;
    CPositionVisuXY * positionVisu_01;
    CPositionVisuXY * positionVisu_02;
    CPositionVisuXY * positionVisu_10;
    CPositionVisuXY * positionVisu_11;
    CPositionVisuXY * positionVisu_12;
    CPositionVisuXY * positionVisu_20;
    CPositionVisuXY * positionVisu_21;
    CPositionVisuXY * positionVisu_22;
    // position visu xyz
    CPositionVisuXYZ * actPositionStateMachine;
    CPositionVisuXYZ * actPostionManualControl;
    CPositionVisuXYZ * setPositionManualControl;
    QStatusBar * statusBar_stateMachine;
    QLabel * label_ActState;

public:
    CProberVisu(QWidget * parent = nullptr);
    CProberVisu( int _x, int _y, int _width, int _height, CProberSystem * _ptrProber, QWidget * parent = nullptr);
    ~CProberVisu();

    QPlainTextEdit * getReadDataDisplay();
    void setThreads(QThread * _consumer, QThread * _producer);
    CPosition * getPositions(void);
    QPushButton * getPushButtonGoOn(void);
    QLabel * getLabelActState(void);
    CPositionVisuXYZ * getActPositionVisuSM(void);
    double readZValueFromTextEdit(QTextEdit * _zValue);
    void requestMeasurementControlData(void);

signals:
    void addCommand(QByteArray _command);
    void startStateMachine(void);
    void stopStateMachine(void);
    void deleteMeasurementDevices(void);
    void measurementParam(int i);
    void paramNameInFileChanged(QString _paramNameInFile);
    void zValuePrePos(double _zPreValue);
    void zValueFinalPos(double _zFinalPos);
    void changedPosition(int _row, int _column, CPosition _pos);
    void requesMeasCtrlData(void);
    void changePositionStylesheet(QString _stylesheet);
    // slots
private slots:
    void on_textEdit_ZPreValue_changed(void);
    void on_textEdit_ZFinalValue_changed(void);

public slots:
    void on_pushButton_Search_clicked();
    void on_pushButton_Connect_clicked();
    void on_tableWidget_Ports_itemSelectionChanged();
    void on_pushButton_Disconnect_clicked();
    void on_pushButton_SendString_clicked();
    void on_pushButton_ReadChuckPosition_clicked();
    void on_pushButton_StartSynchComm_clicked();
    void on_pushButton_StopSynch_clicked();
    void on_pushButton_MoveChuckXY_clicked();
    void on_pushButton_MoveChuckZ_clicked();
    void on_positionChanged(QString _posName, CPosition _newPosition);
    void on_pushButton_StartStateMachine_clicked(void);
    void on_pushButtonStopStateMachine_clicked(void);
    void on_stateMachineFinished(void);
    void on_stateMachineRunningChanged(bool _running);
    void on_measurementPositionChanged(int _row, int _column);


    void on_SynchCommFinished(void);
    void on_Connected(bool isConnected);
    void on_readData(QString  _readData);
    void on_proberInZPosition(void);
    void on_proberInXYPosition(void);
    void on_proberNotInZPosition(void);
    void on_proberNotInXYPosition(void);
    void on_bufferSizeChanged(int _bufferSize);
    void on_measurementControlData(QList<QList<CPosition>> _positionTable, double _zPreValue, double _zFinalValue);

    // pop up slots
    void on_ErrorMsg(QString _windowTitle, QString _windowText);
    void on_WarningMsg(QString _windowTitle, QString _windowText);
    void on_InformationMsg(QString _windowTitle, QString _windowText);

    // adjust device and its parameter
    void on_MeasuredParameter_Changed(int index);
    
};

#endif // CPROBERVISU_H
