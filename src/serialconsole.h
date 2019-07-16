#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include <QFrame>

namespace Ui {
class SerialConsole;
}

class SerialConsole : public QFrame
{
    Q_OBJECT

signals:
    void closeConnection();
    void scpiCommand(QString command);

public slots:
    void onReceivedMessage(QString message);
    void onConnectionStatusChanged(bool connected);

public:
    explicit SerialConsole(QWidget *parent = nullptr);
    ~SerialConsole();

private:
    Ui::SerialConsole *ui;
    void onConnectButtonClicked();
    void connectRS232(QString _interfaceName, quint32 _baudRate);
};

#endif // SERIALCONSOLE_H
