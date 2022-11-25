#include "widget.h"
#include "ui_widget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostInfo>
#include <QString>
#include <QMessageBox>


Widget::Widget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    min_Server = new QTcpServer;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString hostName = QHostInfo::localHostName();
    QHostInfo info = QHostInfo::fromName(hostName);
    QList<QHostAddress> address_min = info.addresses();
    ui->textEdit->append(hostName);
    QHostAddress address;
    foreach(address, address_min) {
        ui->textEdit->append("*********");
        ui->textEdit->append(address.toString());
    }

}

void Widget::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().isEmpty())
        return;
    int min_Port = ui->lineEdit->text().toInt();
    bool flag = min_Server->listen(QHostAddress::Any,min_Port);
    if(flag){
        QMessageBox::information(this,"提示","监听成功");
        connect(min_Server,&QTcpServer::newConnection,this,[=](){
            min_Socket = min_Server->nextPendingConnection();

        connect(min_Socket,&QTcpSocket::readyRead,this,[=](){
            char str[1024]={0};
            min_Socket->read(str,sizeof str);
            ui->textEdit_2->append(str);
        });
    });
}
}
