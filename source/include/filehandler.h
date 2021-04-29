#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "measurementparameter.h"
#include <QObject>
#include <QPointer>
#include <QFile>
#include <QMap>

/**
* @brief Manages all operations related to file access.
* Also creates valid datafiles from measured values and event counter.
* Will be fitted with more options regarding different output file formats in the future.
*/
class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
    const QString getFilePath();
    const QString getFileName();

signals:
    void openedFileName(const QString filename);

public slots:
    void setOutputAutomatic(bool autoOutput);
    void setOutputFile(QString fileName);
    void onNewMeasurementStarted();
    void onFinishedMeasurement();
    void onReceivingValues(QString devicename, QList<MeasurementValue> values, quint64 number);
    void writeLine(QString line);
    void writeBufferToFile(bool endOfMeasurement);

private:
    void correct_columns();
    void createAutomaticOutputFile();
    QString placeholder = "n/a";
    QPointer<QFile> outputFile;
    bool _autoOutput = false;
    quint64 lastWrittenLine = 0;
    QStringList fileHeaderStrings = {"time"/*,"Wert"*/};
    QMap<quint64, QStringList> valueLineListMap;
    quint64 bufferedLines = 100;
    QString x,y=0;
};

#endif // FILEHANDLER_H
