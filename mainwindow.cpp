#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    serverIP = new QHostAddress();
    bisConnect = false;

    ui->setupUi(this);
    ui->sendButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sendButton_clicked()
{
    if(ui->TcpSendDataEdit->text() == "")
    {
        return;
    }
    QString msg = ui->TcpSendDataEdit->text();
    ui->textEdit->append(msg);
    tcpsocket->write(msg.toUtf8().data());
    ui->TcpSendDataEdit->clear();
}

void MainWindow::on_connectionButton_clicked()
{
    if(!bisConnect)
    {
        QString ip = "127.0.0.1";
        if(!serverIP->setAddress(ip))
        {
            qDebug()<<"connection error!!";
            return;
        }
        tcpsocket = new QTcpSocket(this);
        tcpsocket->connectToHost(*serverIP,8888);
        connect(tcpsocket,&QTcpSocket::connected,this,&MainWindow::slotconnectedsuccess);
        connect(tcpsocket,&QTcpSocket::readyRead,this,&MainWindow::slotreceive);
        bisConnect = true;
    }
}

void MainWindow::slotconnectedsuccess()
{
    ui->sendButton->setEnabled(true);
    QString strsucMsg = "connection sucess";
    ui->textEdit->append(strsucMsg);
}

void MainWindow::slotreceive()
{

}

void MainWindow::slotdisconnected()
{

}
