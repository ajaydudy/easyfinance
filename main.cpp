#include <QtGui/QApplication>
#include "myapp.h"
#include "mainwindow.h"
#include "login.h"
#include <Qtsql>
#include <qDebug>
#include <QMessageBox>
#include <QFile>
//#include <QtPlugin>
#include <windows.h>
#include <mysqlinfo.h>
 #include <QInputDialog>

void writeSettings(int day);
int readSettings();
bool created=false;
bool decrypt();
void encrypt();

int main(int argc, char *argv[])
{

//    Q_IMPORT_PLUGIN(qsqlite);
//    QByteArray line;
//    QFile file("Msvc+.dll");
//    file.open(QIODevice::ReadOnly);
//    line = file.readAll();
    //qDebug()<<"myapp init--"<<line.startsWith("SQLite");
 /*   QFile file ;
   if (!file.exists("lg"))
   {
       QFile file2("lg");
       file2.open(QIODevice::WriteOnly);
    //   file2.write("sdd");
       file2.close();
      // qDebug()<<file2.exists();
       created =true;
      // file2.close();

   }else{
              int msgboxID = MessageBox(
                NULL,
                (LPCWSTR)L"EasyFinance Already Running!",
                (LPCWSTR)L"Easyfinance",
                NULL
            );

       return 0;
   }*/
//    if(line.startsWith("SQLite"))
//    {
//        int msgboxID = MessageBox(
//                NULL,
//                (LPCWSTR)L"EasyFinance Already Running!",
//                (LPCWSTR)L"Easyfinance",
//                NULL
//            );

//        return 0;

//        //qApp->quit();
//      //  return true;

//    }
     MyApp a(argc, argv);
   // a.addLibraryPath("./sqldrivers");
      Q_INIT_RESOURCE(EasyFinance);

    int day =readSettings();

    if (day<1300)
    {
        writeSettings(day);

    }else{

        QMessageBox::information(0,"","Application Expired",QMessageBox::Ok);
        return 0;
    }

       // decrypt();

//    {
//        QMessageBox::information(0,"","Easyfinance already running!",QMessageBox::Ok);
//        return 0;
//    }
  /*  QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Msvc+.dll");
    db.setConnectOptions("QSQLITE_BUSY_TIMEOUT= 200");
    db.open();
*/

//    MysqlInfo my;

//  if(my.exec()==1)
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//  {
//    bool ok;
//        QString text = QInputDialog::getText(0,"Enter Mysql Root Password)",
//                                             "Enter Mysql root Password:", QLineEdit::Normal,
//                                            "password", &ok);
//   if (ok && !text.isEmpty())
          //  textLabel->setText(text);

    db.setHostName("127.0.0.1");
    db.setDatabaseName("easy");
    db.setUserName("root");
    //db.setPassword(text);
            //    db.setHostName(my.HostName);
//    db.setDatabaseName(my.DatabaseName);
//    db.setUserName(my.User);
   // db.setPassword("123");
    db.setPassword("rakesh#120");
   // db.setPassword("alqm106zp");

    //db.setPort(3306);
    db.open();

  //  qApp->setStyleSheet("QHeaderView { background-color: white }");
  // MainWindow w;
//   w.showMaximized();
     Login lg;
     lg.created=created;
     lg.show();


    return a.exec();
//}
//  return 0;
    //  a.processEvents();
 //}
}
void writeSettings(int day)
 {
     QSettings settings(QSettings::UserScope,"Microsoft", "Windows");
     day=day+1;
     settings.beginGroup("Install");
     settings.setValue("Run", day );
     settings.endGroup();
 }

int readSettings()
 {
     QSettings settings("Microsoft", "Windows");
     settings.beginGroup("Install");
     int margin = settings.value("Run").toInt();
     settings.endGroup();
     return margin;
 }
bool decrypt()
{

   QByteArray line;
   QFile file("Msvc+.dll");
   file.open(QIODevice::ReadOnly);
   line = file.readAll();
   //qDebug()<<line.startsWith("SQLite");

   if(line.startsWith("SQLite"))
   {
       return true;

   }else{

       QByteArray r("SQLite format 3");
       line.replace(0,15,r);
       file.close();
       file.remove("Msvc+.dll");
       QFile file2("Msvc+.dll");
       file2.open(QIODevice::WriteOnly);
       file2.write(line);
       file2.close();
       return false;
  }
}
void encrypt()
{

   QByteArray line;
   QFile file("Msvc+.dll");
   file.open(QIODevice::ReadOnly);
   line = file.readAll();
   QByteArray r("00haveahardfuck");
   line.replace(0,15,r);
   file.close();
   file.remove("Msvc+.dll");
   QFile file2("Msvc+.dll");
   file2.open(QIODevice::WriteOnly);
  // qDebug()<<file2.write(line);
   file2.close();


}
