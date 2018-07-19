#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <qtcpsocket.h>
#include <QHostAddress>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendButton_clicked();
    void slotconnectedsuccess();
    void slotreceive();
    void slotdisconnected();

    void on_connectionButton_clicked();

private:
    Ui::MainWindow *ui;
    QHostAddress *serverIP;
    QTcpSocket *tcpsocket;
    bool bisConnect;

};

#endif // MAINWINDOW_H
