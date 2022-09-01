#include "voucher.h"
#include "loannos.h"
#include <QDebug>
#include <Qtsql>
#include "LoanDetail.h"
#include <QtGui>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlTableModel>

QStandardItemModel *mdl;

Voucher::Voucher(QWidget *parent,int mode,int vid) :
    QDialog(parent){


    setupUi(this);

    QDoubleValidator *vl= new QDoubleValidator(lineEditAmount);
    vl->setNotation(QDoubleValidator::StandardNotation);
    vl->setDecimals(2);
    lineEditAmount->setValidator(vl);
    this->mode=mode;
    this->vid=vid;
    if (mode ==0){


        tableView->setVisible(false);
        pushButtonAdd->setVisible(false);
        cboLoan->setVisible(false);
        lineEditCust->setVisible(false);
        this->resize(this->width(),this->minimumHeight());
    }

    fillLoans();
     getID();
    mdl= new QStandardItemModel(this);
    tableView->setModel(mdl);


}
void Voucher::getID()
{
     QStringList connectionNames = QSqlDatabase::connectionNames();
       QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);
  //  db.open();
     if(mode==1){

             QSqlQuery query("",db);
             query.exec("Select Max(id) from voucher");
             query.next();
             int maxid;
             if (query.record().count()!=0){
                 qDebug()<<query.value(0).toInt();
                maxid= query.value(0).toInt()+1;
             }else{
                maxid=1;
             }
             qDebug()<<"sdas"<< maxid;
             QVariant nstr = QVariant(maxid);
             dateEdit->setDate(QDate::currentDate());
             lineEditID->setText(nstr.toString().prepend("VC0"));
            query.clear();
      }else{

             QSqlQuery qry("",db);
             QDate dt;
             qry.exec(QString("Select * from voucher where id=").append(QVariant(vid).toString()));
             qry.next();

             if(qry.isActive()){

                 lineEditID->setText(qry.value(0).toString().prepend("VC0"));
                 dt.setDate(qry.value(8).toInt(),qry.value(7).toInt(),qry.value(6).toInt());
                 dateEdit->setDate(dt);
                 qDebug()<<qry.value(1).toString();
                 cboLoan->setCurrentIndex(cboLoan->findText(qry.value(1).toString().prepend("LN0")));
                // qDebug()<<cboLoan->findText(qry.value(1).toString());
                 lineEditNo->setText(qry.value(2).toString());
                 cbodes->setCurrentIndex(cbodes->findText(qry.value(3).toString()));
                 lineEditAmount->setText(qry.value(5).toString());
                 cboDC->setCurrentIndex(cboDC->findText(qry.value(4).toString()));
                qry.clear();
             }
          }
}
void Voucher::fillLoans()
{
     LoanNos *model = new LoanNos();
      QStringList connectionNames = QSqlDatabase::connectionNames();
       QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);
   // db.open();
      model->setQuery("select id from loan",db);
     cboLoan->setModel(model);
     cboLoan->setModelColumn(0);
     QStandardItemModel *OptionlistModel = new QStandardItemModel(this);
     OptionlistModel->setItem(0,0,new QStandardItem("CASH RECD."));
     OptionlistModel->setItem(1,0,new QStandardItem("CASH GIVEN"));
     OptionlistModel->setItem(2,0,new QStandardItem("CHEQUE RECD."));
     OptionlistModel->setItem(3,0,new QStandardItem("CHEQUE GIVEN"));
     OptionlistModel->setItem(4,0,new QStandardItem("CHEQUE BOUNCE"));
     OptionlistModel->setItem(5,0,new QStandardItem("CHEQUE BOUNCE CHRG."));
     OptionlistModel->setItem(6,0,new QStandardItem("REPOSSESION CHRGS."));
     OptionlistModel->setItem(7,0,new QStandardItem("PENALTY"));
     OptionlistModel->setItem(8,0,new QStandardItem("PENALTY RECD."));
     OptionlistModel->setItem(9,0,new QStandardItem("DEALER PAYMENT"));
     cbodes->setModel(OptionlistModel);
     cbodes->setModelColumn(0);
}
void Voucher::save()
{
//    QSqlDatabase db2 =  QSqlDatabase::addDatabase("QSQLITE","mycon");
//    db2.setDatabaseName("Msvc+.dll");
//    db2.open();

  /*     QSqlTableModel model;
        model.setTable("voucher");
         model.setEditStrategy(QSqlTableModel::OnManualSubmit);
        model.select();
        */
//                  qDebug()<<model.rowCount();
   if (validate()){

       QStringList connectionNames = QSqlDatabase::connectionNames();
       QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);
    //    db.close();
     //     QSqlDatabase db2 =  QSqlDatabase::addDatabase("QSQLITE","new");
      //  db2.setDatabaseName("Msvc+.dll");
     if (!db.open()) {
                        qDebug() << "   ***ERROR - cannot open local database";
                        return;
                }


          db.transaction();
        QSqlQuery query(db);

     if(mode==1){

         int rc =mdl->rowCount();
           db.transaction();
         for (int i=0;i<rc;i++){

         // QDate dt;
         // dt = QDate::fromString(mdl->item(i,2)->text(),"dd/MM/yyyy");
          query.prepare("INSERT INTO `voucher`(ID,lnid,vno,des,dc,amount,datedy,datemn,dateyr) VALUES (?,?,?,?,?,?,?,?,?)");
          query.bindValue(0, mdl->item(i,0)->text().remove(0,2).toInt());
          query.bindValue(1, mdl->item(i,1)->text().remove(0,2).toInt());
          query.bindValue(2, mdl->item(i,3)->text());
          query.bindValue(3, mdl->item(i,4)->text());
          query.bindValue(4, mdl->item(i,5)->text());
          query.bindValue(5, mdl->item(i,6)->text());
         query.bindValue(6,dateEdit->date().day());
         query.bindValue(7,dateEdit->date().month());
         query.bindValue(8,dateEdit->date().year());

          qDebug()<<query.exec();

    qDebug()<<  query.lastError();
/*
        int row = model.rowCount();
        model.insertRows(row, 1);
        model.setData(model.index(row, 0), mdl->item(i,0)->text().remove(0,2).toInt());
        model.setData(model.index(row, 1), mdl->item(i,1)->text().remove(0,2).toInt());
        model.setData(model.index(row, 2), mdl->item(i,3)->text());
        model.setData(model.index(row, 3), mdl->item(i,4)->text());
        model.setData(model.index(row, 4), mdl->item(i,5)->text());
        model.setData(model.index(row, 5),mdl->item(i,6)->text());
        model.setData(model.index(row, 6),dt.day());
        model.setData(model.index(row,7), dt.month());
        model.setData(model.index(row,8), dt.year());
        model.submitAll();
*/
        //qDebug()<<model.query().lastQuery();
//        qDebug()<<model.lastError();
        }

         qDebug()<<  query.lastError();
     }else{


         query.prepare(QString("UPDATE voucher SET lnid = ?,vno = ?,des = ?,dc = ?,amount = ?,datedy = ?,datemn = ?,dateyr = ? where id = ").append(lineEditID->text().remove(0,2)));

         query.bindValue(0,cboLoan->currentText().remove(0,2).toInt());
         query.bindValue(1,lineEditNo->text());
         query.bindValue(2,cbodes->currentText());
         query.bindValue(3,cboDC->currentText());
         query.bindValue(4,lineEditAmount->text());
         query.bindValue(5,dateEdit->date().day());
         query.bindValue(6,dateEdit->date().month());
         query.bindValue(7,dateEdit->date().year());

       //  qDebug()<<  query.lastError();

         query.exec();
     //    qDebug()<<  query.lastError();
        // query.clear();

      }
  //   if(!db.commit())
 //    {
 //      qDebug()<<query.lastError().text();
 //        db.rollback();
 //    }
 // }
     //qDebug()<<query.lastError();
      //db.commit();
    //  db2.close();
     db.commit();
     accept();

      }

}
bool Voucher::validate()
{
    if(lineEditAmount->text().length()==0||lineEditNo->text().length()==0){

        return false;

    }else return true;
//cbodes->currentText().length()==0||
}

