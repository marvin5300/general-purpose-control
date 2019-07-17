#ifndef SCANPARAMETERSELECTION_H
#define SCANPARAMETERSELECTION_H

#include <QFrame>
#include <QStandardItemModel>
#include "measurementparameter.h"
#include "measurementdevice.h"

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
    void onDeviceSelectionChanged(int selectedIndex);

private:
    Ui::ScanParameterSelection *ui;
};

#endif // SCANPARAMETERSELECTION_H