#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"

class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public:
    explicit Keithley_2410(QWidget *parent = 0);

private:
};

#endif // KEITHLEY_2410_H