void Voucher::showDetail()
{

    QSqlQuery qry;
    QString str("select name,id from customer where id =(select custid from loan where id = ");
    str.append(cboLoan->currentText().remove(0,2));
    str.append(")");
    qry.exec(str);
    qry.next();
    qDebug()<<str;
    qDebug()<<qry.value(1);
    lineEditCust->setPlainText(qry.value(0).toString().append("   CS0").append(qry.value(1).toString()));
    qry.clear();
}
void Voucher::addVoucher()
{
   if (validate()){

       int rc=mdl->rowCount();
       mdl->setItem(rc,0,new QStandardItem(lineEditID->text()));
       mdl->setItem(rc,1,new QStandardItem(cboLoan->currentText()));
       mdl->setItem(rc,2,new QStandardItem(dateEdit->text()));
       mdl->setItem(rc,3,new QStandardItem(lineEditNo->text()));
       mdl->setItem(rc,4,new QStandardItem(cbodes->currentText()));
       mdl->setItem(rc,5,new QStandardItem(cboDC->currentText()));
       mdl->setItem(rc,6,new QStandardItem(lineEditAmount->text()));
       lineEditTotal->setText(QVariant(lineEditTotal->text().toDouble()+lineEditAmount->text().toDouble()).toString());
       lineEditID->setText(QVariant(lineEditID->text().remove(0,2).toInt()+1).toString().prepend("VC0"));
  }
}
