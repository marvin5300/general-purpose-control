#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QPointer>
#include <QFile>
#include "measurementparameter.h"
#include <QMap>

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
    const QString getFilePath();
    const QString getFileName();

signals:
    void openFileStatus(bool successful);

public slots:
    void setOutputFile(QString fileName);
    void onReceivingValues(QString devicename, QList<MeasurementValue> values, quint64 number);
    void writeLine(QString line);
    void writeBufferToFile(bool endOfMeasurement);

private:
    QString placeholder = "n/a";
    QPointer<QFile> outputFile;
    quint64 lastWrittenLine = 0;
    QStringList fileHeaderStrings;
    QMap<quint64, QStringList> valueLineListMap;
    quint64 bufferedLines = 100;
    void correctFileColumns();
};

#endif // FILEHANDLER_H
