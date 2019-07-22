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
    void measureValues(QList<MeasurementValue> measVals);

public:
    explicit ScanParameterSelection(QWidget *parent = nullptr);
    ~ScanParameterSelection();
    QPointer<QHBoxLayout> layout;

public slots:
    void measure(quint64 count);
    void nextScanParameterStep();

private slots:
    void onDeviceSelectionChanged(int selectedIndex);
    void keepDeviceSelectionIndex();
    void onScanParameterAdjustModeChanged(QString mode);

private:
    Ui::ScanParameterSelection *ui;
    int deviceSelectionIndex = 0;

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
