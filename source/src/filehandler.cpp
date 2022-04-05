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
        qDebug() << outputFile->fileName();
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
     QStringList valuesList;
    
    

    for (auto value : values){
        if(value.name=="I")
        qDebug() <<value.name << value.value;
    }
    for (auto value1 : values){
        qDebug() << value1.name << value1.value1;
        if(value1.name=="I")
        {wert=value1.value1;
        //device=value1.name;
        qDebug()<<"wert"<<wert;}

    }
    if (outputFile.isNull()){
        return;
    }
    if (deviceName==""||values.empty()){
        return;
    }

   
    //valuesList=new QStringList();
   
    /*for (auto value : values){
        valuesList.append(QString(value.name+"["+deviceName+"]:%1").arg(value.value));
    }
    */
 
    qDebug() << "size:";
    for (auto value : values){
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        if (!fileHeaderStrings.contains(fileHeader)){
            fileHeaderStrings.append(fileHeader);
            correct_columns();
        }
    }
    for (auto value1 : values){
        if(value1.name=="C,x"){
        //value1.name="Q";
        qDebug()<<value1.name<<"value1.name";
        value1.name="D";
        QString fileHeader = QString(value1.name+"["+deviceName+"]");
        if (!fileHeaderStrings.contains(fileHeader)){
            fileHeaderStrings.append(fileHeader);
            correct_columns();
        }
        }
        else if (value1.name=="ZTD"){
        qDebug()<<value1.name<<"value1.name";
        value1.name="D";
        qDebug()<<value1.name<<"value1.name";
        QString fileHeader = QString(value1.name+"["+deviceName+"]");
        if (!fileHeaderStrings.contains(fileHeader)){
            fileHeaderStrings.append(fileHeader);
            correct_columns();
        }
        }
    }
    for (int i = 0; i < fileHeaderStrings.size(); i++){
        // make sure size of the values list and fileHeaderStrings are same size
        // so no seg fault occurs
        //valuesList.QStringList();
        valuesList.append(QString());
        //valuesList.append(fileHeaderStrings);
    }
    qDebug() <<"valueslist1:"<< valuesList<<"FILEHEADERSTRINGS: "<<fileHeaderStrings;
    //valuesList[0] =(QString("%1").arg(fileHeaderStrings[0]));
    valuesList[0] = (QString("%1").arg(QDateTime::currentMSecsSinceEpoch()));
    qDebug() << "after insert timestamp";
    for (auto value : values)
    {
        if(value.name=="I" && deviceName=="2410")
        {
        QString fileHeader = QString(value.name+"["+deviceName+"]");
        qDebug() << "insert: " << wert << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(wert);
        }
        else{
                QString fileHeader = QString(value.name+"["+deviceName+"]");
                qDebug() << "insert: " << value.value << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
                valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value.value);
            }
    }
    for (auto value1 : values){
        //value1.name="Q";
        QString fileHeader = QString(value1.name+"["+deviceName+"]"); 
        if (value1.name=="C,x")
        {   value1.name="D";
            QString fileHeader = QString(value1.name+"["+deviceName+"]");
            value1.name="D"; 
        qDebug() <<fileHeader;
        qDebug() << "insert D" << value1.value1 << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value1.value1);
        }
        else if (value1.name=="ZTD")
        {   value1.name="D";
            QString fileHeader = QString(value1.name+"["+deviceName+"]");
            value1.name="D"; 
        qDebug() <<fileHeader;
        qDebug() << "insert D" << value1.value1 << " at "<<(fileHeaderStrings.indexOf(fileHeader));//index of filehandler ist c,q, stop bit?
        valuesList[(fileHeaderStrings.indexOf(fileHeader))] = QString("%1").arg(value1.value1); 
        }
    }
/*valuesList will be created for every step for each device, Keithley has 2 values, sourcetronic 3. The second valueslist will overwrite der first
so the 1. will be saved if its not "" and added in the 2. list. Size make sure that number of elements fit to valueslist. */
    if (valuesList[1]!="")
    {
        x=valuesList[1];
    }
    if (valuesList.size()>2 && valuesList[2]!="")
    {
        y=valuesList[2];
    }
    if (valuesList.size()>3 && valuesList[3]!="")
    {
        z=valuesList[3];
    }
    if (valuesList.size()>4 && valuesList[4]!="")
    {
        a=valuesList[4];
    }
    qDebug() << "after filling valuesList:";
    valuesList[1]=QString("%1").arg(x);//adding 1. valueslist to 2.
    if(valuesList.size()>2){
    valuesList[2]=QString("%1").arg(y);
    }
    if(valuesList.size()>3){
    valuesList[3]=QString("%1").arg(z);
    }
    if(valuesList.size()>4){
    valuesList[4]=QString("%1").arg(a);
    }
   
    
    
    qDebug()<<"fileheader strings"<<fileHeaderStrings;
    valueLineListMap.insert(0, fileHeaderStrings);//header in position0
    fileHeaderStrings.empty();//later implemented
    //valueLineListMap.insert(0, fileHeaderStrings.replaceInStrings(" ",""));
    valueLineListMap.insert(number, valuesList);
    //qDebug()<<"valuelinelistmap: " <<valueLineListMap;
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
        valueLineListMap.clear();//elements of valueLineListMap deleted
        fileHeaderStrings.clear();
    fileHeaderStrings.append("time");
    qDebug()<<"test";
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
