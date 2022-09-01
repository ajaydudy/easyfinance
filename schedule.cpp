#include "schedule.h"
#include <QDebug>
#include <QDate>

Schedule::Schedule(QWidget *parent) :
    QDialog( parent), Ui::Schedule(){

    setupUi(this);

}
Schedule::~Schedule()
{

}
void Schedule::changeEvent(QEvent *e)
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
void Schedule::genSchedule(int a,float rt,int e,int n,int Yr,int Mn,int Day)
{

   QDate dt(Yr,Mn,Day);
   QStringList hdr;
   hdr <<"No"<<"Date"<<"EMI"<<"Principal"<<"Interest";
   model = new QStandardItemModel();
   model->setHorizontalHeaderLabels(hdr);
   int TempAmount=a;
   rt=rt/12;
   int totP=0;
   int totI=0;
   int Gtot=0;

   for(int i=0;i<n;i++){

       model->setItem(i,0,new QStandardItem(QVariant(i+1).toString()));
       model->item(i,0)->setTextAlignment(Qt::AlignRight);
       model->setItem(i,1,new QStandardItem(dt.toString("dd/MM/yyyy")));
       model->item(i,1)->setTextAlignment(Qt::AlignRight);
       model->setItem(i,2,new QStandardItem(QVariant(e).toString()));
       model->item(i,2)->setTextAlignment(Qt::AlignRight);
       model->setItem(i,3,new QStandardItem(QVariant(qRound((e-(rt/100)*TempAmount))).toString()));
       model->item(i,3)->setTextAlignment(Qt::AlignRight);
       model->setItem(i,4,new QStandardItem(QVariant(qRound((rt/100)*TempAmount)).toString()));
       model->item(i,4)->setTextAlignment(Qt::AlignRight);
       totP = totP+model->item(i,3)->data(Qt::DisplayRole).toString().toInt();
       totI = totI+model->item(i,4)->data(Qt::DisplayRole).toString().toInt();
       QDate TempDt(dt.addMonths(1));
       dt.setDate(TempDt.year(),TempDt.month(),TempDt.day());
       //qDebug()<<a;
       TempAmount = TempAmount - model->item(i,3)->data(Qt::DisplayRole).toString().toInt();
        qDebug()<<model->item(i,3)->data(Qt::DisplayRole).toString().toInt();
     //  qDebug()<<"a="<<a<<" "<<i;
     //  qDebug()<<"totp="<<totP;
   }

   if((totP-a)!=0){
   // qDebug()<<"not";
       if(totP>a){

           int diff =totP-a;
        //   qDebug()<<totP;
         //  qDebug()<<a;
           qDebug()<<"diff="<<diff;
           totP=totP-diff;
           totI=totI+diff;
           model->setItem(n-1,3,new QStandardItem(QVariant(model->item(n-1,3)->data(Qt::DisplayRole).toInt()-diff).toString()));
           model->setItem(n-1,4,new QStandardItem(QVariant(model->item(n-1,4)->data(Qt::DisplayRole).toInt()+diff).toString()));
           model->item(n-1,3)->setTextAlignment(Qt::AlignRight);
           model->item(n-1,4)->setTextAlignment(Qt::AlignRight);

       }else{

           int diff =a-totP;
           totP=totP+diff;
           totI=totI-diff;
           model->setItem(n-1,3,new QStandardItem(QVariant(model->item(n-1,3)->data(Qt::DisplayRole).toInt()+diff).toString()));
           model->setItem(n-1,4,new QStandardItem(QVariant(model->item(n-1,4)->data(Qt::DisplayRole).toInt()-diff).toString()));
           model->item(n-1,3)->setTextAlignment(Qt::AlignRight);
           model->item(n-1,4)->setTextAlignment(Qt::AlignRight);

       }
   }

    Gtot=totP+totI;
    lineEditTotI->setText(QVariant(totI).toString());
    lineEditTotP->setText(QVariant(totP).toString());
    lineEditGtot->setText(QVariant(Gtot).toString());
    tableView->setModel(model);
    tableView->setColumnWidth(0,25);
    tableView->resizeRowsToContents();

}
/*void Schedule::setValues(QString a,QString rt,QString e,QString n)
{
       Emi=e;
       NoEmi=n;
       rate=rt;
       amount=a;


}*/
