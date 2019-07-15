#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include "measurementdevice.h"
#include <QFrame>

namespace Ui {
class SerialConsole;
}

class SerialConsole : public QFrame
{
    Q_OBJECT

public slots:
    void onReceivedMessage(QString message);

public:
    explicit SerialConsole(QWidget *parent = nullptr);
    const QString getInterfaceName();
    const QString getDeviceName();
    ~SerialConsole();

private:
    void init();
    Ui::SerialConsole *ui;
    void connectRS232();
};

#endif // SERIALCONSOLE_H
