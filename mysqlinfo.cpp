#include "mysqlinfo.h"
#include "ui_mysqlinfo.h"
#include <QDebug>

MysqlInfo::MysqlInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MysqlInfo)
{
    ui->setupUi(this);
}

MysqlInfo::~MysqlInfo()
{
    delete ui;
}
void MysqlInfo::accept()
{
    this->HostName=this->ui->lineEditHost->text();
    this->DatabaseName=this->ui->lineEditDatabase->text();
    this->User=this->ui->lineEditUser->text();
    this->Pasword=this->ui->lineEditPassword->text();
    this->Port=this->ui->lineEditPort->text();

    this->done(1);
}
