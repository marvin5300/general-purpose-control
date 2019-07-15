#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"


class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public slots:
    void onReceivedMessage(QString message);

public:
    using Keithley_2xxx::Keithley_2xxx;
    const QString getInterfaceName();
    const QString getDeviceName();

private:
    void connectRS232();
    const QString deviceName = "MODULE 2410";
};

#endif // KEITHLEY_2410_H
