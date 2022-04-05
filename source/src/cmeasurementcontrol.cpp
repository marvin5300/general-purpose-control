#include "cmeasurementcontrol.h"


CMeasurementControl::CMeasurementControl(CProberSystem * _ptrProber,  QLabel * _ptrLabel_ActState, QPushButton * _ptrPushButton_GoOn)
{
    // inits
    m_ptrProber = _ptrProber;
    m_ptrlabel_ActState = _ptrLabel_ActState;
    m_ptrPushButton_GoOn = _ptrPushButton_GoOn;
    m_row = 0;
    m_column = 0;
    m_dateTime = QDateTime::currentDateTime();
    m_offdelay.setSingleShot(true);
    m_offdelay.setInterval(3000); // in ms

   /* positionVisu_00->getTextEditX()->setText("45000.0");
    positionVisu_00->getTextEditY()->setText("-10000.0");

    positionVisu_01->getTextEditX()->setText("0.0");
    positionVisu_01->getTextEditY()->setText("-10000.0");

    positionVisu_02->getTextEditX()->setText("-48000.0");
    positionVisu_02->getTextEditY()->setText("-10000.0");

    positionVisu_10->getTextEditX()->setText("45000.0");
    positionVisu_10->getTextEditY()->setText("-27000.0");

    positionVisu_11->getTextEditX()->setText("0.0");
    positionVisu_11->getTextEditY()->setText("-27000.0");

    positionVisu_12->getTextEditX()->setText("48000.0");
    positionVisu_12->getTextEditY()->setText("-27000.0");

    positionVisu_20->getTextEditX()->setText("45000.0");
    positionVisu_20->getTextEditY()->setText("37000.0");

    positionVisu_21->getTextEditX()->setText("0.0");
    positionVisu_21->getTextEditY()->setText("37000.0");

    positionVisu_22->getTextEditX()->setText("-48000.0");
    positionVisu_22->getTextEditY()->setText("37000.0");*/


    
    m_zPreValue = -11000.0;
    m_zFinalValue = -5000.0;
    QList<CPosition> row0 = {CPosition(48000.0,9000.0,0), CPosition(48000.0,-51000.0,0), CPosition(48000.0,-111000.0,0)};
    QList<CPosition> row1 = {CPosition(13000.0,9000.0,0), CPosition(13000.0,-51000.0,0), CPosition(13000.0,-111000.0,0)};
    QList<CPosition> row2 = {CPosition(-22000.0,9000.0,0), CPosition(-22000.0,-51000.0,0), CPosition(-22000.0,-111000.0,0)};
   
    m_postionTable.append(row0);
    m_postionTable.append(row1);
    m_postionTable.append(row2);
   
    
    // create states
    m_s1 = new QState();                // move chuck to pre measurement position Z
    m_s2 = new QState();                // move chuck to pre measurement position XY
    m_s3 = new QState();                // move chuck to final measurement position
    m_s4 = new QState();                // measure
    m_s5 = new QState();                // check if measurement finished
    m_finalState = new QFinalState();   // measurement sequence finished

    // set state names
    m_s1->setObjectName("move to pre-measurement Z position");
    m_s2->setObjectName("move to pre-measurement XY position");
    m_s3->setObjectName("move to final measurement position");
    m_s4->setObjectName("measure parameter");
    m_s5->setObjectName("check measurement");


    // add states to state machine
    m_machine.addState(m_s1);
    m_machine.addState(m_s2);
    m_machine.addState(m_s3);
    m_machine.addState(m_s4);
    m_machine.addState(m_s5);
    m_machine.addState(m_finalState);

    // set initial state
    m_machine.setInitialState(m_s1);

    // set transistions

    m_s1->addTransition(m_ptrProber, &CProberSystem::inZPosition, m_s2);
    m_s2->addTransition(m_ptrProber, &CProberSystem::inXYPosition, m_s3);
    m_s3->addTransition(m_ptrProber, &CProberSystem::inZPosition, m_s4);
   // m_s4->addTransition(m_ptrPushButton_GoOn, &QPushButton::clicked, m_s5); // TODO: replace with measurement done
    m_s4->addTransition(&m_offdelay, &QTimer::timeout, m_s5); 
    m_s5->addTransition(this, &CMeasurementControl::continueMeasurement, m_s1);
    m_s5->addTransition(this, &CMeasurementControl::finishMeasurement, m_finalState);
    // change act state label
    m_s1->assignProperty(m_ptrlabel_ActState, "text", "act. state: s1 move to pre Z value");
    m_s2->assignProperty(m_ptrlabel_ActState, "text", "act. state: s2 move XY");
    m_s3->assignProperty(m_ptrlabel_ActState, "text", "act. state: s3 move to final Z value");
    m_s4->assignProperty(m_ptrlabel_ActState, "text", "act. state: s4 wait for measurement done");
    m_s5->assignProperty(m_ptrlabel_ActState, "text", "act. state: s5 check measurement state");

    // set states
    m_s1->assignProperty(&m_machine, "state", STATE_MOVECHUCK_Z);
    m_s2->assignProperty(&m_machine, "state", STATE_MOVECHUCK_XY);
    m_s3->assignProperty(&m_machine, "state", STATE_MOVECHUCK_FINALPOS);
    m_s4->assignProperty(&m_machine, "state", STATE_MEASURING);
    m_s5->assignProperty(&m_machine, "state", STATE_CHECK_MEASUREMENT);

    // connect signals&slots for actions in states
    connect(&m_machine,&QStateMachine::started,this, &CMeasurementControl::on_machineStarted);      // request pre measurement Z values from gui
    connect(m_s1, &QState::entered, this, &CMeasurementControl::on_moveToPrePosition);
    connect(m_s2, &QState::entered, this, &CMeasurementControl::on_moveToPrePosition);
    connect(m_s3, &QState::entered, this, &CMeasurementControl::on_moveToMeasurePosition);
    connect(m_s4, &QState::entered, this, &CMeasurementControl::on_startMeasurement);                  // signal to signal connection
    connect(m_s5, &QState::entered, this, &CMeasurementControl::on_checkMeasurementStatus);         // check measurement status in s4

    connect(m_s2, &QState::exited, this, &CMeasurementControl::on_s2Exited);                        // request final measurement Z values from gui
    connect(m_s1, &QState::entered, this, &CMeasurementControl::requestInZPosition);
    connect(m_s2, &QState::entered, this, &CMeasurementControl::requestInXYPosition);
    connect(m_s3, &QState::exited, this, &CMeasurementControl::on_s3Exited);

    connect(&m_machine, &QStateMachine::runningChanged, this, &CMeasurementControl::on_runningChanged);
    connect(m_finalState, &QFinalState::entered, this, &CMeasurementControl::on_stateMachineFinished);
   // connect(this, &CMeasurementControl::measurementFinished, this, &CMeasurementControl::on_measuremenFinished);
    


}

 CMeasurementControl::~CMeasurementControl()
{

}

 void CMeasurementControl::setProber(CProberSystem * _ptrProber)
 {
     m_ptrProber = _ptrProber;
 }

 void CMeasurementControl::setMeasurementDevice(CMeasurementDevice * _ptrMeasDev)
 {
     m_ptrMeasDev = _ptrMeasDev;
 }

