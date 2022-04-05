#include <CLogger.h>

// constructor
CLogger::CLogger(QObject *parent, QString fileName, QPlainTextEdit *editor) : QObject(parent)
{
    m_editor = editor;
    m_showDate = true;
    m_fileName = fileName;
    if (!m_fileName.isEmpty()) {
     file = new QFile;
     file->setFileName(m_fileName + ".txt");
     file->open( QIODevice::WriteOnly | QIODevice::Text);
    }
}

CLogger::~CLogger() {

if (file != 0)
    file->close();
}

// write to logger file
void CLogger::write(const QString &value) {
    QString text = value;// + "";
    if (m_showDate)
     text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
    QTextStream out(file);
    out.setCodec("UTF-8");
    if (file != 0) {
     out << text << "\n";
    }
    if (m_editor != nullptr){
      m_editor->appendPlainText(text);
    }
}

void CLogger::setShowDateTime(bool value) {

    m_showDate = value;
}

void CLogger::setPlainTextEdit(QPlainTextEdit * _editor)
{
    m_editor = _editor;
}

QPlainTextEdit * CLogger::getPlainTextEdit()
{
    return m_editor;
}

QString CLogger::getFileName()
{
    return m_fileName;
}
