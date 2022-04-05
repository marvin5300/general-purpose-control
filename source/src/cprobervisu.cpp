#include <cprobervisu.h>

CProberVisu::CProberVisu(QWidget * parent)
:QTabWidget(parent)
{

}


CProberVisu::CProberVisu(int _x, int _y, int _width, int _height, CProberSystem * _ptrProber, QWidget * parent)
    :QTabWidget(parent)
{

    m_ptrProber = _ptrProber;
    // set tab position and size
    this->setGeometry(_x, _y, _width, _height);
     page_ConnectionTest = new QWidget();
     page_ManualControl = new QWidget();
     page_StateMachine = new QWidget();
     page_Logger = new QWidget();

    // set tab texts
    this->addTab(page_ConnectionTest,"Connection");
    this->addTab(page_ManualControl,"Manual Control");
    this->addTab(page_StateMachine, "State Machine");
    this->addTab(page_Logger,"Logger");

    // PAGE_CONNECTION_BEGIN ---------------------------------------------------------------------------------------------------------
    // create widgets
    gridPageConnection = new QGridLayout();
    gridLayout_PortSettings = new QGridLayout();
    gridLayout_DeviceSearch = new QGridLayout();
    gridLayout_SendTextMsg = new QGridLayout();

    gb_portSettings = new QGroupBox();
    gb_deviceSearch = new QGroupBox();
    gb_textMessage = new QGroupBox();

    // comboboxes
    comboBox_BaudRate = new QComboBox(page_ConnectionTest);
    comboBox_Parity  = new QComboBox(page_ConnectionTest);
    comboBox_Databits = new QComboBox(page_ConnectionTest);
    comboBox_Stopbits = new QComboBox(page_ConnectionTest);
    comboBox_Flowcontrol = new QComboBox(page_ConnectionTest);


    comboBox_BaudRate->setGeometry(COMBOBOX_XPOS, LABEL_YTOP+YSPACE*1, COMBOBOX_WIDTH, COMBOBOX_HEIGHT);
    comboBox_Parity->setGeometry(COMBOBOX_XPOS, LABEL_YTOP+YSPACE*2, COMBOBOX_WIDTH, COMBOBOX_HEIGHT);
    comboBox_Databits->setGeometry(COMBOBOX_XPOS, LABEL_YTOP+YSPACE*3, COMBOBOX_WIDTH, COMBOBOX_HEIGHT);
    comboBox_Stopbits->setGeometry(COMBOBOX_XPOS, LABEL_YTOP+YSPACE*4, COMBOBOX_WIDTH, COMBOBOX_HEIGHT);
    comboBox_Flowcontrol->setGeometry(COMBOBOX_XPOS, LABEL_YTOP+YSPACE*5, COMBOBOX_WIDTH, COMBOBOX_HEIGHT);

    // set texts and defualt values
    comboBox_BaudRate->addItems(m_bauds);
    comboBox_BaudRate->setCurrentIndex(3);
    comboBox_Parity->addItems(m_parities);
    comboBox_Parity->setCurrentIndex(0);
    comboBox_Databits->addItems(m_databits);
    comboBox_Databits->setCurrentIndex(3);
    comboBox_Stopbits->addItems(m_stopbits);
    comboBox_Stopbits->setCurrentIndex(0);
    comboBox_Flowcontrol->addItems(m_flowControl);
    comboBox_Flowcontrol->setCurrentIndex(2);


    // lables
    label_PortSettings = new QLabel(page_ConnectionTest);
    label_BaudRate  = new QLabel(page_ConnectionTest);
    label_Parity  = new QLabel(page_ConnectionTest);
    label_Databits  = new QLabel(page_ConnectionTest);
    label_Stopbits  = new QLabel(page_ConnectionTest);
    label_Flowcontrol  = new QLabel(page_ConnectionTest);
    label_DeviceSearch = new QLabel(page_ConnectionTest);
    label_ConnectState = new QLabel(page_ConnectionTest);
    label_ConnectionMsg = new QLabel(page_ConnectionTest);
    label_SendTextMsg = new QLabel(page_ConnectionTest);

    // label texts
    label_PortSettings->setText("Port settings");
    label_BaudRate->setText("Baud rate");
    label_Parity->setText("Parity");
    label_Databits->setText("Databits");
    label_Stopbits->setText("Stopbits");
    label_Flowcontrol->setText("Flowcontrol");
    label_DeviceSearch->setText("Device Search");
    label_ConnectState->setText("Connect state");
    label_ConnectionMsg->setText("Not connected");
    label_SendTextMsg->setText("Send text message");

    // label geometry
    label_PortSettings->setGeometry(LABEL_XTOP,LABEL_YTOP,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_BaudRate->setGeometry(LABEL_XTOP,LABEL_YTOP+YSPACE,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_Parity->setGeometry(LABEL_XTOP,LABEL_YTOP+YSPACE*2,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_Databits->setGeometry(LABEL_XTOP,LABEL_YTOP+YSPACE*3,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_Stopbits->setGeometry(LABEL_XTOP,LABEL_YTOP+YSPACE*4,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_Flowcontrol->setGeometry(LABEL_XTOP,LABEL_YTOP+YSPACE*5,LABEL_WIDTH_1,LABEL_HEIGHT_1);

    label_DeviceSearch->setGeometry(DEVICESEARCH_XPOS,LABEL_YTOP,LABEL_WIDTH_1,LABEL_HEIGHT_1);
    label_ConnectState->setGeometry(DEVICESEARCH_XPOS,CONNECT_STATE_YPOS,PUSHBUTTON_WIDTH,LABEL_HEIGHT_1);
    label_ConnectionMsg->setGeometry(DEVICESEARCH_XPOS + PUSHBUTTON_WIDTH+PUSHBUTTON_XSPACE,CONNECT_STATE_YPOS,2*PUSHBUTTON_WIDTH+1*PUSHBUTTON_XSPACE,LABEL_HEIGHT_1);
    label_SendTextMsg->setGeometry(LABEL_XTOP, LABEL_SENDMSG_YPOS, LABEL_WIDTH_2, LABEL_HEIGHT_1);
    label_ConnectionMsg->setMinimumWidth(215);
    label_ConnectionMsg->setMaximumHeight(LABEL_HEIGHT_1);
    label_ConnectState->setMaximumHeight(LABEL_HEIGHT_1);
    //style sheets
    label_PortSettings->setStyleSheet("font: bold 14px");
    label_DeviceSearch->setStyleSheet("font: bold 14px");
    label_ConnectState->setStyleSheet("border: 1px solid black");
    label_ConnectionMsg->setStyleSheet("border: 1px solid black; background-color: red");
    label_SendTextMsg->setStyleSheet("font: bold 14px");

    // push buttons
    pushButton_Search = new QPushButton(page_ConnectionTest);
    pushButton_Connect = new QPushButton(page_ConnectionTest);
    pushButton_Disconnect = new QPushButton(page_ConnectionTest);
    pushButton_Send = new QPushButton(page_ConnectionTest);


    pushButton_Search->setText("Search");
    pushButton_Connect->setText("Connect");
    pushButton_Disconnect->setText("Disconnect");
    pushButton_Send->setText("Send");

    pushButton_Search->setGeometry(DEVICESEARCH_XPOS,LABEL_YTOP+YSPACE,PUSHBUTTON_WIDTH,PUSHBUTTON_HEIGHT);
    pushButton_Connect->setGeometry(DEVICESEARCH_XPOS+PUSHBUTTON_WIDTH*1+PUSHBUTTON_XSPACE*1,LABEL_YTOP+YSPACE,PUSHBUTTON_WIDTH,PUSHBUTTON_HEIGHT);
    pushButton_Disconnect->setGeometry(DEVICESEARCH_XPOS+PUSHBUTTON_WIDTH*2+PUSHBUTTON_XSPACE*2,LABEL_YTOP+YSPACE,PUSHBUTTON_WIDTH,PUSHBUTTON_HEIGHT);
    pushButton_Send->setGeometry(LABEL_XTOP, TEXTEDIT_SEND_YPOS + TEXTEDIT_SEND_HEIGHT + PUSHBUTTON_SEND_YSPACE, TEXTEDIT_SEND_WIDTH, PUSHBUTTON_HEIGHT);
    // table
    tableWidget_Devices = new QTableWidget(page_ConnectionTest);
    tableWidget_Devices->setMinimumSize(2,2);
    tableWidget_Devices->setRowCount(5);
    tableWidget_Devices->setColumnCount(3);
    tableWidget_Devices->setGeometry(DEVICESEARCH_XPOS, TABLE_YPOS, 5*PUSHBUTTON_WIDTH+2*PUSHBUTTON_XSPACE, TABLE_HEIGHT);
    tableWidget_Devices->setMinimumWidth(350); // valid in grid layout
    tableWidget_Devices->setHorizontalHeaderLabels({"Portname", "Vendor ID", "Product ID"});
    tableWidget_Devices->setShowGrid(true);

    // text edits
    plaintextEdit_Msg = new QPlainTextEdit(page_ConnectionTest);
    plaintextEdit_Reply = new QPlainTextEdit(page_ConnectionTest);

    plaintextEdit_Msg->setGeometry(LABEL_XTOP, TEXTEDIT_SEND_YPOS, TEXTEDIT_SEND_WIDTH, TEXTEDIT_SEND_HEIGHT);
    plaintextEdit_Reply->setGeometry(LABEL_XTOP + TEXTEDIT_SEND_WIDTH + TEXTEDIT_SEND_XSPACE, TEXTEDIT_SEND_YPOS,
                                TEXTEDIT_REPLY_WIDTH, TEXTEDIT_SEND_HEIGHT + PUSHBUTTON_SEND_YSPACE + PUSHBUTTON_HEIGHT);
    // grid layout port settings
    gridLayout_PortSettings->addWidget(label_PortSettings, 0, 0,Qt::AlignCenter);
    gridLayout_PortSettings->addWidget(label_BaudRate, 1, 0,Qt::AlignLeft);
    gridLayout_PortSettings->addWidget(label_Parity, 2, 0, Qt::AlignLeft);
    gridLayout_PortSettings->addWidget(label_Databits, 3, 0, Qt::AlignLeft);
    gridLayout_PortSettings->addWidget(label_Stopbits, 4, 0, Qt::AlignLeft);
    gridLayout_PortSettings->addWidget(label_Flowcontrol, 5, 0, Qt::AlignLeft);
    gridLayout_PortSettings->addWidget(comboBox_BaudRate, 1, 1, Qt::AlignRight);
    gridLayout_PortSettings->addWidget(comboBox_Parity, 2, 1, Qt::AlignRight);
    gridLayout_PortSettings->addWidget(comboBox_Databits, 3, 1, Qt::AlignRight);
    gridLayout_PortSettings->addWidget(comboBox_Stopbits, 4, 1, Qt::AlignRight);
    gridLayout_PortSettings->addWidget(comboBox_Flowcontrol, 5, 1, Qt::AlignRight);
    gb_portSettings->setLayout(gridLayout_PortSettings);
    gb_portSettings->setMaximumWidth(350);

    // grid layout device search
    gridLayout_DeviceSearch->addWidget(label_DeviceSearch,0,0,Qt::AlignLeft);
    gridLayout_DeviceSearch->addWidget(pushButton_Search,1,0,Qt::AlignCenter);
    gridLayout_DeviceSearch->addWidget(pushButton_Connect,1,1,Qt::AlignCenter);
    gridLayout_DeviceSearch->addWidget(pushButton_Disconnect,1,2,Qt::AlignCenter);
    gridLayout_DeviceSearch->addWidget(tableWidget_Devices,2,0,2,3,Qt::AlignLeft);
    gridLayout_DeviceSearch->addWidget(label_ConnectState,7,0,Qt::AlignCenter);
    gridLayout_DeviceSearch->addWidget(label_ConnectionMsg,5,1,5,3,Qt::AlignCenter);
    gb_deviceSearch->setLayout(gridLayout_DeviceSearch);
    //gb_deviceSearch->setFixedWidth(400);


    // grid layout textMessage
    gridLayout_SendTextMsg->addWidget(label_SendTextMsg,0,0,Qt::AlignLeft);
    gridLayout_SendTextMsg->addWidget(plaintextEdit_Msg,1,0,Qt::AlignLeft);
    gridLayout_SendTextMsg->addWidget(plaintextEdit_Reply,1,1,Qt::AlignRight);
    gridLayout_SendTextMsg->addWidget(pushButton_Send,2,0,Qt::AlignLeft);
    gb_textMessage->setLayout(gridLayout_SendTextMsg);
    gb_textMessage->setMaximumWidth(350);

    // page layout
    gridPageConnection->addWidget(gb_portSettings,0,0);
    gridPageConnection->addWidget(gb_deviceSearch,0,1);
    gridPageConnection->addWidget(gb_textMessage,1,0);
    page_ConnectionTest->setLayout(gridPageConnection);
    // connect slots
    connect(pushButton_Search, &QPushButton::clicked, this, &CProberVisu::on_pushButton_Search_clicked);
    connect(pushButton_Connect, &QPushButton::clicked, this, &CProberVisu::on_pushButton_Connect_clicked);
    connect(pushButton_Disconnect, &QPushButton::clicked, this, &CProberVisu::on_pushButton_Disconnect_clicked);
    connect(tableWidget_Devices, &QTableWidget::itemSelectionChanged, this, &CProberVisu::on_tableWidget_Ports_itemSelectionChanged);
    connect(pushButton_Send, &QPushButton::clicked, this, &CProberVisu::on_pushButton_SendString_clicked);
    // PAGE_CONNECTION_END ---------------------------------------------------------------------------------------------------------


    // PAGE_MANUALCONTROL_BEGIN ------------------------------------------------------------------------------------------------------
    // group boxes
    gb_proberState = new QGroupBox();
    gb_manualControl = new QGroupBox();
    gb_synchComm = new QGroupBox();

    // grid layouts
    gridPageManualControl = new QGridLayout();
    gridLayout_proberState = new QGridLayout();
    gridLayout_manualControl = new QGridLayout();
    gridLayout_synchComm = new QGridLayout();

    // labels
    //label_ActXPos = new QLabel(page_ManualControl);
    //label_ActYPos = new QLabel(page_ManualControl);
    //label_ActZPos = new QLabel(page_ManualControl);
    label_SetXPos = new QLabel(page_ManualControl);
    label_SetYPos = new QLabel(page_ManualControl);
    label_SetZPos = new QLabel(page_ManualControl);
    label_PosRef = new QLabel(page_ManualControl);
    label_Unit = new QLabel(page_ManualControl);
    label_Velocity = new QLabel(page_ManualControl);
    label_SynchComm = new QLabel(page_ManualControl);
    label_SynchCommState = new QLabel(page_ManualControl);
    label_inZPositionText = new QLabel(page_ManualControl);
    label_inZPositionRectangle = new QLabel(page_ManualControl);
    label_inXYPositionText = new QLabel(page_ManualControl);
    label_inXYPositionRectangle = new QLabel(page_ManualControl);
    label_bufferSize = new QLabel(page_ManualControl);

    //label_ActXPos->setText("X Position");
    //label_ActYPos->setText("Y Position");
    //label_ActZPos->setText("Z Position");
    label_SetXPos->setText("X Position");
    label_SetYPos->setText("Y Position");
    label_SetZPos->setText("Z Position");
    label_PosRef->setText("PosRef");
    label_Unit->setText("Unit");
    label_Velocity->setText("Velocity");
    label_SynchComm->setText("Synchronous Communication");
    label_SynchCommState->setText("Ready to start");
    label_inZPositionText->setText("Chuck in Z position");
    label_inZPositionRectangle->setText(" ");
    label_inXYPositionText->setText("Chuck in XY position");
    label_inXYPositionRectangle->setText(" ");
    label_bufferSize->setText("Buffergröße");

    //label_ActXPos->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*0 + TEXTEDIT_MC_XSPACE*0,LABEL_MC_ACTPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    //label_ActYPos->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*1 + TEXTEDIT_MC_XSPACE*1,LABEL_MC_ACTPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    //label_ActZPos->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*2 + TEXTEDIT_MC_XSPACE*2,LABEL_MC_ACTPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_SetXPos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*0 + TEXTEDIT_MC_XSPACE*0,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_SetXPos->setMinimumHeight(TEXTEDIT_MC_HEIGHT);
    label_SetYPos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*1 + TEXTEDIT_MC_XSPACE*1,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_SetYPos->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    label_SetZPos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*2 + TEXTEDIT_MC_XSPACE*2,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_SetZPos->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    label_PosRef->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*3 + TEXTEDIT_MC_XSPACE*3,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_PosRef->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    label_Unit->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*4 + TEXTEDIT_MC_XSPACE*4,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_Unit->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    label_Velocity->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE*5,LABEL_MC_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    label_Velocity->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    label_SynchComm->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE,LABEL_MC_ACTPOS_YPOS,
                                 TEXTEDIT_MC_WIDTH*3 + TEXTEDIT_MC_XSPACE, TEXTEDIT_MC_HEIGHT);
    label_SynchComm->setMaximumHeight(TEXTEDIT_MC_HEIGHT*3);
    label_SynchCommState->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE,LABEL_MC_SYNCHCOMM_STATE_YPOS,
                                      TEXTEDIT_MC_WIDTH*3 + TEXTEDIT_MC_XSPACE*3, TEXTEDIT_MC_HEIGHT);
    label_SynchCommState->setMaximumHeight(TEXTEDIT_MC_HEIGHT);    
    label_SynchCommState->setMinimumWidth(TEXTEDIT_MC_WIDTH*3.5);               

    label_inZPositionText->setGeometry(LABEL_INPOSITIONZ_X,LABEL_INPOSITIONZ_Y,LABEL_INPOSITIONZ_WIDTH,LABEL_INPOSITIONZ_HEIGHT);
    label_inZPositionRectangle->setGeometry(LABEL_INPOSITIONZRECT_X,LABEL_INPOSITIONZRECT_Y,LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT);
    label_inXYPositionText->setGeometry(LABEL_INPOSITIONXY_X,LABEL_INPOSITIONXY_Y,LABEL_INPOSITIONXY_WIDTH,LABEL_INPOSITIONXY_HEIGHT);
    label_inXYPositionRectangle->setGeometry(LABEL_INPOSITIONXYRECT_X,LABEL_INPOSITIONXYRECT_Y,LABEL_INPOSITIONXYRECT_WIDTH,LABEL_INPOSITIONXYRECT_HEIGHT);
    label_inZPositionRectangle->setMaximumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inZPositionRectangle->setMinimumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inXYPositionRectangle->setMaximumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inXYPositionRectangle->setMinimumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_bufferSize->setGeometry(550,200,75,50);

    label_SynchComm->setStyleSheet("font: 14px bold");
    label_SynchCommState->setStyleSheet("border: 1px solid black");
    label_inZPositionRectangle->setStyleSheet("background-color: gray");
    label_inXYPositionRectangle->setStyleSheet("background-color: gray");

    // Position Visu
    actPostionManualControl = new CPositionVisuXYZ(10,20,30,75,page_ManualControl);
    actPostionManualControl->setMinimumWidth(300);
    //setPositionManualControl = new CPositionVisuXYZ(10,20,250,75,page_ManualControl);

    actPostionManualControl->getLabel()->setText("Actual Position (x, y, z)");
    //setPositionManualControl->getLabel()->setText("Set Position (x, y, z)");

    // push buttons
    pushButton_ReadChuckPosition = new QPushButton(page_ManualControl);
    QPushButton * pushButton_StartSynchRead = new QPushButton(page_ManualControl);
    QPushButton * pushButton_StopSynchRead = new QPushButton(page_ManualControl);
    pushButton_MoveChuckXY = new QPushButton(page_ManualControl);
    pushButton_MoveChuckZ = new QPushButton(page_ManualControl);

    pushButton_ReadChuckPosition->setText("ReadChuckPosition");
    pushButton_StartSynchRead->setText("Start");
    pushButton_StopSynchRead->setText("Stop");
    pushButton_MoveChuckXY->setText("MoveChuck XY");
    pushButton_MoveChuckZ->setText("MoveChuck Z");

    pushButton_ReadChuckPosition->setGeometry(TEXTEDIT_ACTPOS_XPOS, TEXTEDIT_ACTPOS_YPOS + TEXTEDIT_MC_HEIGHT + PUSHBUTTON_MC_YSPACE,
                                              TEXTEDIT_MC_WIDTH*3 + TEXTEDIT_MC_XSPACE*2, PUSHBUTTON_HEIGHT);
    pushButton_StartSynchRead->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE,LABEL_MC_ACTPOS_YPOS*2.25,
                                           TEXTEDIT_MC_WIDTH*1.5 + TEXTEDIT_MC_XSPACE, TEXTEDIT_MC_HEIGHT);   
    pushButton_StartSynchRead->setMaximumWidth(TEXTEDIT_MC_WIDTH*2); 
    pushButton_StartSynchRead->setMaximumHeight(TEXTEDIT_MC_HEIGHT);     
    pushButton_StopSynchRead->setGeometry(TEXTEDIT_ACTPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE*2 + TEXTEDIT_MC_WIDTH*1.5 + TEXTEDIT_MC_XSPACE,
                                          LABEL_MC_ACTPOS_YPOS*2.25, TEXTEDIT_MC_WIDTH*1.5 + TEXTEDIT_MC_XSPACE, TEXTEDIT_MC_HEIGHT);
    pushButton_StopSynchRead->setMaximumWidth(TEXTEDIT_MC_WIDTH*2);
    pushButton_StopSynchRead->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    pushButton_MoveChuckXY->setGeometry(TEXTEDIT_ACTPOS_XPOS, TEXTEDIT_SETPOS_YPOS + TEXTEDIT_MC_HEIGHT + PUSHBUTTON_MC_YSPACE,
                                        TEXTEDIT_MC_WIDTH*6 + TEXTEDIT_MC_XSPACE*5, PUSHBUTTON_HEIGHT);
    pushButton_MoveChuckXY->setMinimumHeight(PUSHBUTTON_HEIGHT);
    pushButton_MoveChuckXY->setMinimumWidth(TEXTEDIT_MC_WIDTH*4.25);
    pushButton_MoveChuckZ->setGeometry(TEXTEDIT_ACTPOS_XPOS, TEXTEDIT_SETPOS_YPOS + TEXTEDIT_MC_HEIGHT + PUSHBUTTON_MC_YSPACE*2 + PUSHBUTTON_HEIGHT,
                                       TEXTEDIT_MC_WIDTH*6 + TEXTEDIT_MC_XSPACE*5, PUSHBUTTON_HEIGHT);
    pushButton_MoveChuckZ->setMinimumHeight(PUSHBUTTON_HEIGHT);
    pushButton_MoveChuckZ->setMinimumWidth(TEXTEDIT_MC_WIDTH*4.25);


    // text edits
    textEdit_SetXpos = new QTextEdit(page_ManualControl);
    textEdit_SetYpos = new QTextEdit(page_ManualControl);
    textEdit_SetZpos = new QTextEdit(page_ManualControl);
    textEdit_PosRef = new QTextEdit(page_ManualControl);
    textEdit_Unit = new QTextEdit(page_ManualControl);
    textEdit_Velocity = new QTextEdit(page_ManualControl);
    textEdit_JoblistSize = new QTextEdit(page_ManualControl);

   
    textEdit_SetXpos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*0 + TEXTEDIT_MC_XSPACE*0,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_SetYpos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*1 + TEXTEDIT_MC_XSPACE*1,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_SetZpos->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*2 + TEXTEDIT_MC_XSPACE*2,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_PosRef->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*3 + TEXTEDIT_MC_XSPACE*3,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_Unit->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*4 + TEXTEDIT_MC_XSPACE*4,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_Velocity->setGeometry(TEXTEDIT_SETPOS_XPOS + TEXTEDIT_MC_WIDTH*5 + TEXTEDIT_MC_XSPACE*5,TEXTEDIT_SETPOS_YPOS,TEXTEDIT_MC_WIDTH, TEXTEDIT_MC_HEIGHT);
    textEdit_JoblistSize->setGeometry(625,200,50,50);
    textEdit_JoblistSize->setMaximumWidth(50);
    textEdit_JoblistSize->setMaximumHeight(50);

    textEdit_SetXpos->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    textEdit_SetYpos->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    textEdit_SetZpos->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    textEdit_PosRef->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    textEdit_Unit->setMaximumHeight(TEXTEDIT_MC_HEIGHT);
    textEdit_Velocity->setMaximumHeight(TEXTEDIT_MC_HEIGHT);

    // Layout
    // grid layout prober state
    gridLayout_proberState->addWidget(actPostionManualControl,0,0);
    gridLayout_proberState->addWidget(pushButton_ReadChuckPosition,1,0);
    gridLayout_proberState->addWidget(label_inZPositionRectangle,1,1);
    gridLayout_proberState->addWidget(label_inZPositionText,1,2);
    gridLayout_proberState->addWidget(label_inXYPositionRectangle,2,1);
    gridLayout_proberState->addWidget(label_inXYPositionText,2,2);
    gridLayout_proberState->setHorizontalSpacing(50);
    gb_proberState->setLayout(gridLayout_proberState);
    gb_proberState->setMaximumHeight(250);
    
    // grid layout manual control
    //gridLayout_manualControl->addWidget(setPositionManualControl,0,0);
    gridLayout_manualControl->addWidget(label_SetXPos,0,0);
    gridLayout_manualControl->addWidget(label_SetYPos,0,1);
    gridLayout_manualControl->addWidget(label_SetZPos,0,2);
    gridLayout_manualControl->addWidget(label_PosRef,0,3);
    gridLayout_manualControl->addWidget(label_Unit,0,4);
    gridLayout_manualControl->addWidget(label_Velocity,0,5);
    gridLayout_manualControl->addWidget(textEdit_SetXpos,1,0);
    gridLayout_manualControl->addWidget(textEdit_SetYpos,1,1);
    gridLayout_manualControl->addWidget(textEdit_SetZpos,1,2);
    gridLayout_manualControl->addWidget(textEdit_PosRef,1,3);
    gridLayout_manualControl->addWidget(textEdit_Unit,1,4);
    gridLayout_manualControl->addWidget(textEdit_Velocity,1,5);
    gridLayout_manualControl->addWidget(pushButton_MoveChuckXY,2,0,2,5);
    gridLayout_manualControl->addWidget(pushButton_MoveChuckZ,3,0,3,5);
    gb_manualControl->setLayout(gridLayout_manualControl);

    // grid layout synch comm
    gridLayout_synchComm->addWidget(label_SynchComm,0,0);
    gridLayout_synchComm->addWidget(pushButton_StartSynchRead,1,0);
    gridLayout_synchComm->addWidget(pushButton_StopSynchRead,1,1);
    gridLayout_synchComm->addWidget(label_SynchCommState,2,0,2,1);
    gridLayout_synchComm->addWidget(label_bufferSize,3,0);
    gridLayout_synchComm->addWidget(textEdit_JoblistSize,3,1);
    gb_synchComm->setLayout(gridLayout_synchComm);


    // page layout
    gridPageManualControl->addWidget(gb_proberState,0,0);
    gridPageManualControl->addWidget(gb_manualControl,1,0);
    gridPageManualControl->addWidget(gb_synchComm,1,1);
    page_ManualControl->setLayout(gridPageManualControl);

    // connect
    connect(pushButton_ReadChuckPosition, &QPushButton::clicked, this, &CProberVisu::on_pushButton_ReadChuckPosition_clicked);
    connect(pushButton_StartSynchRead, &QPushButton::clicked, this, &CProberVisu::on_pushButton_StartSynchComm_clicked);
    connect(pushButton_StopSynchRead, &QPushButton::clicked, this, &CProberVisu::on_pushButton_StopSynch_clicked);
    connect(pushButton_MoveChuckXY, &QPushButton::clicked, this, &CProberVisu::on_pushButton_MoveChuckXY_clicked);
    connect(pushButton_MoveChuckZ, &QPushButton::clicked, this, &CProberVisu::on_pushButton_MoveChuckZ_clicked);



    // PAGE_MANUALCONTROL_END -------------------------------------------------------------------------------------------------------

    // PAGE_STATE_MACHINE_BEGIN -----------------------------------------------------------------------------------------------------
    // group boxes
    gb_stateMachineControl = new QGroupBox();
    gb_stateMachinePositions = new QGroupBox();
    // gridlayouts
    gridPageStateMachine = new QGridLayout();
    gridLayout_stateMachineControl = new QGridLayout();
    gridLayout_stateMachinePositions = new QGridLayout();
    // labels
    label_StateMachineActState = new QLabel(page_StateMachine);
    label_zPrePos  = new QLabel(page_StateMachine);
    label_zFinalPos  = new QLabel(page_StateMachine);
    label_inZPositionTextSM = new QLabel(page_StateMachine);
    label_inZPositionRectangleSM = new QLabel(page_StateMachine);
    label_inXYPositionTextSM = new QLabel(page_StateMachine);
    label_inXYPositionRectangleSM = new QLabel(page_StateMachine);
    label_ActState = new QLabel(page_StateMachine);
    label_MeasurementParam = new QLabel(page_StateMachine);



    label_StateMachineActState->setText("No state");
    label_zPrePos->setText("pre-measurement Z: ");
    label_zFinalPos->setText("final measurement Z: ");
    label_inZPositionTextSM->setText("Chuck in Z position");
    label_inZPositionRectangleSM->setText(" ");
    label_inXYPositionTextSM->setText("Chuck in XY position");
    label_inXYPositionRectangleSM->setText(" ");
    label_ActState->setText("State machine is ready to start");
    label_MeasurementParam->setText("Measured parameter");

    label_StateMachineActState->setGeometry(LABEL_STATE_MACHINE_X, LABEL_STATE_MACHINE_Y, LABEL_STATE_MACHINE_WIDTH, LABEL_STATE_MACHINE_HEIGHT);
    label_StateMachineActState->setMinimumWidth(LABEL_STATE_MACHINE_WIDTH);
    label_StateMachineActState->setMaximumWidth(LABEL_STATE_MACHINE_WIDTH);
    label_StateMachineActState->setMinimumHeight(LABEL_STATE_MACHINE_HEIGHT);
    label_StateMachineActState->setMaximumHeight(LABEL_STATE_MACHINE_HEIGHT);

    label_zPrePos->setGeometry(25,95,175,25);
    label_zPrePos->setMaximumHeight(LABEL_STATE_MACHINE_HEIGHT);
    label_zPrePos->setMaximumWidth(LABEL_STATE_MACHINE_WIDTH);
    label_zFinalPos->setGeometry(25,140,175,25);
    label_zFinalPos->setMaximumHeight(LABEL_STATE_MACHINE_HEIGHT);
    label_zFinalPos->setMaximumWidth(LABEL_STATE_MACHINE_WIDTH);

    label_inZPositionTextSM->setGeometry(465,150,LABEL_INPOSITIONZ_WIDTH,LABEL_INPOSITIONZ_HEIGHT);
    label_inZPositionRectangleSM->setGeometry(425,150,LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT);
    label_inXYPositionTextSM->setGeometry(465,180,LABEL_INPOSITIONXY_WIDTH,LABEL_INPOSITIONXY_HEIGHT);
    label_inXYPositionRectangleSM->setGeometry(425,180,LABEL_INPOSITIONXYRECT_WIDTH,LABEL_INPOSITIONXYRECT_HEIGHT);
    label_inZPositionRectangleSM->setMaximumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inZPositionRectangleSM->setMinimumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inXYPositionRectangleSM->setMaximumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_inXYPositionRectangleSM->setMinimumSize(QSize(LABEL_INPOSITIONZRECT_WIDTH,LABEL_INPOSITIONZRECT_HEIGHT));
    label_ActState->setGeometry(0,550,400,30);


    label_StateMachineActState->setStyleSheet("border: 1px solid black");
    label_inZPositionRectangleSM->setStyleSheet("background-color: gray");
    label_inXYPositionRectangleSM->setStyleSheet("background-color: gray");
    label_ActState->setStyleSheet("border: 1px solid black");


    // textEdits
    textEdit_zPrePos = new QTextEdit(page_StateMachine);
    textEdit_zFinalPos = new QTextEdit(page_StateMachine);

    textEdit_zPrePos->setGeometry(200,95,80,30);
    textEdit_zPrePos->setMaximumHeight(30);
    textEdit_zPrePos->setMaximumWidth(80);
    textEdit_zFinalPos->setGeometry(200,140,80,30);
    textEdit_zFinalPos->setMaximumHeight(30);
    textEdit_zFinalPos->setMaximumWidth(80);

    // Combobox
    comboBox_MeasParam = new QComboBox(page_StateMachine);
    comboBox_MeasParam->addItems(m_measParams);
    comboBox_MeasParam->setCurrentIndex(1);
    emit measurementParam(comboBox_MeasParam->currentIndex());
    // pushButtons
    pushButton_StartStateMachine = new QPushButton(page_StateMachine);
    pushButton_goOn = new QPushButton(page_StateMachine);
    pushButton_StopStateMachine = new QPushButton(page_StateMachine);

    pushButton_StartStateMachine->setText("Start SM");
    pushButton_goOn->setText("Go on");
    pushButton_StopStateMachine->setText("Stop SM");

    pushButton_StartStateMachine->setGeometry(PUSHBUTTON_SM_START_X, PUSHBUTTON_SM_START_Y, PUSHBUTTON_SM_START_WIDTH, PUSHBUTTON_SM_START_HEIGHT);
    pushButton_StartStateMachine->setMaximumHeight(PUSHBUTTON_SM_START_HEIGHT);
    pushButton_StartStateMachine->setMaximumWidth(PUSHBUTTON_SM_START_WIDTH);
    pushButton_goOn->setGeometry(PUSHBUTTON_SM_START_X + PUSHBUTTON_SM_START_WIDTH*3 + POSITIONS_SPACE_X*2, PUSHBUTTON_SM_START_Y, PUSHBUTTON_SM_START_WIDTH, PUSHBUTTON_SM_START_HEIGHT);
    pushButton_goOn->setMaximumHeight(PUSHBUTTON_SM_START_HEIGHT);
    pushButton_goOn->setMaximumWidth(PUSHBUTTON_SM_START_WIDTH);
    pushButton_StopStateMachine->setGeometry(PUSHBUTTON_SM_START_X, PUSHBUTTON_SM_START_Y + PUSHBUTTON_SM_START_HEIGHT + 10, PUSHBUTTON_SM_START_WIDTH,PUSHBUTTON_SM_START_HEIGHT);
    pushButton_StopStateMachine->setMaximumHeight(PUSHBUTTON_SM_START_HEIGHT);
    pushButton_StopStateMachine->setMaximumWidth(PUSHBUTTON_SM_START_WIDTH);


    // position visu
    positionVisu_00 = new CPositionVisuXY(25,225,200,75,false,page_StateMachine);
    positionVisu_01 = new CPositionVisuXY(250,225,200,75,false,page_StateMachine);
    positionVisu_02 = new CPositionVisuXY(475,225,200,75,false,page_StateMachine);
    positionVisu_10 = new CPositionVisuXY(25,325,200,75,false,page_StateMachine);
    positionVisu_11 = new CPositionVisuXY(250,325,200,75,false,page_StateMachine);
    positionVisu_12 = new CPositionVisuXY(475,325,200,75,false,page_StateMachine);
    positionVisu_20 = new CPositionVisuXY(25,425,200,75,false,page_StateMachine);
    positionVisu_21 = new CPositionVisuXY(250,425,200,75,false,page_StateMachine);
    positionVisu_22 = new CPositionVisuXY(475,425,200,75,false,page_StateMachine);
    actPositionStateMachine = new CPositionVisuXYZ(425,80,150,250,true,page_StateMachine);

    positionVisu_00->setObjectName("pos00");
    positionVisu_01->setObjectName("pos01");
    positionVisu_02->setObjectName("pos02");
    positionVisu_10->setObjectName("pos10");
    positionVisu_11->setObjectName("pos11");
    positionVisu_12->setObjectName("pos12");
    positionVisu_20->setObjectName("pos20");
    positionVisu_21->setObjectName("pos21");
    positionVisu_22->setObjectName("pos22");


    positionVisu_00->getLabel()->setText("Cxss1 (x, y)");
    positionVisu_01->getLabel()->setText("Cxss2 (x, y)");
    positionVisu_02->getLabel()->setText("Cxss3 (x, y)");
    positionVisu_10->getLabel()->setText("Cxss4 (x, y)");
    positionVisu_11->getLabel()->setText("Cxss5 (x, y)");
    positionVisu_12->getLabel()->setText("Cxss6 (x, y)");
    positionVisu_20->getLabel()->setText("Cxss7 (x, y)");
    positionVisu_21->getLabel()->setText("Cxss8 (x, y)");
    positionVisu_22->getLabel()->setText("Cxss9 (x, y)");
    actPositionStateMachine->getLabel()->setText("Actual Position");
    actPositionStateMachine->setMaximumWidth(300);
    actPositionStateMachine->setMinimumWidth(250);

    QString strStyle = "#pos00{border: 1px solid black;} \
                            #pos01{border: 1px solid black;} \
                            #pos02{border: 1px solid black;} \
                            #pos10{border: 1px solid black;} \
                            #pos11{border: 1px solid black;} \
                            #pos12{border: 1px solid black;} \
                            #pos20{border: 1px solid black;} \
                            #pos21{border: 1px solid black;} \
                            #pos22{border: 1px solid black;}";
    this->setStyleSheet(strStyle);


    positionVisu_00->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_01->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_02->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_10->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_11->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_12->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_20->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_21->getLabel()->setAlignment(Qt::AlignCenter);
    positionVisu_22->getLabel()->setAlignment(Qt::AlignCenter);

 
   // m_zPrePos = readZValueFromTextEdit(textEdit_zPrePos);
    //m_zFinalPos = readZValueFromTextEdit(textEdit_zFinalPos);
    actPositionStateMachine->on_writePositionToTextEdit(CPosition(0,0,0));

    // Layout
    // grid layout state machine control
    gridLayout_stateMachineControl->addWidget(pushButton_StartStateMachine, 0, 0);
    gridLayout_stateMachineControl->addWidget(pushButton_StopStateMachine, 0, 1);
    gridLayout_stateMachineControl->addWidget(label_StateMachineActState, 0, 2);
    gridLayout_stateMachineControl->addWidget(pushButton_goOn, 0, 8,Qt::AlignRight);
    gridLayout_stateMachineControl->addWidget(label_zPrePos, 1,0);
    gridLayout_stateMachineControl->addWidget(textEdit_zPrePos, 1,1);
    gridLayout_stateMachineControl->addWidget(label_zFinalPos, 2,0);
    gridLayout_stateMachineControl->addWidget(textEdit_zFinalPos, 2,1);
    gridLayout_stateMachineControl->addWidget(label_MeasurementParam, 3, 0);
    gridLayout_stateMachineControl->addWidget(comboBox_MeasParam, 3,1);
    gridLayout_stateMachineControl->addWidget(actPositionStateMachine, 1,2, Qt::AlignLeft);
    gridLayout_stateMachineControl->addWidget(label_inXYPositionRectangleSM, 2,7);
    gridLayout_stateMachineControl->addWidget(label_inXYPositionTextSM, 2,8);
    gridLayout_stateMachineControl->addWidget(label_inZPositionRectangleSM, 3,7);
    gridLayout_stateMachineControl->addWidget(label_inZPositionTextSM, 3,8);
    gb_stateMachineControl->setLayout(gridLayout_stateMachineControl);


    // grid laxout state machine positions
    gridLayout_stateMachinePositions->addWidget(positionVisu_00, 0,0);
    gridLayout_stateMachinePositions->addWidget(positionVisu_01, 0,1);
    gridLayout_stateMachinePositions->addWidget(positionVisu_02, 0,2);
    gridLayout_stateMachinePositions->addWidget(positionVisu_10, 1,0);
    gridLayout_stateMachinePositions->addWidget(positionVisu_11, 1,1);
    gridLayout_stateMachinePositions->addWidget(positionVisu_12, 1,2);
    gridLayout_stateMachinePositions->addWidget(positionVisu_20, 2,0);
    gridLayout_stateMachinePositions->addWidget(positionVisu_21, 2,1);
    gridLayout_stateMachinePositions->addWidget(positionVisu_22, 2,2);
    gridLayout_stateMachinePositions->addWidget(label_ActState,3,0,3,2);
    gb_stateMachinePositions->setLayout(gridLayout_stateMachinePositions);


    // page layout
    gridPageStateMachine->addWidget(gb_stateMachineControl, 0, 0);
    gridPageStateMachine->addWidget(gb_stateMachinePositions, 1, 0);
    page_StateMachine->setLayout(gridPageStateMachine);

    // connects
    connect(positionVisu_00,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_01,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_02,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_10,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_11,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_12,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_20,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_21,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);
    connect(positionVisu_22,&CPositionVisuXY::positionChanged, this, &CProberVisu::on_positionChanged);

    //connect(this, &CProberVisu::changePositionStylesheet, positionVisu_00, &CPositionVisuXY::on_StylesheetChanged);

    connect(pushButton_StartStateMachine, &QPushButton::clicked, this, &CProberVisu::on_pushButton_StartStateMachine_clicked);
    connect(pushButton_StopStateMachine, &QPushButton::clicked, this, &CProberVisu::on_pushButtonStopStateMachine_clicked);
    connect(textEdit_zPrePos,&QTextEdit::textChanged, this, &CProberVisu::on_textEdit_ZPreValue_changed);
    connect(textEdit_zFinalPos,&QTextEdit::textChanged, this, &CProberVisu::on_textEdit_ZFinalValue_changed);
    // QT5 can not distinguish between currentIndecCHanged(int) and (text) therefore use this syntax
    connect(comboBox_MeasParam, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &CProberVisu::on_MeasuredParameter_Changed);

   // PAGE_STATE_MACHINE_END -------------------------------------------------------------------------------------------------------

    // PAGE_LOGGER_BEGIN -------------------------------------------------------------------------------------------------------------
    vboxLayout_logger = new QVBoxLayout();

    // labels
    label_ProberLogger = new QLabel(page_Logger);
    label_ProberLogger->setText("Prober Logger");
    label_ProberLogger->setGeometry(LABEL_LOGGER_XPOS,LABEL_LOGGER_YPOS, LABEL_LOGGER_WIDTH, LABEL_LOGGER_HEIGHT);
    label_ProberLogger->setStyleSheet("font: bold 14px");

    plainTextEdit_Logger = new QPlainTextEdit(page_Logger);
    plainTextEdit_Logger->setGeometry(LOGGER_XPOS,LOGGER_YPOS,LOGGER_WIDTH, LOGGER_HEIGHT);

    vboxLayout_logger->addWidget(label_ProberLogger,0);
    vboxLayout_logger->addWidget(plainTextEdit_Logger,0);
    page_Logger->setLayout(vboxLayout_logger);

    // PAGE_LOGGER_END -------------------------------------------------------------------------------------------------------------

    // init logger and read data display
    m_ptrProber->setDisplayLogger(plainTextEdit_Logger);
    m_ptrProber->setResponseDisplay(plaintextEdit_Reply);

}


CProberVisu::~CProberVisu(){

}

QPlainTextEdit * CProberVisu::getReadDataDisplay()
 {
     return plaintextEdit_Reply;
 }

void CProberVisu::setThreads(QThread * _consumer, QThread * _producer)
 {
     consumerThread = _consumer;
     producerThread = _producer;
 }

QPushButton * CProberVisu::getPushButtonGoOn(void)
{
    return pushButton_goOn;
}

QLabel * CProberVisu::getLabelActState(void)
{
    return label_StateMachineActState;
}

CPositionVisuXYZ * CProberVisu::getActPositionVisuSM(void)
{
    return actPositionStateMachine;
}

double CProberVisu::readZValueFromTextEdit(QTextEdit * _zValue)
{
   QString allowedChars = "-0123456789.";
   QString zPos = _zValue->toPlainText();
   if(!zPos.isEmpty()){
       for(int i = 0; i < zPos.size(); i++){
           if(!allowedChars.contains(zPos.at(i)))
           {
               on_WarningMsg("Warning", "Invalid input for position");
               return qInf();
           }
       }
       return zPos.toDouble();
   }
   return qInf();
}
// slots

void CProberVisu::on_pushButton_Search_clicked()
{
    bool noDeviceFound = true;
    noDeviceFound = m_ptrProber->searchForDevice();

    if(!noDeviceFound)
    {
        m_ptrProber->displayFoundDevices(tableWidget_Devices);
    }
}

void CProberVisu::on_pushButton_Connect_clicked()
{
    QString devicePortName = m_ptrProber->getSelectedDevicePort(tableWidget_Devices);
    m_ptrProber->connectDevice(devicePortName,
                         EnumHelper::fromString<QSerialPort::BaudRate>(m_bauds.at(comboBox_BaudRate->currentIndex())),
                         EnumHelper::fromString<QSerialPort::Parity>(m_parities.at(comboBox_Parity->currentIndex())),
                         EnumHelper::fromString<QSerialPort::DataBits>(m_databits.at(comboBox_Databits->currentIndex())),
                         EnumHelper::fromString<QSerialPort::StopBits>(m_stopbits.at(comboBox_Stopbits->currentIndex())),
                         EnumHelper::fromString<QSerialPort::FlowControl>(m_flowControl.at(comboBox_Flowcontrol->currentIndex())));

}

void CProberVisu::on_tableWidget_Ports_itemSelectionChanged()
{
    m_ptrProber->setSelectedDevice(tableWidget_Devices);

}

void CProberVisu::on_pushButton_Disconnect_clicked()
{

    m_ptrProber->disconnectDevice();

}

void CProberVisu::on_pushButton_SendString_clicked()
{

    m_ptrProber->sendString(plaintextEdit_Msg);

    //emit addCommand(plaintextEdit_Msg->toPlainText().toUtf8());

}

void CProberVisu::on_pushButton_ReadChuckPosition_clicked()
{
    unsigned int retVal= 0;
    actPostionManualControl->getTextEditX()->clear();
    actPostionManualControl->getTextEditY()->clear();
    actPostionManualControl->getTextEditZ()->clear();
    retVal = m_ptrProber->on_asynchReadChuckPosition();
    qDebug() << "return of readChuckPosition: " << retVal;
}

void CProberVisu::on_pushButton_StartSynchComm_clicked()
{
    actPostionManualControl->getTextEditX()->clear();
    actPostionManualControl->getTextEditY()->clear();
    actPostionManualControl->getTextEditZ()->clear();
    if(!m_ptrProber->getSerialPort()->portName().isEmpty())
    {
        if(!consumerThread->isRunning()
                && !producerThread->isRunning())
        {
            consumerThread->start();
            producerThread->start();
            if(!m_ptrProber->isCycPosReadActive())
            {
               m_ptrProber->startCyclPosRead();
            }
            if(consumerThread->isRunning()
                    && producerThread->isRunning())
                label_SynchCommState->setText("Synchronous communication is running");
        }else{
           m_ptrProber->wakeUpConsumer();
           consumerThread->start();
           producerThread->start();
           if(!m_ptrProber->isCycPosReadActive())
       {
          m_ptrProber->startCyclPosRead();
       }
           if(consumerThread->isRunning()
                   && producerThread->isRunning())
               label_SynchCommState->setText("Synchronous communication is running");
        }
    }else{
        on_WarningMsg("Warning", "No port selected for prober system");
    }

}

void CProberVisu::on_pushButton_StopSynch_clicked()
{
    m_ptrProber->stopCycPosRead();
    on_Connected(false);
    // TODO wait unti buffer is empty!
    m_ptrProber->quitConsumer();
    m_ptrProber->wakeUpConsumer();
    consumerThread->exit();
    //consumerThread->terminate();
    consumerThread->wait();

    m_ptrProber->quitProducer();
    m_ptrProber->wakeUpProducer();
    producerThread->exit();
    //producerThread->terminate();
    producerThread->wait();

    if(!consumerThread->isRunning() && !producerThread->isRunning())
        label_SynchCommState->setText("Ready to start");
}

void CProberVisu::on_pushButton_MoveChuckXY_clicked()
{
    unsigned int retVal = 0;
    CPosition _target(0,0,0);
    QString xPos = textEdit_SetXpos->toPlainText();// TODO
    QString yPos = textEdit_SetYpos->toPlainText();// TODO
    QString zPos = textEdit_SetZpos->toPlainText();// TODO
   const QChar minus = '-';
   const QChar dot = '.';

    // read position from textedit and check for input errors
    for(QString::const_iterator i = (QString::const_iterator)xPos.begin(); i != (QString::const_iterator)xPos.end(); i++)
    {
       if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
           QMessageBox::warning(this,"Warning", "Invalid input for X value parameter");
           return;
       }
    }

    for(QString::const_iterator i = (QString::const_iterator)yPos.begin(); i != (QString::const_iterator)yPos.end(); i++)
    {
        if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
            QMessageBox::warning(this,"Warning", "Invalid input for Y value parameter");
            return;
        }
    }
    for(QString::const_iterator i = (QString::const_iterator)zPos.begin(); i != (QString::const_iterator)zPos.end(); i++)
    {
        if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
            QMessageBox::warning(this,"Warning", "Invalid input for Z value parameter");
            return;
        }
    }
    _target.setXpos(textEdit_SetXpos->toPlainText().toDouble());//TODO change to CPositionVisuXYZ
    _target.setYpos(textEdit_SetYpos->toPlainText().toDouble());//TODO change to CPositionVisuXYZ
    _target.setZpos(textEdit_SetZpos->toPlainText().toDouble());//TODO change to CPositionVisuXYZ
    // send command
    retVal = m_ptrProber->on_requestMoveChuckXY(_target.getXpos(), _target.getYpos(), textEdit_PosRef->toPlainText(), textEdit_Unit->toPlainText(), textEdit_Velocity->toPlainText());
    qDebug() << "return of moveChuck: " << retVal;

    switch(retVal)
    {
        case 1: QMessageBox::warning(this,"Warning", "Write error occured"); break;
        case 2: QMessageBox::warning(this,"Warning", "Port no writeable"); break;
        case 3: QMessageBox::warning(this,"Warning", "Port not opened"); break;
        case 4: QMessageBox::warning(this,"Warning", "Invalid input for PosRef parameter"); break;
        case 5: QMessageBox::warning(this,"Warning", "Invalid input for unit parameter"); break;
        case 6: QMessageBox::warning(this,"Warning", "Invalid input for velocity parameter"); break;

    }

}

