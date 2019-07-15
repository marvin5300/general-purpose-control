#ifndef SCANPARAMETERSELECTION_H
#define SCANPARAMETERSELECTION_H

#include <QFrame>
#include "measurementdevice.h"
#include <QStandardItemModel>

namespace Ui {
class ScanParameterSelection;
}

class ScanParameterSelection : public QFrame
{
    Q_OBJECT

public:
    explicit ScanParameterSelection(QWidget *parent = nullptr);
    ~ScanParameterSelection();

private slots:
    void onDeviceSelectionChanged(QString deviceName);

private:
    Ui::ScanParameterSelection *ui;
};

#endif // SCANPARAMETERSELECTION_H
