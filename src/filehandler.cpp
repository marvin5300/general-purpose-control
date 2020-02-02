#include "filehandler.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

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

void FileHandler::onReceivingValues(QString deviceName, QList<MeasurementValue> values, quint64 number){
    //qDebug() << deviceName << " " << number;
    for (auto value : values){
        qDebug() << value.name << " " << value.value;
    }
    return;
    // does nothing except print it for now!!!
    QStringList valuesList = valueLineListMap.value(number);
    if (deviceName==""||values.empty()){
        return;
    }
    for (int i = valuesList.size(); i<fileHeaderStrings.size(); i++){
        // make sure size of the values list and fileHeaderStrings are same size
        // so no seg fault occurs
        valuesList.append(QString());
    }
    for (auto value : values){
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        if (!fileHeaderStrings.contains(fileHeader)){
            fileHeaderStrings.append(fileHeader);
            correctFileColumns();
        }
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value.value);
    }
    valueLineListMap.insert(number, valuesList);
    if (number > lastWrittenLine + bufferedLines || number < lastWrittenLine){
        writeBufferToFile(false); // writes only older buffered lines to file
    }
}

void FileHandler::writeBufferToFile(bool endOfMeasurement){
    if (outputFile.isNull()||(outputFile->isOpen()==false)){
        return;
    }
    QTextStream out(outputFile);
    for (QMap<quint64, QStringList>::Iterator it = valueLineListMap.begin(); it != valueLineListMap.end(); it++){
        if (endOfMeasurement || it.key()<=lastWrittenLine+bufferedLines){
            lastWrittenLine = it.key();
            for (auto string : it.value()){
                out << string << " ";
            }
            out << "\n";
        }
    }
}

void FileHandler::writeLine(QString line){
    if (outputFile.isNull()||(outputFile->isOpen()==false)){
        return;
    }
    QTextStream out(outputFile);
    out << line << endl;
}

void FileHandler::correctFileColumns(){

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
