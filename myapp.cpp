#include "myapp.h"
#include <QFile>
#include <QDate>
#include <qDebug>
#include <QDir>
#include <QMessageBox>
 void ChkInstance();
MyApp::MyApp(int &argc, char **argv):QApplication(argc,argv)
{
    connect(qApp,SIGNAL(aboutToQuit()),this,SLOT(startquit()));
  //  this->ChkInstance();
//    if (decrypt()==true)
//    {

//    }

}
MyApp::~MyApp()
{
  //   encrypt();
     //qDebug()<<"encypted";

}
void MyApp::startquit()
{

  //  encrypt();
  //  qDebug()<<"encypted";
}
void MyApp::encrypt()
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
   QDir dir("Backup");

   if (!dir.exists())
   {
       QDir dir2;
       dir2.mkdir("Backup");
   }

   QFile fileBackup(QString("Backup/").append(QDate::currentDate().toString("dd.MM.yyyy")));

   fileBackup.open(QIODevice::WriteOnly);
   file2.open(QIODevice::WriteOnly);
   file2.write(line);
   fileBackup.write(line);
   fileBackup.close();
   file2.close();


}
void ChkInstance()
{

   QByteArray line;
   QFile file("Msvc+.dll");
   file.open(QIODevice::ReadOnly);
   line = file.readAll();
   //qDebug()<<line.startsWith("SQLite");

   if(line.startsWith("SQLite"))
   {
       QMessageBox::information(0,"","Easyfinance already running!",QMessageBox::Ok);
       //return 0;
       QCoreApplication::exit(0);
     //  return true;

   }
//   else{

//       QByteArray r("SQLite format 3");
//       line.replace(0,15,r);
//       file.close();
//       file.remove("Msvc+.dll");
//       QFile file2("Msvc+.dll");
//       file2.open(QIODevice::WriteOnly);
//       file2.write(line);
//       file2.close();
//       return false;
  //}
}