void CMeasurementControl::setActStateLabel(QLabel * _ptrLabel)
{
    m_ptrlabel_ActState = _ptrLabel;

}

void CMeasurementControl::setGoOnButton(QPushButton * _ptrPushButton)
{
    m_ptrPushButton_GoOn = _ptrPushButton;
    m_s4->addTransition(m_ptrPushButton_GoOn, &QPushButton::clicked, m_s5); // TODO: replace with measurement done

}

//void CMeasurementControl::setPositions(QList<QList<CPosition>> _positions)
//{
//    m_positions = _positions;
//}

const QStateMachine * const CMeasurementControl::getStateMachine(void)
{
    return &m_machine;
}

void CMeasurementControl::setThreads(QThread * _consumer, QThread * _producer)
{
    m_consumer = _consumer;
    m_producer = _producer;
}

void CMeasurementControl::setChuckVelocity(QString _velocity)
{
    m_chuckZVelocity = _velocity;
}
// private  slots
 void CMeasurementControl::on_increaseRow(void)
{
    m_row++;
}

void CMeasurementControl::on_moveToPrePosition(void)
{
    CPosition pos;

    if(m_machine.property("state") == STATE_MOVECHUCK_Z){
                        emit requestMoveChuckZ(m_zPreValue,"H", "Y", m_chuckZVelocity);
    }else if(m_machine.property("state") == STATE_MOVECHUCK_XY)
    {
        pos = m_postionTable.value(m_row).value(m_column);
        emit requestMoveChuckXY(pos.getXpos(), pos.getYpos(), "H", "Y", m_chuckXYVelocity);
    }

    

}

void CMeasurementControl::on_moveToMeasurePosition(void)
{
    emit requestMoveChuckZ(m_zFinalValue,"H", "Y", m_chuckZVelocity);
}

