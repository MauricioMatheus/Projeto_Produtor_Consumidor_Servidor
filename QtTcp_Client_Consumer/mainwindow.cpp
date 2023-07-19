#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);


    connect(ui->pushButtonStart,
            SIGNAL(clicked(bool)),
            this,
            SLOT(putData()));

    connect(ui->pushButtonConnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));

    connect(ui->pushButtonDisconnect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpDisconnect()));

    connect(ui->pushButtonStop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopData()));
}

void MainWindow::tcpConnect(){
    socket->connectToHost(getHost(),1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }

}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
}


QString MainWindow::getHost(){
    QString ip;

    ip = ui->lineEdit->text();

    return ip;

}

void MainWindow::putData(){
    QString timeStr;

    timeStr = ui->time_label->text();
    timer = startTimer((timeStr.toInt())*1000);
}

void MainWindow::stopData(){
    killTimer(timer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

