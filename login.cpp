#include "login.h"
#include "mainwindow.h"
#include <QtSql>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent){
    setupUi(this);
   // this->setAttribute(Qt::WA_DeleteOnClose);
}

void Login::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        retranslateUi(this);
        break;
    default:
        break;
    }
}
void Login::closeEvent(QCloseEvent *event)
{

   // crypt();

}
void Login::accept()
{

 /*   if(checkOpenDatabase()==true)
    {
        MainWindow *w = new MainWindow();
        w->showMaximized();
        QDialog::accept();


           }else{
               QMessageBox::information(this,"EasyFinance","Invalid ID or password.Please try again");

    }
*/

    QSqlQuery qry;
    qry.exec("select name from users");
    QString usr;
    QString pass;
    usr=lineEditName->text();
    pass= lineEditPass->text();
    bool found;
    found=false;

    while (qry.next())
    {
       //  qDebug()<<qry.value(0).toString();
        if(qry.value(0).toString() == usr)
        {
            found=true;
        }

    }

    if(found==true)
    {
           qDebug()<<found;
           qry.exec(QString("select password from users where name = '").append(usr.trimmed()).append("'"));
           qry.last();

           if((qry.at()+1)!=0)
           {
               if(qry.value(0).toString()!= pass.trimmed())
               {
                  QMessageBox::information(this,"EasyFinance","Invalid ID or password.Please try again");
                  return;
               }
           }else{
               QMessageBox::information(this,"EasyFinance","Invalid ID or password.Please try again");
           }

           MainWindow *w = new MainWindow();
           w->showMaximized();
           QDialog::accept();


       }else{
           QMessageBox::information(this,"EasyFinance","Invalid ID or password.Please try again");
       }



}

void Login::reject()
{
    QDialog::reject();
    if(this->created==true){
        QFile file ;
        if (file.exists("lg"))
        {
            file.remove("lg");

        }


    }
    qApp->quit();
}
bool Login::checkOpenDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("easy");
    db.setUserName(lineEditName->text().trimmed());
    db.setPassword(lineEditPass->text().trimmed());

    if(!db.open())
    {

        return false;
     }else{
                return true;
    }

}
