#ifndef CPOSITIONVISUXYZ_H
#define CPOSITIONVISUXYZ_H

#include <CPosition.h>

#include <QObject>
#include <QLabel>
#include <QTextEdit>
#include <QGroupBox>
#include <QtGlobal>
#include <QGridLayout>

#define LABEL_POSNAME_X 25
#define LABEL_POSNAME_Y 100
#define LABEL_POSNAME_WIDTH_XYZ 170
#define LABEL_POSNAME_HEIGHT_XYZ 20

#define TEXTEDIT_SM_WIDTH 80
#define TEXTEDIT_SM_HEIGHT 30

#define TEXTEDIT_SPACE_X 10
#define TEXTEDIT_SPACE_Y 10

class CPositionVisuXYZ : public QWidget
{
    Q_OBJECT

private:
    QGridLayout m_gridLayout;
    QLabel * m_label_Name;
    QLabel m_label_xpos;
    QLabel m_label_ypos;
    QLabel m_label_zpos;
    QTextEdit * m_textEdit_xPos;
    QTextEdit * m_textEdit_yPos;
    QTextEdit * m_textEdit_zPos;
    bool m_readOnly = false;
public:
    explicit CPositionVisuXYZ(int _x, int _y, int _width, int _height, bool _readOnly, QWidget *parent = nullptr);
    QLabel * getLabel(void);
    QTextEdit * getTextEditX(void);
    QTextEdit * getTextEditY(void);
    QTextEdit * getTextEditZ(void);
    CPosition readPositionsFromTextEdits(void);


private slots:
    void on_inputPositionChanged(void);
public slots:
    void on_writePositionToTextEdit(CPosition _position);

signals:
    void positionChanged(QString _labelName,CPosition _newPosition);
    void warning(QString _windowTitle, QString _windowText);

};

#endif // CPOSITIONVISUXYZ_H
