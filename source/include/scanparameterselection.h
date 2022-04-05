#ifndef SCANPARAMETERSELECTION_H
#define SCANPARAMETERSELECTION_H

#include "measurementparameter.h"
#include "measurementdevice.h"
#include <QFrame>
#include <QStandardItemModel>
#include <QLayout>
#include <QTimer>
#include <devices/keithley_2410.h>
//#include <QMouseEvent>

namespace Ui {
class ScanParameterSelection;
}

class ScanParameterSelection : public QFrame
{
    Q_OBJECT

signals:

    /**
    * Sent when this scan parameter completes one loop
    */
    void completedLoop();

    /**
    * Sends progress calculation to next scan parameter in the loop.
    * Only used to create a plausible progress bar.
    */
    void addProgress(double progress);

    /**
    * Sends ready state to main window if scan parameter set successfully
    * @param deviceName this associated device name
    * @param number event measurement ID
    */
    void scanParameterReady(QString deviceName, quint64 number);

    void scanParameterSelectionChanged(int _index);

public:
    explicit ScanParameterSelection(QWidget *parent = nullptr);
    ~ScanParameterSelection();

    /**
    * Pointer to layout this widget sits in.
    * Used to move this widget when drag and dropping.
    */
    QPointer<QHBoxLayout> layout;

    /**
     * counts the scan parameter objects
     */
    static int numberOfObjects;
    

public slots:
    /**
    * Called when main window calls for next scan parameter step.
    * (Next measurement loop step)
    */
    void nextScanParameterStep();

    /**
    * Called at beginning of measurement loop.
    */
    void scanParameterInit();

    /**
    * Used to calculate the accumulated progress through nested event loop.
    * Emits addProgress.
    * Only used to create a plausible progress bar.
    */
    void progressCarry(int progress);

    /**
    * Called when MeasurementDevice calls that scan parameter is set.
    * @param deviceName this associated device name
    * @param number event measurement ID
    */
    void onDeviceScanParameterReady(QString deviceName, quint64 number);

     /**
     * getter for number of objects
     */
    static int getNumberOfScanParameterselection(void); 

    /**
     * enables to change scnparameters from program code
     */
    void setScanparameters(QString _deviceName, QString _scanParam, QString _scanMode, int _numberOfSteps, double _minVal, double _maxVal);

private slots:
    
    /**
    * Called when device selection drop box changes selection.
    */
    void onDeviceSelectionChanged(int selectedIndex);

    /**
    * Helper function to allow only valid device selection drop box indices
    */
    void keepDeviceSelectionIndex();

    /**
    * Called when adjust mode changed in drop box.
    * Adjust mode examples are 'ramp' or 'fixed'.
    * Changes appearance of widget when adjust mode changes.
    */
    void onScanParameterAdjustModeChanged(QString mode);

    /**
     * decrase static counter of object
     */
    void decraseNumberOfObject(void);

    
    

private:
    Ui::ScanParameterSelection *ui;
    QPointer<MeasurementDevice> lastSelectedDevice;
    int deviceSelectionIndex = 0;
    double parameterBeginValue = 0.0;
    double parameterCurrentValue = 0.0;
    double parameterEndValue = 1.0;

    /**
    * Number of steps to complete one measurement loop
    */
    quint64 stepNumber = 100;
    
    /**
    * Tracks scan loop step. Increases each step.
    */
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
