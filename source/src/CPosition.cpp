#include <CPosition.h>


CPosition::CPosition()
    :QObject()
{
    xPos = 0;
    yPos = 0;
    zPos = 0;
}

CPosition::CPosition( double _xPos, double _yPos, double _zPos)
    :QObject()
{
    xPos = _xPos;
    yPos = _yPos;
    zPos = _zPos;
}

CPosition::CPosition(CPosition const& _position)
    :QObject()
{
    this->xPos = _position.getXpos();
    this->yPos = _position.getYpos();
    this->zPos = _position.getZpos();

}

CPosition::~CPosition()
{
    
}

double CPosition::getXpos() const
{
    return xPos;
}

double CPosition::getYpos() const
{
    return yPos;
}

double CPosition::getZpos() const
{
    return zPos;
}

void CPosition::setXpos(double _xPos)
{
    xPos = _xPos;
}

void CPosition::setYpos(double _yPos)
{
    yPos = _yPos;
}

void CPosition::setZpos(double _zPos)
{
    zPos = _zPos;
}

CPosition const& CPosition::operator+(CPosition const &other)
{
    CPosition *result = new CPosition;
    result->setXpos(xPos + other.xPos);
    result->setYpos(yPos + other.yPos);
    result->setZpos(zPos + other.zPos);
    return *result;
}

CPosition const& CPosition::operator-(CPosition const &other)
{
   CPosition *result = new CPosition;
   result->xPos = xPos - other.xPos;
   result->yPos = yPos - other.yPos;
   result->zPos = zPos - other.zPos;
   return *result;

}

CPosition const& CPosition::operator=(CPosition const &other)
{

    xPos = other.xPos;
    yPos = other.yPos;
    zPos = other.zPos;
    return *this;
}

unsigned int CPosition::qByteArrayToPosition(const QByteArray _position, CPosition * result)
{
    QString strPosition;
    strPosition = QString::fromUtf8(_position);;
    QString allowedChars = ": -0123456789.\r";
    int a = _position.size(), b = 0, c = 0;
    int n[3] = {};
    const QChar space = ' ';
    const QChar dot = '.';
    const QChar colon = ':';
    // loop for check every character within QString
    int j = 0;
    for(int i = 0; i < strPosition.size(); i++)
    {
        if(allowedChars.contains(strPosition.at(i)))
        {
         // data is after :
         if(strPosition.at(i) == colon)
         {
             a = i+1;
         }

         if(i>=a && ( strPosition.at(i).isDigit()
                 || strPosition.at(i) == dot))
         {
             n[j]++;
         }

         if(strPosition.at(i) == space)
             j++;
        }else{
            return 1;
        }
    }

    // extract positions
    QString xPos = strPosition.mid(a,n[0]);
    QString yPos = strPosition.mid(a+n[0]+1,n[1]);
    QString zPos = strPosition.mid(a+n[0]+n[1]+2, n[2]);

    result->setXpos(xPos.toDouble());
    result->setYpos(yPos.toDouble());
    result->setZpos(zPos.toDouble());

    return 0;

}

QByteArray CPosition::positionToQByteArray(const CPosition _position)
{
    QString strResult;
    QString xPos, yPos, zPos;

    xPos = QString::number(_position.getXpos());
    yPos = QString::number(_position.getYpos());
    zPos = QString::number(_position.getZpos());
    strResult = xPos + " " + yPos + " " + zPos;
    return strResult.toUtf8(); // converts QSTring to QByteArray
}

unsigned int CPosition::qStringToPosition(const QString _position, CPosition * result)
{
    QString strPosition;
    QString allowedChars = ": -0123456789.\r";
    strPosition = _position;
    int a = _position.size(), b = 0, c = 0;
    int n[3] = {};
    QChar space = ' ';
    const QChar dot = '.';
    const QChar colon = ':';
    QString xPos;
    QString yPos;
    QString zPos;
    //QChar space = " ";
    // loop for check every character within QString if size bigger than 3 "0:\r" is shortest message
   /* if(strPosition.size() > 3)
    {
        int j = 0;
        for(int i = 0; i < strPosition.size(); i++)
        {
            if(allowedChars.contains(strPosition.at(i)))
            {
                // data is after :
                if(strPosition.at(i) == colon)
                {
                    a = i+1;
                }

                if(i>=a && ( strPosition.at(i).isDigit()
                        || strPosition.at(i) == dot
                        || strPosition.at(i) == '-'))
                {
                    n[j]++;
                }// any other char causes error and return

                if(strPosition.at(i) == space )
                    j++;
            }else{
                return 1;
            }
        }

        // extract positions
        if((a+n[0]) < strPosition.size())
        {
            xPos = strPosition.mid(a,n[0]);
        }
        if((a+n[0]) < strPosition.size())
        {
            yPos = strPosition.mid(a+n[0]+1,n[1]);
        }
        if((a+n[0]) < strPosition.size())
        {
            zPos = strPosition.mid(a+n[0]+n[1]+2, n[2]);
        }
    }*/

    // test QRegularExpression
    QRegularExpression r1("[: -](\\d+).(\\d)");
   //QRegularExpression r2(":-(\\d+).(\\d)");
   //QRegularExpression r3(" -(\\d+).(\\d)");
   // QRegularExpression r4(" (\\d+).(\\d)");

    QList<int> list;
    // find x value
    QRegularExpressionMatchIterator i = r1.globalMatch(strPosition);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString word = match.captured(1);
        int capturedStart = match.capturedStart();
        if(strPosition.at(capturedStart) == "-")
        {
            word.insert(0,"-");
        }
        if(list.size() <=3)
        {
            list << word.toInt();
        }
        
    }

   // QRegularExpressionMatchIterator j = r2.globalMatch(strPosition);
   // while (j.hasNext()) {
   //     QRegularExpressionMatch match = j.next();
   //     QString word = match.captured(1);
   //     
   //     if(list.size() <=3)
   //     {
   //         list << word.toInt();
   //     }
   // }
//
   // // patterns for y and z values
   // QRegularExpressionMatchIterator k = r3.globalMatch(strPosition);
   // while (k.hasNext()) {
   //     QRegularExpressionMatch match = k.next();
   //     QString word = match.captured(1);
   //     word.insert(0,"-");
   //     int capturedPos = match.capturedStart();
   //     list << word.toInt();
   // }
//

    qDebug()<<list;
    


    if(list.size()< 3)
    {
        return 2; // positions cannot be empty
    }else{
        result->setXpos((double)list.at(0));
        result->setYpos((double)list.at(1));
        result->setZpos((double)list.at(2));
    }
    return 0;

}

QString CPosition::positionToQString(const CPosition _position)
{
    QString strResult;
    QString xPos, yPos, zPos;

    xPos = QString::number(_position.getXpos());
    yPos = QString::number(_position.getYpos());
    zPos = QString::number(_position.getZpos());
    strResult = xPos + " " + yPos + " " + zPos;
    return strResult;
}


void CPosition::displayPosition()
{
  qDebug() << qSetRealNumberPrecision(10) << "x= " << this->xPos << "; "  << "y= " << this->yPos << "; " << "z= " << this->zPos << ";";
}

