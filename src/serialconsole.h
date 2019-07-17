#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include <QDialog>

namespace Ui {
class SerialConsole;
}

class SerialConsole : public QDialog
{
    Q_OBJECT

signals:
    void closeConnection();
    void scpiCommand(QString command);

public slots:
    void onReceivedMessage(QString message);
    void onConnectionStatusChanged(bool connected);

public:
    explicit SerialConsole(QWidget *parent = nullptr, Qt::WindowFlags flags =
            Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    ~SerialConsole();

private:
    Ui::SerialConsole *ui;
    void onSendButtonClicked();
    void onConnectButtonClicked();
    void connectRS232(QString _interfaceName, quint32 _baudRate);
};

#endif // SERIALCONSOLE_H
