#ifndef KEITHLEY_2000_H
#define KEITHLEY_2000_H

#include "keithley_2xxx.h"

namespace Ui {
class Keithley_2000;
}

class Keithley_2000 : public Keithley_2xxx
{
    Q_OBJECT

public:
    explicit Keithley_2000(QWidget *parent = 0);
    ~Keithley_2000();

private:
    Ui::Keithley_2000 *ui;
};

#endif // KEITHLEY_2000_H
