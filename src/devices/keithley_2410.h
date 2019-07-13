#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"


class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public:
    using Keithley_2xxx::Keithley_2xxx;
    const QString deviceName = "MODULE 2410";

private:
};

#endif // KEITHLEY_2410_H