void CProberVisu::on_pushButton_MoveChuckZ_clicked()
{
    unsigned int retVal = 0;
    CPosition target(0,0,0);
    QString xPos = textEdit_SetXpos->toPlainText();
    QString yPos = textEdit_SetYpos->toPlainText();
    QString zPos = textEdit_SetZpos->toPlainText();
    const QChar minus = '-';
    const QChar dot = '.';

    // read position from textedit and check for input errors
    for(QString::const_iterator i = (QString::const_iterator)xPos.begin(); i != (QString::const_iterator)xPos.end(); i++)
    {
       if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
           QMessageBox::warning(this,"Warning", "Invalid input for X value parameter");
           return;
       }
    }

    for(QString::const_iterator i = (QString::const_iterator)yPos.begin(); i != (QString::const_iterator)yPos.end(); i++)
    {
        if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
            QMessageBox::warning(this,"Warning", "Invalid input for Y value parameter");
            return;
        }
    }
    for(QString::const_iterator i = (QString::const_iterator)zPos.begin(); i != (QString::const_iterator)zPos.end(); i++)
    {
        if(!(i->isDigit()) && (*i != dot) && (*i != minus)){
            QMessageBox::warning(this,"Warning", "Invalid input for Z value parameter");
            return;
        }
    }
    // write target
    target.setXpos(textEdit_SetXpos->toPlainText().toDouble());
    target.setYpos(textEdit_SetYpos->toPlainText().toDouble());
    target.setZpos(textEdit_SetZpos->toPlainText().toDouble());

    // send command
    retVal = m_ptrProber->on_requestMoveChuckZ(target.getZpos(), textEdit_PosRef->toPlainText(), textEdit_Unit->toPlainText(), textEdit_Velocity->toPlainText());
    qDebug() << "return of moveChuck: " << retVal;

    switch(retVal)
    {
        case 1: QMessageBox::warning(this,"Warning", "Write error occured"); break;
        case 2: QMessageBox::warning(this,"Warning", "Port no writeable"); break;
        case 3: QMessageBox::warning(this,"Warning", "Port not opened"); break;
        case 4: QMessageBox::warning(this,"Warning", "Invalid input for PosRef parameter"); break;
        case 5: QMessageBox::warning(this,"Warning", "Invalid input for unit parameter"); break;
        case 6: QMessageBox::warning(this,"Warning", "Invalid input for velocity parameter"); break;

    }
}

