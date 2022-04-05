#ifndef CMEASUREMENTDEVICE_H
#define CMEASUREMENTDEVICE_H

#include <cdevice.h>

#include <QObject>

class CMeasurementDevice : public CDevice
{
    Q_OBJECT
public:
    CMeasurementDevice();
    ~CMeasurementDevice();

signals:
    void measurementDone(void);
};

#endif // CMEASUREMENTDEVICE_H
