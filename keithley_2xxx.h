#ifndef KEITHLEY_2XXX_H
#define KEITHLEY_2XXX_H

#include "measurement_device.h"

class Keithley_2xxx : public Measurement_Device
{
public:
    explicit Keithley_2xxx(QWidget *parent = 0);
};

#endif // KEITHLEY_2XXX_H