void CProberVisu::on_pushButton_StartStateMachine_clicked(void)
{
    QString paramNameInFile;
    switch (comboBox_MeasParam->currentIndex())
    {
        case 0:
                paramNameInFile = "Vgs";
            break;
        case 1:
                paramNameInFile = "Idss";
            break;
        case 2:
                paramNameInFile = "Igss";
            break;
        case 3:
                paramNameInFile = "Ciss";
                break;
        case 4:
                paramNameInFile = "Coss";
                break;
        case 5:
                paramNameInFile = "Crss";
                break;
        default:
                paramNameInFile = "ParamName";
            break;
    }
    emit paramNameInFileChanged(paramNameInFile); // send param name to MeasCtrl
    emit startStateMachine();
}

void CProberVisu::on_pushButtonStopStateMachine_clicked(void)
{

    emit stopStateMachine();
}

void CProberVisu::on_ErrorMsg(QString _windowTitle, QString _windowText)
{
    QMessageBox::critical(this, _windowTitle, _windowText);
}

void CProberVisu::on_WarningMsg(QString _windowTitle, QString _windowText)
 {
     QMessageBox::warning(this, _windowTitle, _windowText);
 }

void CProberVisu::on_InformationMsg(QString _windowTitle, QString _windowText)
 {
     QMessageBox::information(this, _windowTitle, _windowText);
 }

