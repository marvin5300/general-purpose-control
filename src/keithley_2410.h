#ifndef KEITHLEY_2410_H
#define KEITHLEY_2410_H

#include "keithley_2xxx.h"

namespace Ui {
class Keithley_2410;
}

class Keithley_2410 : public Keithley_2xxx
{
    Q_OBJECT

public:
    explicit Keithley_2410(QWidget *parent = 0);
    ~Keithley_2410();

private:
    Ui::Keithley_2410 *ui;
};

#endif // KEITHLEY_2410_H
