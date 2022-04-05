#ifndef CPOSITIONVISUXY_H
#define CPOSITIONVISUXY_H

#include "CPosition.h"

#include <QObject>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QtGlobal>
#include <QGridLayout>

#define LABEL_POSNAME_X 25
#define LABEL_POSNAME_Y 100
#define LABEL_POSNAME_WIDTH_XY 100
#define LABEL_POSNAME_HEIGHT_XY 20

#define TEXTEDIT_SM_WIDTH 80
#define TEXTEDIT_SM_HEIGHT 30

#define TEXTEDIT_SPACE_X 10
#define TEXTEDIT_SPACE_Y 10

class CPositionVisuXY : public QFrame
{
    Q_OBJECT

private:
    QGridLayout m_gridLayout;
    QLabel * m_label_Name;
    QTextEdit * m_textEdit_xPos;
    QTextEdit * m_textEdit_yPos;
    bool m_readOnly = false;
public:
    explicit CPositionVisuXY(int _x, int _y, int _width, int _height, bool _readOnly, QWidget *parent = nullptr);
    QLabel * getLabel(void);
    QTextEdit * getTextEditX(void);
    QTextEdit * getTextEditY(void);
    CPosition readPositionsFromTextEdits(void);
    void setObjectname(QString _objectname);

private slots:
    void on_inputPositionChanged(void);
public slots:
    void on_writePositionToTextEdit(CPosition _position);
    //void on_StylesheetChanged(QString _stylesheet);
signals:
    void positionChanged(QString _labelName,CPosition _newPosition);
    void warning(QString _windowTitle, QString _windowText);

};

#endif // CPOSITIONVISUXY_H