void CProberVisu::on_stateMachineRunningChanged(bool _running)
{
    if(_running)
    {
        label_ActState->setText("State machine is running...");
    }else{
        label_ActState->setText("State machine is stopped");
    }
}

void CProberVisu::on_SynchCommFinished(void)
{
    QMessageBox::information(this, "Information", "Synch Comm has finished");
}

void CProberVisu::on_Connected(bool isConnected)
{
    if(isConnected)
    {
        label_ConnectionMsg->setText("Connected to " + m_ptrProber->getSerialPort()->portName());
        label_ConnectionMsg->setStyleSheet("background-color: green");
    }else{
        label_ConnectionMsg->setText("Not Connected");
        label_ConnectionMsg->setStyleSheet("border: 1px solid black; background-color: red");
    }
}

void CProberVisu::on_readData(QString  _readData)
{
    plaintextEdit_Reply->appendPlainText(_readData);
    // if data can be converted to position
    if( actPostionManualControl != nullptr
            && m_ptrProber != nullptr)
    {
        m_ptrProber->displayActPosition(actPostionManualControl);
    }
}

void CProberVisu::on_positionChanged(QString _posName, CPosition _newPosition)
{
    QString searchedChars = "012";
    QString foundChars = "";
    const int len = _posName.size();

    for(int i = 0; i < len; i++)
    {
        if(searchedChars.contains(_posName.at(i)))
        {
            foundChars += _posName.at(i);
        }
    }

    int row;
     int column;
    if(foundChars.size()>1){
     int row = QString(foundChars.at(0)).toInt();
     int column = QString(foundChars.at(1)).toInt();
     emit changedPosition(row, column, _newPosition);
    }
   
}

