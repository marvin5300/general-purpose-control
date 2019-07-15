#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"


class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public slots:
    void onReceivedMessage(QString message);

public:
    explicit Keithley_2410(QString _interfaceName);
    const QString getInterfaceName();
    const QString getDeviceName();

private:
    void init();
    void connectRS232();
    const QString deviceName = "MODULE 2410";
};

#endif // KEITHLEY_2410_H
