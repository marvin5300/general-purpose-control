#include "filehandler.h"
#include <QMessageBox>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setOutputFile(QString fileName){
    if (!outputFile.isNull()){
        outputFile->close();
        outputFile.clear();
    }
    outputFile = new QFile(fileName);
    if (outputFile->exists()){
        int button =
                QMessageBox::warning(nullptr,tr("File exists"),
                                     tr("File already exists. Open anyway?"),
                                     QMessageBox::Open, QMessageBox::Abort);
        if (button == QMessageBox::Open){
            if (outputFile->open(QIODevice::ReadWrite)){
                emit openFileStatus(true);
                return;
            }
        }
    }
    outputFile.clear();
    emit openFileStatus(false);
}

const QString FileHandler::getFilePath(){
    if (outputFile.isNull()){
        return "";
    }
    return outputFile->fileName();
}