void CProberVisu::on_stateMachineFinished(void)
{
    label_StateMachineActState->setText("state machine finished");
    qDebug() << "state machine finished";
}

void CProberVisu::on_proberInZPosition(void){
    label_inZPositionRectangle->setStyleSheet("background-color: green");
    label_inZPositionRectangleSM->setStyleSheet("background-color: green");
}

void CProberVisu::on_proberInXYPosition(void)
{
    label_inXYPositionRectangle->setStyleSheet("background-color: green");
    label_inXYPositionRectangleSM->setStyleSheet("background-color: green");
}

void CProberVisu::on_proberNotInZPosition(void){
    label_inZPositionRectangle->setStyleSheet("background-color: red");
    label_inZPositionRectangleSM->setStyleSheet("background-color: red");
}

void CProberVisu::on_proberNotInXYPosition(void){
    label_inXYPositionRectangle->setStyleSheet("background-color: red");
    label_inXYPositionRectangleSM->setStyleSheet("background-color: red");
}

void CProberVisu::on_bufferSizeChanged(int _bufferSize)
{
    textEdit_JoblistSize->setText(QString::number(_bufferSize));
}

void CProberVisu::on_textEdit_ZPreValue_changed(void)
{
    QString allowedChars = "-0123456789.";
    QString zPos = textEdit_zPrePos->toPlainText();
    double z;

    if(!zPos.isEmpty()){
        for(int i = 0; i < zPos.size(); i++){
            if(!allowedChars.contains(zPos.at(i)))
            {
                on_WarningMsg("Warning", "Invalid input for position");
                m_zPrePos =  qInf();
            }
        }

        z = zPos.toDouble();
        if( z < m_zFinalPos)
        {
            m_zPrePos = zPos.toDouble();
            emit zValuePrePos(m_zPrePos);
        }else{
            on_WarningMsg("Warning", "Pre measurement value cannot be higher than final measurement value");
        }
        
    }
}

