#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("General Purpose Control");
    this->setWindowIcon(QIcon(":/res/tune.png"));
    connect(ui->actionSerial_Console, &QAction::triggered, this, &MainWindow::openSerialConsole);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openSerialConsole(){
    QMainWindow *serialConsoleWindow = new QMainWindow(this);
    serialConsoleWindow->setWindowTitle("Serial Console");
    serialConsoleWindow->setWindowIcon(QIcon(":/res/rs232.png"));
    serialConsoleWindow->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    SerialConsole *serialConsole = new SerialConsole(serialConsoleWindow);
    serialConsole->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    serialConsoleWindow->setCentralWidget(serialConsole);
    serialConsoleWindow->show();
}
