#include "totalinterest.h"
#include "ui_totalinterest.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QtSql>
#include <QSqlTableModel>
#include <QDebug>
#include <QDate>

QStandardItemModel *model;
 
TotalInterest::TotalInterest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TotalInterest)
{
   //model = new QStandardItemModel();
    ui->setupUi(this);
    CalculateInterest();


}

TotalInterest::~TotalInterest()
{
    delete ui;
}
void TotalInterest::CalculateInterest()
{


    ui->lineEditTotal->clear();
    QSqlQuery qryTotalLoan;

    model = new QStandardItemModel();

    QStandardItemModel *modelview;
    QSqlQuery qryTotalInterest;
    QSqlQuery qryledger;

    QSqlDatabase::database().transaction();

    qryTotalLoan.exec("select count(*) from loan");
    qryTotalLoan.next();

    int TotalLoans;
    int TotalInterest=0;
    TotalLoans=qryTotalLoan.value(0).toInt();
    QString strTotInterest;
    //QSqlQuery qrydate;


    modelview = new QStandardItemModel();
     QStringList hdr;
        hdr <<"Loan No."<<"Interest";
        modelview->setHorizontalHeaderLabels(hdr);
 int totinterest=0;

    for(int i=1;i<=TotalLoans;i++)
    {

       totinterest=0;
        QDate datelast;
        FillLedger(i);
        //qDebug()     //  qrydate.exec("Select * from ledger where credit IS NOT NULL order by dateyr DESC,datemn DESC,datedy DESC LIMIT 1");
     //  qrydate.next();
        int rc=model->rowCount();

        int cramt=0;

        for(int j=rc-1;j>=0;j--){


           QString cr;
           cr.append(model->item(j,6)->text());

           if(cr.isNull()==false)
            {

            if(cr.contains("Cr"))
            {

                qDebug()<<"loan "<<i;
                datelast = datelast.fromString(model->item(j,0)->text(),"dd/MM/yyyy");
                qDebug()<<datelast;

                cr.chop(5);
                qDebug()<<"cr"<<cr;
                cramt = cramt + QVariant(cr).toInt();
                 qDebug()<<"cramt"<< QVariant(cramt).toInt();
                break;

            }else if(model->item(j,5)->text()!="0"){
                qDebug()<<"CASH";
                datelast = datelast.fromString(model->item(j,0)->text(),"dd/MM/yyyy");
                qDebug()<<datelast;
                break;
            }

         }
      }
        qDebug()<<datelast.isNull();
        qDebug()<<datelast;
       if( !datelast.isNull())
       {
            qDebug()<<"loanNo--"<< i;
       //qDebug()<<qrydate.value(0).toInt();
          // QDate dt;
          // dt.setDate(qrydate.value(2).toInt(),qrydate.value(1).toInt(),qrydate.value(0).toInt());
         //  qDebug()<<dt;
        strTotInterest.clear();

          strTotInterest.append("SELECT * FROM `ln0");
          strTotInterest.append(QVariant(i).toString());
//          strTotInterest.append("` where datedy <='");
//          strTotInterest.append(qrydate.value(0).toString());
//          strTotInterest.append("' AND dateyr<='");
//          strTotInterest.append(qrydate.value(2).toString());
//          strTotInterest.append("'AND datemn <'");
//          strTotInterest.append(qrydate.value(1).toString().append("' "));

          qryTotalInterest.exec(strTotInterest);






          while (qryTotalInterest.next())

           {

            if(QDate(qryTotalInterest.value(3).toInt(),qryTotalInterest.value(2).toInt(),qryTotalInterest.value(1).toInt())<=datelast)
             {
             //   qDebug()<<QDate(qryTotalInterest.value(2).toInt(),qryTotalInterest.value(1).toInt(),qryTotalInterest.value(0).toInt());
            //    qDebug()<<"sd"<<qryTotalInterest.value(6).toInt();
qDebug()<<QDate(qryTotalInterest.value(3).toInt(),qryTotalInterest.value(2).toInt(),qryTotalInterest.value(1).toInt());
qDebug()<<datelast;
                totinterest=totinterest + qryTotalInterest.value(6).toInt();
                qDebug()<<"totinterest"<<totinterest;
              }

                //qDebug()<<"hello";

               // model->setItem(i,1,new QStandardItem(QVariant(TotalInterest).toString());

           //qDebug()<<"interest"<<qryTotalInterest.value(0).toInt();

            }
                     if (cramt!=0)
                {
                   qDebug()<<qryTotalInterest.value(4).toInt();

                  if(cramt>=qryTotalInterest.value(4).toInt())
                     {
                       qDebug()<<"add" <<cramt;
                       totinterest=totinterest+cramt;
                     }

                  cramt=0;
          }

          TotalInterest=TotalInterest+totinterest;


//cramt=0;

      }
 qDebug()<<"i"<<i;
          modelview->setItem(i-1,0,new QStandardItem(QString("LN0").append(QVariant(i).toString())));
          modelview->setItem(i-1,1,new QStandardItem(QString(QVariant(totinterest).toString())));
          modelview->item(i-1,1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
          totinterest=0;


    }


    QSqlDatabase::database().commit();
    ui->tableView->setModel(modelview);
    this->ui->lineEditTotal->setText(QVariant(TotalInterest).toString());
}

void TotalInterest::FillLedger(int lnid)
{

// QSqlDatabase::database().transaction();

     QSqlQuery queryInsert;
     model->clear();

     //----------------add from schedule--------------

        QString str("select id,datedy,datemn,dateyr,emi from ");
        str.append("LN0").append(QVariant(abs(lnid)).toString());
        QSqlQuery querySchedule(str);
        querySchedule.exec();
        queryInsert.exec("delete from ledger");
        //queryInsert.clear();

       if ( querySchedule.isActive() ) {

        while (querySchedule.next())
         {

            queryInsert.prepare("INSERT INTO `ledger`(datedy,datemn,dateyr,des,debit) VALUES (?,?,?,?,?)");
            queryInsert.bindValue(0,querySchedule.value(1));
            queryInsert.bindValue(1,querySchedule.value(2));
            queryInsert.bindValue(2,querySchedule.value(3));
            queryInsert.bindValue(3,QString("INSTALLMENT ").append(querySchedule.value(0).toString()));
            queryInsert.bindValue(4,querySchedule.value(4));
            queryInsert.exec();

        }
       }

       //--------------------------------------------------------------
       //--------add from vouchers-------------------------------------

         str.clear();
         querySchedule.clear();
         str.append("select datedy,datemn,dateyr,des,vno,dc,amount,id from voucher where des != 'DEALER PAYMENT' And lnid= ");
         str.append(QVariant(abs(lnid)).toString());
         querySchedule.exec(str);
         queryInsert.clear();

        if ( querySchedule.isActive() ) {

         while (querySchedule.next())

          {

             queryInsert.prepare("INSERT INTO `ledger`(datedy,datemn,dateyr,des,chno,debit,credit,vno) VALUES (?,?,?,?,?,?,?,?)");
             queryInsert.bindValue(0,querySchedule.value(0));
             queryInsert.bindValue(1,querySchedule.value(1));
             queryInsert.bindValue(2,querySchedule.value(2));
             queryInsert.bindValue(3,querySchedule.value(3));
             queryInsert.bindValue(4,querySchedule.value(4));

             if(querySchedule.value(5).toString()=="Credit")

             {
                 queryInsert.bindValue(5,0);
                 queryInsert.bindValue(6,querySchedule.value(6));

             }else{

                 queryInsert.bindValue(6,0);
                 queryInsert.bindValue(5,querySchedule.value(6));
             }
                queryInsert.bindValue(7,querySchedule.value(7).toString());
                queryInsert.exec();
          }

        }
        //queryInsert.finish();
      //  QSqlDatabase::database().commit();
       //----------------view ledger-----------------------------------

        QString strAg("select csdy,csmn,csyr,emi,no,penalty from loan where id= ");
        strAg.append(QVariant(abs(lnid)).toString());
        QSqlQuery queryAgreed(strAg);

        double agamount;
        queryAgreed.exec();
        queryAgreed.next();
        agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();
        double tempStkBalance;
        double totalCredit=0.0;
        double totalDebit=0.0;

        QStringList hdr;
        hdr <<"Date"<<"Description"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance"<<"Stock Amount"<<"Stock Balance";
        model->setHorizontalHeaderLabels(hdr);
        QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
        model->setItem(0,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
        model->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        model->setItem(0,1,new QStandardItem("AGREED VALUE"));
      //model->item(0,7)->setTextAlignment(Qt::AlignVCenter);
        model->setItem(0,5,new QStandardItem("0"));
         model->setItem(0,6,new QStandardItem("0"));
        model->setItem(0,7,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
        model->item(0,7)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        model->setItem(0,8,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
        model->item(0,8)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        tempStkBalance=agamount;
//queryAgreed.clear();
        QSqlQuery queryLedger(QString("select * from ledger order by dateyr,datemn,datedy"));

        if ( queryLedger.isActive() ) {
        //    double totPenalty=0;
            while (queryLedger.next())

             {

             dt.setDate(queryLedger.value(2).toInt(),queryLedger.value(1).toInt(),queryLedger.value(0).toInt());
             if(dt<=QDate::currentDate())
              {

               model->setItem(queryLedger.at()+1,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
               model->item(queryLedger.at()+1,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
               model->setItem(queryLedger.at()+1,1,new QStandardItem(queryLedger.value(3).toString()));
              // model->item(queryLedger.at()+1,1)->setTextAlignment(Qt::AlignVCenter);
               if( queryLedger.value(4).toString()!=""){
               model->setItem(queryLedger.at()+1,2,new QStandardItem(queryLedger.value(4).toString().prepend("VC0")));
               model->item(queryLedger.at()+1,2)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
               }
               model->setItem(queryLedger.at()+1,3,new QStandardItem(queryLedger.value(5).toString()));
               model->item(queryLedger.at()+1,3)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
               model->setItem(queryLedger.at()+1,4,new QStandardItem(queryLedger.value(6).toString()));
               model->item(queryLedger.at()+1,4)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
               totalDebit=totalDebit+queryLedger.value(6).toDouble();
               model->setItem(queryLedger.at()+1,5,new QStandardItem(queryLedger.value(7).toString()));
               model->item(queryLedger.at()+1,5)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
               totalCredit=totalCredit+queryLedger.value(7).toDouble();

               if(totalCredit>totalDebit){
                 model->setItem(queryLedger.at()+1,6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0 Cr")));
               }else {
                 model->setItem(queryLedger.at()+1,6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0 Dr")));
               }

               if( totalCredit-totalDebit==0){
                   model->setItem(queryLedger.at()+1,6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0")));
               }

                model->item(queryLedger.at()+1,6)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                QString st(model->item(queryLedger.at()+1,1)->text());
                st.truncate(11);

               if(st=="INSTALLMENT" && model->item(queryLedger.at()+1,1)->text()!="INSTALLMENT RECD" ){

                  model->setItem(queryLedger.at()+1,7,new QStandardItem(queryLedger.value(6).toString().append(" Dr")));
                  model->item(queryLedger.at()+1,7)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
                  tempStkBalance = tempStkBalance - QVariant(queryLedger.value(6)).toDouble();

               }
               model->setItem(queryLedger.at()+1,8,new QStandardItem(QVariant(tempStkBalance).toString().append(" Dr")));
               model->item(queryLedger.at()+1,8)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
            }

           }
        }

        qDebug()<<"row"<<model->rowCount();

}