void CProberVisu::on_textEdit_ZFinalValue_changed(void)
{
    QString allowedChars = "-0123456789.";
    QString zPos = textEdit_zFinalPos->toPlainText();
    double z = 0;

    if(!zPos.isEmpty()){
        for(int i = 0; i < zPos.size(); i++){
            if(!allowedChars.contains(zPos.at(i)))
            {
                on_WarningMsg("Warning", "Invalid input for position");
                m_zFinalPos =  qInf();
            }
        }
        z = zPos.toDouble();
        if( z > m_zPrePos)
        {
            m_zFinalPos = zPos.toDouble();
            emit zValueFinalPos(m_zFinalPos);
        }else{
            on_WarningMsg("Warning", "Final measurement Pos have to be always higher than pre measurement value");
        }
    }
}

void CProberVisu:: on_measurementPositionChanged(int _row, int _column)
{
    QString strStyle = "#pos00{border: 1px solid black;} \
                            #pos01{border: 1px solid black;} \
                            #pos02{border: 1px solid black;} \
                            #pos10{border: 1px solid black;} \
                            #pos11{border: 1px solid black;} \
                            #pos12{border: 1px solid black;} \
                            #pos20{border: 1px solid black;} \
                            #pos21{border: 1px solid black;} \
                            #pos22{border: 1px solid black;}";
    switch (_row) {
                    case 0:
                        switch(_column)
                        {
                            case 0:
                                      strStyle = "#pos00{border: 2px solid gray; background-color: lightgray;} \
                                                #pos01{border: 1px solid black;} \
                                                #pos02{border: 1px solid black;} \
                                                #pos10{border: 1px solid black;} \
                                                #pos11{border: 1px solid black;} \
                                                #pos12{border: 1px solid black;} \
                                                #pos20{border: 1px solid black;} \
                                                #pos21{border: 1px solid black;} \
                                                #pos22{border: 1px solid black;}";
                                        emit changePositionStylesheet("{border: 2px solid gray; background-color: lightgray;}");
                                        this->setStyleSheet(strStyle);

                                       break;
                            case 1:
                                       strStyle = "#pos00{border: 1px solid black;} \
                                               #pos01{border: 2px solid gray; background-color: lightgray;} \
                                               #pos02{border: 1px solid black;} \
                                               #pos10{border: 1px solid black;} \
                                               #pos11{border: 1px solid black;} \
                                               #pos12{border: 1px solid black;} \
                                               #pos20{border: 1px solid black;} \
                                               #pos21{border: 1px solid black;} \
                                               #pos22{border: 1px solid black;}";
                                        this->setStyleSheet(strStyle);
                                        break;
                            case 2:
                                        strStyle = "#pos00{border: 1px solid black;} \
                                                #pos01{border: 1px solid black;}\
                                                #pos02{border: 2px solid gray; background-color: lightgray;}  \
                                                #pos10{border: 1px solid black;} \
                                                #pos11{border: 1px solid black;} \
                                                #pos12{border: 1px solid black;} \
                                                #pos20{border: 1px solid black;} \
                                                #pos21{border: 1px solid black;} \
                                                #pos22{border: 1px solid black;}";
                                        this->setStyleSheet(strStyle);
                                       break;
                            default:
                                       break;

                        }
                      break;
                    case 1:
                       switch(_column)
                       {
                           case 0:
                                     strStyle = " #pos00{border: 1px solid black;}\
                                               #pos01{border: 1px solid black;} \
                                               #pos02{border: 1px solid black;} \
                                               #pos10{border: 2px solid gray; background-color: lightgray;} \
                                               #pos11{border: 1px solid black;} \
                                               #pos12{border: 1px solid black;} \
                                               #pos20{border: 1px solid black;} \
                                               #pos21{border: 1px solid black;} \
                                               #pos22{border: 1px solid black;}";
                                       this->setStyleSheet(strStyle);
                                      break;
                           case 1:
                                      strStyle = "#pos00{border: 1px solid black;} \
                                              #pos01{border: 1px solid black;} \
                                              #pos02{border: 1px solid black;} \
                                              #pos10{border: 1px solid black;} \
                                              #pos11{border: 2px solid gray; background-color: lightgray;} \
                                              #pos12{border: 1px solid black;} \
                                              #pos20{border: 1px solid black;} \
                                              #pos21{border: 1px solid black;} \
                                              #pos22{border: 1px solid black;}";
                                       this->setStyleSheet(strStyle);
                                    break;
                           case 2:
                                       strStyle = "#pos00{border: 1px solid black;} \
                                               #pos01{border: 1px solid black;} \
                                               #pos02{border: 1px solid black;} \
                                               #pos10{border: 1px solid black;} \
                                               #pos11{border: 1px solid black;} \
                                               #pos12{border: 2px solid gray; background-color: lightgray;}  \
                                               #pos20{border: 1px solid black;} \
                                               #pos21{border: 1px solid black;} \
                                               #pos22{border: 1px solid black;}";
                                       this->setStyleSheet(strStyle);
                                      break;
                           default:
                                      break;

                       }
                       break;
                    case 2:
                       switch(_column)
                       {
                           case 0:
                                     strStyle = "#pos00{border: 1px solid black;} \
                                               #pos01{border: 1px solid black;} \
                                               #pos02{border: 1px solid black;} \
                                               #pos10{border: 1px solid black;} \
                                               #pos11{border: 1px solid black;} \
                                               #pos12{border: 1px solid black;} \
                                               #pos20{border: 2px solid gray; background-color: lightgray;} \
                                               #pos21{border: 1px solid black;} \
                                               #pos22{border: 1px solid black;}";
                                       this->setStyleSheet(strStyle);
                                      break;
                           case 1:
                                      strStyle = "#pos00{border: 1px solid black;} \
                                              #pos01{border: 1px solid black;} \
                                              #pos02{border: 1px solid black;} \
                                              #pos10{border: 1px solid black;} \
                                              #pos11{border: 1px solid black;} \
                                              #pos12{border: 1px solid black;} \
                                              #pos20{border: 1px solid black;} \
                                              #pos21{border: 2px solid gray; background-color: lightgray;}  \
                                              #pos22{border: 1px solid black;}";
                                       this->setStyleSheet(strStyle);
                                        break;
                           case 2:
                                       strStyle = "#pos00{border: 1px solid black;} \
                                               #pos01{border: 1px solid black;} \
                                               #pos02{border: 1px solid black;} \
                                               #pos10{border: 1px solid black;} \
                                               #pos11{border: 1px solid black;} \
                                               #pos12{border: 1px solid black;} \
                                               #pos20{border: 1px solid black;} \
                                               #pos21{border: 1px solid black;} \
                                               #pos22{border: 2px solid gray; background-color: lightgray;} ";
                                       this->setStyleSheet(strStyle);
                                      break;
                           default:
                                      break;

                       }
                       break;
                    default:
                        break;

    }
}

