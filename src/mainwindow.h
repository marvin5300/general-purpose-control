#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <src/measurementdevice.h>
#include <src/serialconsole.h>
#include <src/filehandler.h>
#include <QMainWindow>
#include <QMap>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
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

public slots:
    void onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);
    void onSettingsClicked();
    void onProgressReceived(int progress);
    void onMeasureReady(QString deviceName, quint64 number);
    void onScanParamSelReady(QString deviceName, quint64 number);
    void onTimerTimeout();
    void setSerialMask(QStringList masks);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddAdjustValuesButtonClicked();
    void onAddMeasureValuesButtonClicked();
    void adjustProgressBarAppearance(int value);
    void onStartMeasurementButtonClicked();
    void onFinishedMeasurement();

private:
    Ui::MainWindow *ui;
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
    bool ongoingMeasurement = false;
    void setUiMeasurementState(bool _ongoingMeasurement);
    void connectScanValues(bool doConnect);
    QTimer intervalTimer;
    bool timerOngoing;
    int numberOfScanparameterSelections;
    int scanParameterReadyCounter;
    int measurementReadyCounter = 0;
    quint64 measCount = 0;
    int measCycle = 0;
};

#endif // MAINWINDOW_H
