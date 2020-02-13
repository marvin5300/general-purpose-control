#include "filehandler.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>

FileHandler::FileHandler(QObject *parent) : QObject(parent)
{

}

void FileHandler::setOutputFile(QString fileName){
    if (!outputFile.isNull()){
        outputFile->close();
        outputFile.clear();
    }
    if (fileName == ""){
        emit openedFileName("no file");
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
            emit openedFileName("no file");
            return;
        }
    }
    if (outputFile->open(QIODevice::ReadWrite|QIODevice::Append)){
        emit openedFileName(outputFile->fileName());
    }
}

void FileHandler::onNewMeasurementStarted(){
    if (!outputFile.isNull()){
        return;
    }
    if (_autoOutput){
        createAutomaticOutputFile();
    }
}

void FileHandler::createAutomaticOutputFile(){
    // create automatic output file
}

void FileHandler::onFinishedMeasurement(){
    writeBufferToFile(true);
    if (!_autoOutput){
        emit openedFileName("no file");
        return;
    }
    createAutomaticOutputFile();
}

void FileHandler::setOutputAutomatic(bool autoOutput){
    if (!_autoOutput&&autoOutput){
        outputFile->close();
        outputFile.clear();
        createAutomaticOutputFile();
        _autoOutput = true;
    }
}

void FileHandler::onReceivingValues(QString deviceName, QList<MeasurementValue> values, quint64 number){
    //qDebug() << deviceName << " " << number;
    for (auto value : values){
        qDebug() << value.name << " " << value.value;
    }
    if (outputFile.isNull()){
        return;
    }
    if (deviceName==""||values.empty()){
        return;
    }
    QStringList valuesList;
    /*for (auto value : values){
        valuesList.append(QString(value.name+"["+deviceName+"]:%1").arg(value.value));
    }
    */
    qDebug() << "size";
    for (auto value : values){
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        if (!fileHeaderStrings.contains(fileHeader)){
            fileHeaderStrings.append(fileHeader);
            correct_columns();
        }
    }
    for (int i = 0; i < fileHeaderStrings.size(); i++){
        // make sure size of the values list and fileHeaderStrings are same size
        // so no seg fault occurs
        valuesList.append(QString());
    }
    qDebug() << "valuesList size" << valuesList.size();
    valuesList[0] = (QString("%1").arg(QDateTime::currentMSecsSinceEpoch()));
    qDebug() << "after insert timestamp";
    for (auto value : values){
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        qDebug() << "insert " << value.value << " at "<<(fileHeaderStrings.indexOf(fileHeader));
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value.value);
    }
    qDebug() << "after filling valuesList";
    valueLineListMap.insert(number, valuesList);
    if (number > lastWrittenLine + bufferedLines || number < lastWrittenLine){
        writeBufferToFile(false); // writes only older buffered lines to file
    }
}

void FileHandler::writeBufferToFile(bool endOfMeasurement){
    qDebug() << "write buffer to file, end of measurement: "<<endOfMeasurement;
    qDebug() << "buffer: "<<valueLineListMap;
    if (outputFile.isNull()||(outputFile->isOpen()==false)||valueLineListMap.empty()){
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
    if (endOfMeasurement){
        outputFile->close();
        outputFile.clear();
    }
}

void FileHandler::correct_columns(){

}

void FileHandler::writeLine(QString line){
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
