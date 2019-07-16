#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <QObject>
#include <QPointer>
#include <QFile>

class FileHandler : public QObject
{
    Q_OBJECT
public:
    explicit FileHandler(QObject *parent = nullptr);
    const QString getFilePath();

signals:
    void openFileStatus(bool successful);

public slots:
    void setOutputFile(QString fileName);

private:
    QPointer<QFile> outputFile;
};

#endif // FILEHANDLER_H
