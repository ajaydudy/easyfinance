#include "gaurantor.h"
#include <QMessageBox>

Gaurantor::Gaurantor(QWidget *parent) :
    QDialog(parent){
    setupUi(this);
    QIntValidator *vl5= new QIntValidator(lineEditPhone);
    lineEditPhone->setValidator(vl5);
    getID();
}
Gaurantor::~Gaurantor(){}
void Gaurantor::changeEvent(QEvent *e)
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
bool Gaurantor::validate()
{

    if(lineEditName->text().length()==0||txtAddress->toPlainText().length()==0||lineEditPhone->text().length()==0){
        QMessageBox::information(this,"Easy Finance","Please enter all required(*) values",QMessageBox::Ok);
        return false ;
    }else{

        return true;
    }

}

void Gaurantor::Save()
{

   if (validate()){
    //   QStringList connectionNames = QSqlDatabase::connectionNames();
    //   QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

     // if(db.open()){

         QSqlQuery query("");

         query.exec("Select Max(id) from guarantor");

         query.next();

         int maxid;

         if (query.record().count()!=0){

             maxid= query.value(0).toInt()+1;

         }else{

            maxid=1;
         }

         QVariant nstr = QVariant(maxid);

          query.prepare("INSERT INTO `guarantor`(ID,name,address,phone,email) VALUES (?,?,?,?,?)");
          query.bindValue(0, nstr);
          query.bindValue(1,lineEditName->text());
          query.bindValue(2,txtAddress->toPlainText());
          query.bindValue(3,lineEditPhone->text());
          query.bindValue(4,lineEditEmail->text());
       //   qDebug()<<  query.lastError();
          query.exec();

        //qDebug()<<  query.lastError();

     //    db.close();
          QDialog::accept();


       }

  // }



}
void Gaurantor::getID()
{

    //   QStringList connectionNames = QSqlDatabase::connectionNames();
   //    QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

    //  if(db.open()){

        QSqlQuery query("");

         query.exec("Select Max(id) from guarantor");
         query.next();

         int maxid;

         if (query.record().count()!=0){
            maxid= query.value(0).toInt()+1;
         }else{

            maxid=1;
         }

        QVariant nstr = QVariant(maxid);
        lineEditID->setText(nstr.toString().prepend("GR0"));
  //  }

}
