#ifndef SCANPARAMETERSELECTION_H
#define SCANPARAMETERSELECTION_H

#include <QFrame>
#include <QStandardItemModel>
#include "measurementparameter.h"
#include "measurementdevice.h"
#include <QLayout>
#include <QTimer>
//#include <QMouseEvent>

namespace Ui {
class ScanParameterSelection;
}

class ScanParameterSelection : public QFrame
{
    Q_OBJECT

signals:
    void completedLoop();
    void addProgress(double progress);
    void scanParameterReady(QString deviceName, quint64 number);

public:
    explicit ScanParameterSelection(QWidget *parent = nullptr);
    ~ScanParameterSelection();
    QPointer<QHBoxLayout> layout;

public slots:
    void nextScanParameterStep();
    void scanParameterInit();
    void progressCarry(int progress);
    void onDeviceScanParameterReady(QString deviceName, quint64 number);

private slots:
    void onDeviceSelectionChanged(int selectedIndex);
    void keepDeviceSelectionIndex();
    void onScanParameterAdjustModeChanged(QString mode);

private:
    Ui::ScanParameterSelection *ui;
    QPointer<MeasurementDevice> lastSelectedDevice;
    int deviceSelectionIndex = 0;
    double parameterBeginValue = 0.0;
    double parameterCurrentValue = 0.0;
    double parameterEndValue = 1.0;
    quint64 stepNumber = 100;
    quint64 setScanCounter;
    // enable drag drop of widget
    enum MoveDirection{MoveLeft,MoveRight,MoveUp,MoveDown};
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    bool isMinimumDistanceRiched(QMouseEvent *event);
    bool moveInLayout(QWidget *widget, MoveDirection direction);
    QPoint dragStartPosition;
    QTimer timer;
    bool mouseReleaseReady = true;
    int oldX = 0;
    int oldY = 0;
    int mouseClickX = 0;
    int mouseClickY = 0;
};

#endif // SCANPARAMETERSELECTION_H
