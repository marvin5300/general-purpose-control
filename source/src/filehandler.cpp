#include "filehandler.h"
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>
#include <QDateTime>
#include <serial.h>
#include <QObject>
#include <string>


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

void FileHandler::onReceivingValues(QString deviceName, QList<MeasurementValue>values, quint64 number){
    //qDebug() << deviceName << " " << number //number gibt cycle nummer an
    for (auto value : values){
        qDebug() << value.name << value.value;
    }
    for (auto value1 : values){
        qDebug() << value1.name << value1.value1;
    }
    if (outputFile.isNull()){
        return;
    }
    if (deviceName==""||values.empty()){
        return;
    }
    QStringList valuesList;
    //valuesList=new QStringList();
    /*
    for (auto value : values){
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
        //valuesList.QStringList();
        valuesList.append(QString());
    }
    qDebug() <<"valueslist1"<< valuesList<<"FILEHEADERSTRINGS "<<fileHeaderStrings;
    qDebug() <<"valuesList size" << valuesList.size();
    valuesList[0] = (QString("%1").arg(QDateTime::currentMSecsSinceEpoch()));
    qDebug() << "after insert timestamp";
    for (auto value : values){
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        qDebug() << "insert " << value.value << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value.value);
    }
    /*for (auto value1 : values){
        QString fileHeader = QString(value1.name+"["+deviceName+"]");
        qDebug() << "insert " << value1.value1 << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value1.value1);
    }
    */
    if (valuesList[1]!="")
    {
        x=valuesList[1];
        qDebug()<<x<<"x";
    }
    if (valuesList[2]!="")
    {
        y=valuesList[2];
        qDebug()<<y<<"y";
    }

    qDebug()<< "valuelist2";
    qDebug() << "after filling valuesList";
    valuesList[1]=QString("%1").arg(x);
    valuesList[2]=QString("%1").arg(y);
    qDebug() << valuesList;
    valueLineListMap.insert(number, valuesList);

    qDebug()<<"valuelinelistmap" <<valueLineListMap;
    if (number > lastWrittenLine + bufferedLines || number < lastWrittenLine){
        qDebug()<<"testbuffer";
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
