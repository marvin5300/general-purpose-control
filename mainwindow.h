#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void scpiCommand(QString command);
    void disconnectRS232(QString portName);

public slots:
    void connectRS232(QString portName, quint32 baudRate, QString deviceName);
    void onReceivedMessage(QString message);
    void onReceivedConnectionStatus(bool connected, QString portName);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onConnectButtonClicked();
    void onSendButtonClicked();

private:
    Ui::MainWindow *ui;
    QStringList devices = {"MODEL 2410", "MODEL 2000"};
    QStringList ports = {"COM1", "COM2", "COM3", "COM4", "COM5"};
#if defined(Q_OS_UNIX)
    QFile file(QString(QStandardPaths::writableLocation(QStandardPaths::HomeLocation)+"/.muondetector-gui.save"));
#elif defined(Q_OS_WIN)
    QFile file(QString("ipAddresses.save"));
#else
    QFile file(QString("ipAddresses.save"));
#endif
};

#endif // MAINWINDOW_H