void CProberVisu::on_MeasuredParameter_Changed(int index)
{
    // delete all devices from the list
    emit deleteMeasurementDevices();
    // add required devices
    emit measurementParam(comboBox_MeasParam->currentIndex());
    // send param name to measurement control for file name
    QString paramNameInFile;
    switch (comboBox_MeasParam->currentIndex())
    {
        case 1:
                paramNameInFile = "Vgs";
            break;
        case 2:
                paramNameInFile = "Idss";
            break;
        case 3:
                paramNameInFile = "Igss";
                break;
        case 4:
                paramNameInFile = "Ciss";
                break;
        case 5:
                paramNameInFile = "Coss";
                break;
        case 6:
                paramNameInFile = "Crss";
                break;
        default:
                paramNameInFile = "ParamName";
            break;
    }
    emit paramNameInFileChanged(paramNameInFile); // send param name to MeasCtrl

}

 void CProberVisu::requestMeasurementControlData(void)
 {
     emit requesMeasCtrlData();
 }

 void CProberVisu::on_measurementControlData(QList<QList<CPosition>> _positionTable, double _zPreValue, double _zFinalValue)
 {


    positionVisu_00->getTextEditX()->setText(QString::number(_positionTable.value(0).value(0).getXpos()));
    positionVisu_00->getTextEditY()->setText(QString::number(_positionTable.value(0).value(0).getYpos()));

    positionVisu_01->getTextEditX()->setText(QString::number(_positionTable.value(0).value(1).getXpos()));
    positionVisu_01->getTextEditY()->setText(QString::number(_positionTable.value(0).value(1).getYpos()));

    positionVisu_02->getTextEditX()->setText(QString::number(_positionTable.value(0).value(2).getXpos()));
    positionVisu_02->getTextEditY()->setText(QString::number(_positionTable.value(0).value(2).getYpos()));

    positionVisu_10->getTextEditX()->setText(QString::number(_positionTable.value(1).value(0).getXpos()));
    positionVisu_10->getTextEditY()->setText(QString::number(_positionTable.value(1).value(0).getYpos()));

    positionVisu_11->getTextEditX()->setText(QString::number(_positionTable.value(1).value(1).getXpos()));
    positionVisu_11->getTextEditY()->setText(QString::number(_positionTable.value(1).value(1).getYpos()));

    positionVisu_12->getTextEditX()->setText(QString::number(_positionTable.value(1).value(2).getXpos()));
    positionVisu_12->getTextEditY()->setText(QString::number(_positionTable.value(1).value(2).getYpos()));

    positionVisu_20->getTextEditX()->setText(QString::number(_positionTable.value(2).value(0).getXpos()));
    positionVisu_20->getTextEditY()->setText(QString::number(_positionTable.value(2).value(0).getYpos()));

    positionVisu_21->getTextEditX()->setText(QString::number(_positionTable.value(2).value(1).getXpos()));
    positionVisu_21->getTextEditY()->setText(QString::number(_positionTable.value(2).value(1).getYpos()));

    positionVisu_22->getTextEditX()->setText(QString::number(_positionTable.value(2).value(2).getXpos()));
    positionVisu_22->getTextEditY()->setText(QString::number(_positionTable.value(2).value(2).getYpos()));

    m_zFinalPos = _zFinalValue;
    m_zPrePos = _zPreValue;
    textEdit_zFinalPos->setText(QString::number(_zFinalValue));
    textEdit_zPrePos->setText(QString::number(_zPreValue));
    

 }