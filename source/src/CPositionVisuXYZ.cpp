#include "CPositionVisuXYZ.h"
#include <QDebug>

CPositionVisuXYZ::CPositionVisuXYZ(int _x, int _y, int _width, int _height, bool _readOnly, QWidget *parent)
    : QWidget{parent}
{

    this->setGeometry(_x, _y, _width, _height);

    // Position name
    m_label_Name = new QLabel(parent);
    m_label_Name->setText("Position");
    m_label_Name->setGeometry(_x,_y,LABEL_POSNAME_WIDTH_XYZ,LABEL_POSNAME_HEIGHT_XYZ);
    m_gridLayout.addWidget(m_label_Name, 0,0,Qt::AlignCenter);
    m_label_Name->setMinimumWidth(LABEL_POSNAME_WIDTH_XYZ);
    
    // text edit descriptions
    m_label_xpos.setText("x value");
    m_label_ypos.setText("y value");
    m_label_zpos.setText("z value");

    m_gridLayout.addWidget(&m_label_xpos,1,0, Qt::AlignLeft);
    m_gridLayout.addWidget(&m_label_ypos,1,1, Qt::AlignLeft);
    m_gridLayout.addWidget(&m_label_zpos,1,2, Qt::AlignLeft);

    m_textEdit_xPos = new QTextEdit(parent);
    m_textEdit_xPos->setGeometry(_x,_y + TEXTEDIT_SPACE_Y + LABEL_POSNAME_HEIGHT_XYZ, TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT);
    m_textEdit_xPos->setMaximumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_xPos->setMinimumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_xPos->setText("0.0");
    m_gridLayout.addWidget(m_textEdit_xPos, 2,0, Qt::AlignLeft);

    m_textEdit_yPos = new QTextEdit(parent);
    m_textEdit_yPos->setGeometry(_x + TEXTEDIT_SM_WIDTH + TEXTEDIT_SPACE_X,_y + TEXTEDIT_SPACE_Y + LABEL_POSNAME_HEIGHT_XYZ, TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT);
    m_textEdit_yPos->setMaximumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_yPos->setMinimumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_yPos->setText("0.0");
    m_gridLayout.addWidget(m_textEdit_yPos, 2,1, Qt::AlignLeft);

    m_textEdit_zPos = new QTextEdit(parent);
    m_textEdit_zPos->setGeometry(_x + TEXTEDIT_SM_WIDTH*2 + TEXTEDIT_SPACE_X*2, _y + TEXTEDIT_SPACE_Y + LABEL_POSNAME_HEIGHT_XYZ, TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT);
    m_textEdit_zPos->setMaximumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_zPos->setMinimumSize(QSize(TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT));
    m_textEdit_zPos->setText("0.0");
    m_gridLayout.addWidget(m_textEdit_zPos, 2,2,Qt::AlignLeft);

    // insert space
    m_gridLayout.setHorizontalSpacing(20);

    

    m_readOnly = _readOnly;
    m_textEdit_xPos->setReadOnly(m_readOnly);
    m_textEdit_yPos->setReadOnly(m_readOnly);
    m_textEdit_zPos->setReadOnly(m_readOnly);

    // connect
    // members >> this
    connect(m_textEdit_xPos, &QTextEdit::textChanged, this, &CPositionVisuXYZ::on_inputPositionChanged);
    connect(m_textEdit_yPos, &QTextEdit::textChanged, this, &CPositionVisuXYZ::on_inputPositionChanged);
    connect(m_textEdit_zPos, &QTextEdit::textChanged, this, &CPositionVisuXYZ::on_inputPositionChanged);
    this->setLayout(&m_gridLayout);
}


QLabel * CPositionVisuXYZ::getLabel(void)
{
   return m_label_Name;
}

QTextEdit * CPositionVisuXYZ::getTextEditX(void)
{
    return m_textEdit_xPos;
}

QTextEdit * CPositionVisuXYZ::getTextEditY(void)
{
    return m_textEdit_yPos;
}

QTextEdit * CPositionVisuXYZ::getTextEditZ(void)
{
    return m_textEdit_zPos;
}

CPosition CPositionVisuXYZ::readPositionsFromTextEdits(void)
{
    CPosition input(0,0,0);

    QString allowedChars = "-0123456789.";
    QString xPos = m_textEdit_xPos->toPlainText();
    QString yPos = m_textEdit_yPos->toPlainText();
    QString zPos = m_textEdit_zPos->toPlainText();

    int xSize = xPos.size();
    int ySize = yPos.size();
    int zSize = zPos.size();

    if(!xPos.isEmpty()){
        for(int i = 0; i < xSize; i++){
            if(!allowedChars.contains(xPos.at(i)))
            {
                emit warning("Warning", "Invalid input for position");
                return CPosition(qInf(),qInf(),qInf());
            }
        }
        input.setXpos(xPos.toDouble());
    }

    if(!yPos.isEmpty()){
        for(int i = 0; i < ySize; i++){
            if(!allowedChars.contains(yPos.at(i)))
            {
                emit warning("Warning", "Invalid input for position");
                return CPosition(qInf(),qInf(),qInf());
            }
        }
        input.setYpos(yPos.toDouble());
    }

    if(!zPos.isEmpty()){
        for(int i = 0; i < zSize; i++){
            if(!allowedChars.contains(zPos.at(i)))
            {
                emit warning("Warning", "Invalid input for position");
                return CPosition(qInf(),qInf(),qInf());
            }
        }
        input.setZpos(zPos.toDouble());
    }

    return input;
}

void CPositionVisuXYZ::on_writePositionToTextEdit(CPosition _position)
{
    if(m_readOnly)
    {
        m_textEdit_xPos->setReadOnly(false);
        m_textEdit_yPos->setReadOnly(false);
        m_textEdit_zPos->setReadOnly(false);

        m_textEdit_xPos->setText(QString::number(_position.getXpos()));
        m_textEdit_yPos->setText(QString::number(_position.getYpos()));
        m_textEdit_zPos->setText(QString::number(_position.getZpos()));

        m_textEdit_xPos->setReadOnly(true);
        m_textEdit_yPos->setReadOnly(true);
        m_textEdit_zPos->setReadOnly(true);
    }else{
        m_textEdit_xPos->setText(QString::number(_position.getXpos()));
        m_textEdit_yPos->setText(QString::number(_position.getYpos()));
        m_textEdit_zPos->setText(QString::number(_position.getZpos()));
    }
}

 void CPositionVisuXYZ::on_inputPositionChanged(void)
 {
    emit positionChanged(m_label_Name->objectName(), readPositionsFromTextEdits());
 }

/*void CPositionVisuXYZ::on_StylesheetChanged(QString _stylesheet)
{
    this->setStyleSheet(_stylesheet);
}*/

