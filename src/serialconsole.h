#ifndef SERIALCONSOLE_H
#define SERIALCONSOLE_H

#include "measurementdevice.h"
#include <QGroupBox>

namespace Ui {
class SerialConsole;
}

class SerialConsole : public MeasurementDevice
{
    Q_OBJECT

public:
    explicit SerialConsole(QWidget *parent = nullptr);
    ~SerialConsole();

private:
    Ui::SerialConsole *ui;
};

#endif // SERIALCONSOLE_H
