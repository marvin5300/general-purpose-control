#ifndef SETVALUE_H
#define SETVALUE_H

#include <QFrame>
#include "measurementdevice.h"
#include <QStandardItemModel>

namespace Ui {
class SetValue;
}

class SetValue : public QFrame
{
    Q_OBJECT

public:
    explicit SetValue(bool _measureOnly = true, QWidget *parent = nullptr);
    ~SetValue();
    bool measureOnly = true;

private slots:
    void onDeviceSelectionChanged(QString deviceName);

private:
    Ui::SetValue *ui;
    MeasurementDevice *device = nullptr;
};

#endif // SETVALUE_H
