#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "measurementdevice.h"
#include "serialconsole.h"
#include "filehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void setOutputFile(QString filename);

public slots:
    void onDeviceSelectionChange(QPointer<MeasurementDevice> device, QString _newDeviceName, QString _newInterfaceName);
    void onSettingsClicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddAdjustValuesButtonClicked();
    void onAddMeasureValuesButtonClicked();
    void adjustProgressBarAppearance(int value);
    void onStartMeasurementButtonClicked();

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
};

#endif // MAINWINDOW_H
