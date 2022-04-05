#include <CPositionVisuXY.h>
#include <QDebug>

CPositionVisuXY::CPositionVisuXY(int _x, int _y, int _width, int _height, bool _readOnly, QWidget *parent)
    : QFrame{parent}
{

    this->setGeometry(_x, _y, _width, _height);

    
    m_textEdit_xPos = new QTextEdit(this);
    m_textEdit_xPos->setGeometry(_x,_y + TEXTEDIT_SPACE_Y + LABEL_POSNAME_HEIGHT_XY, TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT);
    m_textEdit_xPos->setText("0.0");
    m_gridLayout.addWidget(m_textEdit_xPos,1,0);

    m_textEdit_yPos = new QTextEdit(this);
    m_textEdit_yPos->setGeometry(_x + TEXTEDIT_SM_WIDTH + TEXTEDIT_SPACE_X,_y + TEXTEDIT_SPACE_Y + LABEL_POSNAME_HEIGHT_XY, TEXTEDIT_SM_WIDTH,TEXTEDIT_SM_HEIGHT);
    m_textEdit_yPos->setText("0.0");
    m_gridLayout.addWidget(m_textEdit_yPos,1,1);

    m_label_Name = new QLabel(this);
    m_label_Name->setText("Position");
    m_label_Name->setGeometry(_x,_y,LABEL_POSNAME_WIDTH_XY,LABEL_POSNAME_HEIGHT_XY);
    m_gridLayout.addWidget(m_label_Name,0,0);

    m_readOnly = _readOnly;
    m_textEdit_xPos->setReadOnly(m_readOnly);
    m_textEdit_yPos->setReadOnly(m_readOnly);


    // connect
    // members >> this
    connect(m_textEdit_xPos, &QTextEdit::textChanged, this, &CPositionVisuXY::on_inputPositionChanged);
    connect(m_textEdit_yPos, &QTextEdit::textChanged, this, &CPositionVisuXY::on_inputPositionChanged);
    this->setLayout(&m_gridLayout);

}


QLabel * CPositionVisuXY::getLabel(void)
{
   return m_label_Name;
}

QTextEdit * CPositionVisuXY::getTextEditX(void)
{
    return m_textEdit_xPos;
}

QTextEdit * CPositionVisuXY::getTextEditY(void)
{
    return m_textEdit_yPos;
}

CPosition CPositionVisuXY::readPositionsFromTextEdits(void)
{
    CPosition input(0,0,0);

    QString allowedChars = "-0123456789.";
    QString xPos = m_textEdit_xPos->toPlainText();
    QString yPos = m_textEdit_yPos->toPlainText();

    int xSize = xPos.size();
    int ySize = yPos.size();

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

    return input;
}

void CPositionVisuXY::on_writePositionToTextEdit(CPosition _position)
{
    if(m_readOnly)
    {
        m_textEdit_xPos->setReadOnly(false);
        m_textEdit_yPos->setReadOnly(false);


        m_textEdit_xPos->setText(QString::number(_position.getXpos()));
        m_textEdit_yPos->setText(QString::number(_position.getYpos()));


        m_textEdit_xPos->setReadOnly(true);
        m_textEdit_yPos->setReadOnly(true);

    }else{
        m_textEdit_xPos->setText(QString::number(_position.getXpos()));
        m_textEdit_yPos->setText(QString::number(_position.getYpos()));

    }
}

 void CPositionVisuXY::on_inputPositionChanged(void)
 {
    emit positionChanged(this->objectName(), readPositionsFromTextEdits());
 }