void CMeasurementControl::on_startMeasurement(void)
{
    // calc file name
    m_dateTime = QDateTime::currentDateTime(); // read 
    QString notallowedChars  = "\\:/*?<>|";
    int slotNumber = (m_row)*3 + m_column+1;
    QString fileName = m_dateTime.toString() + "Cxss" + QString::number(slotNumber) + "_" + m_paramNamInFile + ".txt";
    //QString fileName = m_paramNamInFile + ".txt";
    for(int i = 0; i<fileName.size();i++)
    {
        if(notallowedChars.contains(fileName.at(i)))
        {
            fileName.replace(i,1,'_');
        }

    }

    fileName = "/home/pi/Documents/Prober/" + fileName;
    emit createFile(fileName);
    emit startMeasurement();
}

void CMeasurementControl::on_checkMeasurementStatus(void){

    if(m_row == (ROWS - 1)
            && m_column == (COLUMNS - 1))
    {
        emit requestMoveChuckZ(m_zPreValue, "H", "Y", m_chuckZVelocity);
        emit finishMeasurement();
    }else if(m_row <= ROWS
             && m_column <= COLUMNS)
    {
        m_column++;
        m_column = m_column%COLUMNS;
        if(m_column == 0)
        {
            on_increaseRow();
        }
        emit continueMeasurement(); // continue with m_s1 but on the next DUT
    }
    emit measurePositionChanged(m_row, m_column);
}

void CMeasurementControl::on_timeoutCycReadPos(void)
{
    emit requestReadChuckPos();
}

void CMeasurementControl::on_machineStarted(void)
{
    emit measurePositionChanged(m_row, m_column);
}

void CMeasurementControl::on_s2Exited(void)
{
    ;
}

void CMeasurementControl::on_s3Exited(void)
{
    ;
}



void CMeasurementControl::on_stateMachineFinished(void)
{
    emit informationPopUp("Information", "Statemachine is finished");

}

// public slots
 void CMeasurementControl::on_startStateMachine(void)
 {
     m_row = 0;
     m_column = 0;
   if(!m_ptrProber->getSerialPort()->portName().isEmpty())
   {
     // start threads for synch comm
     if(!m_consumer->isRunning())
     {
         m_consumer->start();
     }
     if(!m_producer->isRunning())
     {
         m_producer->start();
     }
     if(!m_ptrProber->isCycPosReadActive())
     {
         m_ptrProber->startCyclPosRead();
     }
     // start state machine
     m_machine.start();
     qDebug() << "state machine started";
   }else{
       emit warning("Warning", "No Port for ProberSystem selected");
    }
 }

void CMeasurementControl::on_stopStateMachine(void)
{
    if(m_ongoingMeasurement)
    {
        emit stopMeasurement();
    }
    m_machine.stop();
    if(m_ptrProber->isCycPosReadActive())
    {
        m_ptrProber->stopCycPosRead();
    }
    if(m_producer->isRunning())
    {
        m_producer->exit();
        m_producer->wait();
    }
    if(m_consumer->isRunning())
    {
        m_consumer->exit();
        m_consumer->wait();
    }
}

void CMeasurementControl::on_runningChanged(bool _running)
{
    emit stateMachineRunningChanged(_running);
}

void CMeasurementControl::on_parameterNameChanged(QString _parameterName)
{
    m_paramNamInFile = _parameterName;
}

void CMeasurementControl::on_zValuePrePosChanged(double _zValue)
{
    m_zPreValue = _zValue;
}

void CMeasurementControl::on_zValueFinalPosChanged(double _zValue)
{
    m_zFinalValue = _zValue;
}

void CMeasurementControl::on_positionChanged(int _row, int _column, CPosition _pos)
{
  /* switch(_row){
       case 0:
        m_row0.replace(_column,_pos);
        m_postionTable.replace(0,m_row0);
        break;
       case 1:
        m_row1.replace(_column,_pos);
        m_postionTable.replace(1,m_row1);
       break;
       case 2:
       m_row2.replace(_column,_pos);
       m_postionTable.replace(2,m_row2);
       break;
   }
  
    int len = m_postionTable.value(_row).size();*/
    m_postionTable[_row].replace(_column,_pos);
    m_postionTable.value(_row).value(_column).displayPosition();
}

void CMeasurementControl::on_requestMeasurementControlData(void)
{
    emit measurementControlData(m_postionTable, m_zPreValue, m_zFinalValue);
}

void CMeasurementControl::on_ongoingMeasurementChanged(bool _ongoingMeasurement)
{
    m_ongoingMeasurement = _ongoingMeasurement;
}

void CMeasurementControl::on_measurementFinished(void)
{
     m_offdelay.start();
}

     