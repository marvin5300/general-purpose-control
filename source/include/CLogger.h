#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QPlainTextEdit>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <iostream>

class CLogger : public QObject {
    Q_OBJECT

public:
    explicit CLogger(QObject *parent, QString fileName, QPlainTextEdit *editor = 0);
    ~CLogger();
    void setShowDateTime(bool value);
    void setPlainTextEdit(QPlainTextEdit * _editor);
    QPlainTextEdit * getPlainTextEdit();
    QString getFileName();


private:
    QFile *file;
    QPlainTextEdit *m_editor;
    bool m_showDate;
    QString m_fileName;

signals:
    ;
public slots:
    void write(const QString &value);

};

#endif // LOGGER_H
