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
    void measuredValues(QString deviceName, QList<MeasurementValue> measVals, quint64 number);
    void queueMeasure(quint64 count);
    void addProgress(double progress);

public:
    explicit ScanParameterSelection(QWidget *parent = nullptr);
    ~ScanParameterSelection();
    QPointer<QHBoxLayout> layout;

public slots:
    void measure(quint64 count);
    void nextScanParameterStep();
    void scanParameterInit();
    void measurementFinished();
    void progressCarry(int progress);
    void onMeasureValuesReceived(QList<MeasurementValue> measVals, quint64 count);

private slots:
    void onDeviceSelectionChanged(int selectedIndex);
    void keepDeviceSelectionIndex();
    void onScanParameterAdjustModeChanged(QString mode);

private:
    Ui::ScanParameterSelection *ui;
    int deviceSelectionIndex = 0;
    double parameterBeginValue = 0.0;
    double parameterCurrentValue = 0.0;
    double parameterEndValue = 1.0;
    quint64 stepNumber = 100;
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
