#ifndef KEITHLEY_2000_H
#define KEITHLEY_2000_H

#include "keithley_2xxx.h"

class Keithley_2000 : public Keithley_2xxx
{
    Q_OBJECT

public:
    explicit Keithley_2000(QWidget *parent = 0);

private:
};

#endif // KEITHLEY_2000_H
