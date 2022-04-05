#ifndef CPOSITION_H
#define CPOSITION_H

#include <QObject>
#include <QTextStream>
#include <QDebug>
#include <QRegularExpression>

class CPosition : public QObject
{
    Q_OBJECT
    private:
        double xPos, yPos, zPos;
    public:
        CPosition();
        ~CPosition();
        CPosition(double _x, double _y, double _z);
        CPosition(CPosition const& _position);

        double getXpos() const;
        double getYpos() const;
        double getZpos() const;
        void setXpos(double _xPos);
        void setYpos(double _yPos);
        void setZpos(double _zPos);
        
        CPosition const& operator+(CPosition const &other);
        CPosition const& operator-(CPosition const &other);
        CPosition const& operator=(CPosition const &other);
        static unsigned int qByteArrayToPosition(const QByteArray _position, CPosition * result);
        static QByteArray positionToQByteArray(const CPosition _position);
        static unsigned int qStringToPosition(const QString _position, CPosition * result);
        static QString positionToQString(const CPosition _position);
        void displayPosition();

};

#endif //CPOSITION_H
