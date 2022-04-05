#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ui_mainwindow.h>

// user created includes ---
#include <EnumHelper.h>
#include <CLogger.h>
#include <cprobersystem.h>
#include <cprobervisu.h>
#include <cmeasurementdevice.h>
#include <cdevice.h>
//
#include <filehandler.h>
#include <serialconsole.h>
#include <measurementdevice.h>
#include <scanparameterselection.h>
#include <devices/keithley_2410.h>
// -------------------------

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QMessageBox>
#include <QMetaEnum>
#include <QDesktopServices>
#include <QUrl>
#include <QTimer>
#include <QPointer>
#include <filehandler.h>




// defines -----------------
#define COLUMNS 3
#define VENDOR_ID 1
#define PRODUCT_ID 2
#define COMMENT_ID 3

// stacked Widget pages
#define MEASUREMENTS 0
#define PAGE_PROBER 1
#define PAGE_MEASUREMENT_DEVS 2
#define LOGGER 3

// -------------------------

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT
signals:
    void setOutputFile(QString filename);
    void setAutoOutputFile(bool autoOutput);
    void nextInterval();
    void measure(quint64 count);
    void scanInit();
    void startMeasurement();
    void finishedMeasurement();
    void probeProgress(int progressStart = 0);
    void setMeasureParam(DeviceParameterConstraint _paramConstraint);
    void ongoingMeasurementChanged(bool );
private:
    bool m_remoteProber = false; // true= prober in remote control

    // prober
    CProberSystem m_prober;
    CProberVisu * m_ptrProberVisu;
    QThread * m_consumer;
    QThread * m_producer;
    CMeasurementControl * m_ptrMeasCtrl;

    //Measurement Devices
    QPointer<FileHandler> fileHandler;
    QString highLevel = "QProgressBar {"
                        "background-color: #74c8ff;"
                        "color: #33ff33;"
                        "text-align: center; }"
                        "QProgressBar::chunk {"
                        "background-color: #010327; }";
    QString lowLevel =  "QProgressBar {"
                        "background-color: #74c8ff;"
                        "color: #008000;"
                        "text-align: center; }"
                        "QProgressBar::chunk {"
                        "background-color: #010327; }";
    QTimer intervalTimer;
    QTimer measurementDelay; //start delay measurement 
    bool ongoingMeasurement = false;
    void setUiMeasurementState(bool _ongoingMeasurement);
    void connectScanValues(bool doConnect);
    bool timerOngoing;
    int numberOfScanparameterSelections;
    int scanParameterReadyCounter;
    int measurementReadyCounter = 0;
    quint64 measCount = 0;
    int measCycle = 0;

    QList<ScanParameterSelection*> scanParramWindows;
  

public:
    MainWindow(QThread * _consumer, QThread * _producer, QWidget *parent = nullptr);
    ~MainWindow();
    void initConnections(void);
private slots:
    void on_pushButton_Logger_clicked();
    void on_pushButton_Measurements_clicked();
    void on_pushButton_Prober_clicked();
    void on_pushButton_Open_clicked();
    void on_pushButton_MeasDevs_clicked();
    // MArvin Peter
    void onAddAdjustValuesButtonClicked();
    void onAddMeasureValuesButtonClicked();
    void adjustProgressBarAppearance(int value);
    void onStartMeasurementButtonClicked();
    void onFinishedMeasurement();
public slots:
    void onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);
    void onSettingsClicked();
    void onProgressReceived(int progress);
    void onMeasureReady(QString deviceName, quint64 number);
    void onScanParamSelReady(QString deviceName, quint64 number);
    void onTimerTimeout();
    void setSerialMask(QStringList masks);
    void onDeletMeasurementDevices(void);
    void onAddMeasurementDevices(int _measurementParam);
    void onTimerStart(void);

};
#endif // MAINWINDOW_H
