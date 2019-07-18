#include "filehandler.h"
#include <QMessageBox>
#include <QTextStream>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setOutputFile(QString fileName){
    if (!outputFile.isNull()){
        outputFile->close();
        outputFile.clear();
    }
    if (fileName == ""){
        emit openFileStatus(false);
        return;
    }
    outputFile = new QFile(fileName);
    if (outputFile->exists()){
        int button =
                QMessageBox::warning(nullptr,tr("File exists"),
                                     tr("File already exists. Open anyway?"),
                                     QMessageBox::Open, QMessageBox::Abort);
        if (button != QMessageBox::Open){
            outputFile.clear();
            emit openFileStatus(false);
            return;
        }
    }
    if (outputFile->open(QIODevice::ReadWrite|QIODevice::Append)){
        emit openFileStatus(true);
    }
}

void FileHandler::writeToFile(QString line){
    if (outputFile.isNull()||(outputFile->isOpen()==false)){
        return;
    }
    QTextStream out(outputFile);
    out << line << endl;
}

const QString FileHandler::getFilePath(){
    if (outputFile.isNull()){
        return "";
    }
    return outputFile->fileName();
}

const QString FileHandler::getFileName(){
    if (outputFile.isNull()){
        return "";
    }
    return outputFile->fileName().split("/").last();
}
