#include "loandialog.h"
#include "schedule.h"
#include "gaurantor.h"
#include "CustomerDialog.h"
#include "dealer.h"
#include <QTreeView>
#include <QTreeWidget>
#include <QtSql>
#include <QtGui>
#include <math.h>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QSplashScreen>
#include "messagedialog.h"

LoanDialog::LoanDialog(QWidget *parent,int mode,int lnid) :
    QDialog(parent){

    setupUi(this);
    dateEditStart->setDate(QDate::currentDate());
    dateEditCase->setDate(QDate::currentDate());
    fillComboCust();
    fillComboGr();
    fillComboDl();
    setCompleter();
    this->mode=mode;
    this->lnid=lnid;
    getID();
    QDoubleValidator *vl= new QDoubleValidator(lineEditCost);
    vl->setNotation(QDoubleValidator::StandardNotation);
    vl->setDecimals(2);
    lineEditCost->setValidator(vl);
    QDoubleValidator *vl2= new QDoubleValidator(lineEditAmount);
    vl2->setNotation(QDoubleValidator::StandardNotation);
    vl2->setDecimals(2);
    lineEditAmount->setValidator(vl2);
    QDoubleValidator *vl8= new QDoubleValidator(lineEditDlPayment);
    vl8->setNotation(QDoubleValidator::StandardNotation);
    vl8->setDecimals(2);
    lineEditDlPayment->setValidator(vl8);

    QIntValidator *vl4= new QIntValidator(lineEditEMI);
    lineEditEMI->setValidator(vl4);
    QIntValidator *vl5= new QIntValidator(lineEditNoEMI);
    lineEditNoEMI->setValidator(vl5);
    QIntValidator *vl6= new QIntValidator(lineEditPfrom);
    lineEditPfrom->setValidator(vl6);
    QIntValidator *vl7= new QIntValidator(lineEditPto);
    lineEditPto->setValidator(vl7);


}
QString LoanDialog::getFlatRate()
{
    float E ;
    float P ;
    float N ;
    float r;

    if(radioButtonDaily->isChecked())
   {

      E = lineEditEMI->text().toFloat()*30;
      P = lineEditAmount->text().toFloat();
      N = lineEditNoEMI->text().toFloat()/30;

    }else if(radioButtonWeekly->isChecked()){
      E = lineEditEMI->text().toFloat()*4;
      P = lineEditAmount->text().toFloat();
      N = lineEditNoEMI->text().toFloat()/4;

    }else if(radioButtonMonthly->isChecked()){
      E = lineEditEMI->text().toFloat();
      P = lineEditAmount->text().toFloat();
      N = lineEditNoEMI->text().toFloat();

   }
    r=(((E*N)-P)*1200)/(P*N);
    QString str;
    str = QVariant(r).toString();
    str.truncate(5);
    return str;

}
QString LoanDialog::getReducingRate()
{

   /* EMI Formula: l x r [(1+r)n /(1+r)n-1 ] x 1/12
    l = loan amount
    r = rate of interest
    n = term of the loan
    */
    //float rate;E = P×r×(1 + r)n/((1 + r)n - 1)
    int p =QVariant(lineEditAmount->text()).toInt();
    float r=0;
    int n=QVariant(lineEditNoEMI->text()).toInt();
    int emi=lineEditEMI->text().toInt();

    QString str;

    for( int i=1;i<=200;i++){
        for(int j=0;j<=9;j++){
             float temp;
             temp=r;
             for(int k=0;k<=9;k++){
                r = QVariant(r).toString().append(".").append(QVariant(j).toString()).append(QVariant(k).toString()).toFloat();
                if(emi==qRound( p * (r/1200) / (1 -(pow(1/(1 + (r/1200)), n))))){
                     str = QVariant(r).toString();
                     str.truncate(5);
                }
                r=temp;
             }
        }
        r=r+1;
    }
    return (str);
}

bool LoanDialog::validate()
{
    if(lineEditAmount->text().length()==0||lineEditCost->text().length()==0||lineEditHire->text().length()==0||lineEditEMI->text().length()==0||lineEditNoEMI->text().length()==0){
        QMessageBox::information(this,"Easy Finance","Please enter all required(*) values",QMessageBox::Ok);
        return false ;
    }else{

        return true;
    }
}

void LoanDialog::showSchedule()
{

   if (validateEmi()){
       Schedule *sc = new Schedule(this);
       int Emi=lineEditEMI->text().toInt();
       int NoEmi=lineEditNoEMI->text().toInt();
       float rate=lineEditReducing->text().toFloat();
       int amount=lineEditAmount->text().toInt();
       qDebug()<<amount;
       sc->genSchedule(amount,rate,Emi,NoEmi,dateEditStart->date().year(),dateEditStart->date().month(),dateEditStart->date().day());
       sc->exec();
       delete sc;

  }else{

           //QMessageBox::information(this,"EasyFinance","Please enter values! ",QMessageBox::Ok);
       }
}
void LoanDialog::showList()
{

    cboName->showPopup();
    //cboName;


}

void LoanDialog::showGuarantor()
{
    Gaurantor *gr = new Gaurantor(this);
    gr->exec();
    fillComboGr();
    delete gr;
}
void LoanDialog::showDealer()
{
    Dealer *dl = new Dealer(this);
    dl->exec();
    fillComboDl();
    delete dl;
}
void LoanDialog::calculateRate()
{
   if (checkEmi()){
    if(lineEditAmount->text().length()!=0 && lineEditEMI->text().length()!=0 && lineEditNoEMI->text().length()!=0){
        // qDebug()<<(lineEditAmount->text().length()!=0||lineEditEMI->text().length()!=0||lineEditNoEMI->text().length()!=0);
         lineEditReducing->setText(getReducingRate());
         lineEditIR->setText(getFlatRate());
     }
  }else{
         lineEditReducing->setText("");
         lineEditIR->setText("");
     }
  lineEditDlPayment->setText(lineEditAmount->text());
}
bool LoanDialog::checkEmi()
{

    if(lineEditEMI->text().toInt()*lineEditNoEMI->text().toFloat()>lineEditAmount->text().toInt()){
        return true;
    }else{
         lineEditIR->setText("");
         lineEditReducing->setText("");
         return false;
    }

}
bool LoanDialog::validateEmi()
{
    if(lineEditAmount->text().length()!=0 && lineEditEMI->text().length()!=0 && lineEditNoEMI->text().length()!=0&& lineEditReducing->text().length()!=0){
        return true;
    }else{

        return false;
    }
}

double LoanDialog::roundh(double number,int place)
{

return 0;
}
void LoanDialog::showCustomer()
{

    CustomerDialog *cd =new CustomerDialog(this,1,0);
    cd->exec();
    fillComboCust();
    cboName->setCurrentIndex(cboName->model()->rowCount()-1);
    delete cd;

}
void LoanDialog::setFinishDate()
{

    dateEditFinish->setDate(dateEditStart->date().addMonths(lineEditNoEMI->text().toInt()-1));

}
void LoanDialog::fillComboCust()
{

     QStandardItemModel *model=new QStandardItemModel();
     QStringList connectionNames = QSqlDatabase::connectionNames();
     QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

     if(db.open()){

          QSqlQuery query("",db);
          query.exec("SELECT id,name FROM Customer");

          qDebug()<<  query.lastError();

          if ( query.isActive() ) {

              while ( query.next() ) {

                   model->setItem(query.at(),0, new QStandardItem( query.value(1).toString()));
                   model->setItem(query.at(),1, new QStandardItem("CS0"+query.value(0).toString()));

                  }
           }
      }

    QTreeView *treeWidget = new QTreeView;
    treeWidget->setModel(model);
    treeWidget->setRootIsDecorated(false);
    treeWidget->header()->hide();
    treeWidget->header()->setStretchLastSection(false);
    treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
    treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
    cboName->setModel(treeWidget->model());
    cboName->setView(treeWidget);


}

void LoanDialog::fillComboGr()
{

     QStandardItemModel *model=new QStandardItemModel();
     QStringList connectionNames = QSqlDatabase::connectionNames();
     //QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

   //  if(db.open()){

           QSqlQuery query("");
           query.exec("SELECT id,name FROM guarantor");
           qDebug()<<  query.lastError();

          if ( query.isActive() ) {

              while ( query.next() ) {

                     model->setItem(query.at(),0, new QStandardItem( query.value(1).toString()));
                     model->setItem(query.at(),1, new QStandardItem("GR0"+query.value(0).toString()));

                   }
           }
    //  }

    QTreeView *treeWidget = new QTreeView;
    treeWidget->setModel(model);

    treeWidget->setRootIsDecorated(false);
    treeWidget->header()->hide();
    treeWidget->header()->setStretchLastSection(false);
    treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
    treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
    cbogrntr->setModel(treeWidget->model());
    cbogrntr->setView(treeWidget);

}
void LoanDialog::fillComboDl()
{

     QStandardItemModel *model=new QStandardItemModel();
     QStringList connectionNames = QSqlDatabase::connectionNames();
     QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

     if(db.open()){

           QSqlQuery query("",db);
           query.exec("SELECT id,name FROM dealer");
           qDebug()<<  query.lastError();

          if ( query.isActive() ) {

              while ( query.next() ) {

                     model->setItem(query.at(),0, new QStandardItem( query.value(1).toString()));
                     model->setItem(query.at(),1, new QStandardItem("DL0"+query.value(0).toString()));

                   }
           }
      }

    QTreeView *treeWidget = new QTreeView;
    treeWidget->setModel(model);

    treeWidget->setRootIsDecorated(false);
    treeWidget->header()->hide();
    treeWidget->header()->setStretchLastSection(false);
    treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
    treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
    cboDealer->setModel(treeWidget->model());
    cboDealer->setView(treeWidget);

}
void LoanDialog::getID()
{

   //    QStringList connectionNames = QSqlDatabase::connectionNames();
     //  QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

      //if(db.open()){

         if(mode==1){

             QSqlQuery query;
             query.exec("Select Max(id) from loan");
             query.next();
             int maxid;
             if (query.record().count()!=0){
                maxid= query.value(0).toInt()+1;
             }else{
                maxid=1;
             }
             QVariant nstr = QVariant(maxid);
             lineEditID->setText(nstr.toString().prepend("LN0"));

         }else{

             QSqlQuery qryCust;
             QSqlQuery qryGrntr;
             QSqlQuery qryDealer;
             QSqlQuery qry;
             QDate dt;
             qry.exec(QString("Select * from loan where id=").append(QVariant(lnid).toString()));
             qry.next();

             if(qry.isActive()){
                //qDebug()<<"act";
                 lineEditID->setText(qry.value(0).toString().prepend("LN0"));
                 dt.setDate(qry.value(3).toInt(),qry.value(2).toInt(),qry.value(1).toInt());
                 dateEditCase->setDate( dt);
                 qryCust.exec(QString("select name from customer where id= ").append(qry.value(4).toString()));
                 qryCust.next();
                 cboName->setCurrentIndex(cboName->findText(qryCust.value(0).toString()));
                 cboType->setCurrentIndex(cboType->findText(qry.value(5).toString()));
                 qryGrntr.exec(QString("select name from guarantor where id= ").append(qry.value(6).toString()));
                 qryGrntr.next();
                 cbogrntr->setCurrentIndex(cbogrntr->findText(qryGrntr.value(0).toString()));
                 lineEditCost->setText(QVariant(qRound(qry.value(7).toDouble())).toString());
                 lineEditHire->setText(QVariant(qRound(qry.value(8).toDouble())).toString());
                 lineEditAmount->setText(QVariant(qRound(qry.value(9).toDouble())).toString());
                 lineEditEMI->setText(QVariant(qRound(qry.value(10).toDouble())).toString());
                 lineEditNoEMI->setText(qry.value(11).toString());
                 lineEditIR->setText(qry.value(12).toString());
                 lineEditReducing->setText(qry.value(13).toString());
                 dt.setDate(qry.value(16).toInt(),qry.value(15).toInt(),qry.value(14).toInt());
                 dateEditStart->setDate(dt);
                 dt.setDate(qry.value(19).toInt(),qry.value(18).toInt(),qry.value(17).toInt());
                 dateEditFinish->setDate(dt);
                    qryDealer.exec(QString("select name from dealer where id=").append(qry.value(20).toString()));
                    qryDealer.next();
                 cboDealer->setCurrentIndex(cboDealer->findText(qryDealer.value(0).toString()));
                 lineEditVh->setText(qry.value(21).toString());
                 lineEditReg->setText(qry.value(22).toString());
                 lineEditCh->setText(qry.value(23).toString());
                 lineEditEng->setText(qry.value(24).toString());
                 lineEditPfrom->setText(qry.value(25).toString());
                 lineEditPto->setText(qry.value(26).toString());
                 lineEditBK->setText(qry.value(27).toString());
                 lineEditGRfile->setText(qry.value(28).toString());
                 spinBoxPenalty->setValue(qry.value(31).toInt());
                 lineEditDlPayment->setText(qry.value(29).toString());
                 if(qry.value(32).toInt()==0){
                     checkBox->setCheckState(Qt::Unchecked);
                 }else{

                     checkBox->setCheckState(Qt::Checked);
                 }
             }
          }
   // }

}
void LoanDialog::save()
{

    QPixmap pixmap(":/new/prefix1/images/wait.jpg");
   // qDebug()<<pixmap.size();
    QSplashScreen splash(pixmap);
    //qDebug()<< splash.show();
 //   splash.raise();
  //  qApp->processEvents();
   if(QMessageBox::question(this,"Easy Finance","Do you want to save this loan ?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes){


       if (validate()){
        QPixmap pixmap(":/new/prefix1/images/wait.jpg");
       // qDebug()<<pixmap.size();
        QSplashScreen splash(pixmap);
        splash.show();
     //   splash.raise();
        qApp->processEvents();

         messageDialog *msg= new messageDialog(this);
         msg->setWindowFlags(Qt::SplashScreen|Qt::WindowStaysOnTopHint);
         msg->show();
         qApp->setOverrideCursor(Qt::BusyCursor);
//       QStringList connectionNames = QSqlDatabase::connectionNames();
  //     QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

    //  if(db.open()){
        if(mode==1){
          QSqlQuery query("");
          query.exec("Select Max(id) from loan");
          query.next();

         int maxid;

         if (query.record().count()!=0){
           maxid= query.value(0).toInt()+1;
         }else{

            maxid=1;
         }

         QVariant nstr = QVariant(maxid);

          query.prepare("INSERT INTO `loan`(ID,csdy,csmn,csyr,custid,type,grntr,cost,hire,amount,emi,no,flrate,rdrate,startdy,startmn,startyr,enddy,endmn,endyr,dealer,vhname,regno,chno,engno,pdcfrom,pdcto,pdcbk,grfile,penalty,dlramt,closed) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
          query.bindValue(0,nstr);
          query.bindValue(1,dateEditCase->date().day());
          query.bindValue(2,dateEditCase->date().month());
          query.bindValue(3,dateEditCase->date().year());
          query.bindValue(4,CsID);
          query.bindValue(5,cboType->currentText());
          query.bindValue(6,GrID);
          query.bindValue(7,lineEditCost->text().trimmed());
          query.bindValue(8,lineEditHire->text().trimmed());
          query.bindValue(9,lineEditAmount->text().trimmed());
          query.bindValue(10,lineEditEMI->text().trimmed());
          query.bindValue(11,lineEditNoEMI->text().trimmed());
          query.bindValue(12,lineEditIR->text().trimmed());
          query.bindValue(13,lineEditReducing->text().trimmed());
          query.bindValue(14,dateEditStart->date().day());
          query.bindValue(15,dateEditStart->date().month());
          query.bindValue(16,dateEditStart->date().year());
          query.bindValue(17,dateEditFinish->date().day());
          query.bindValue(18,dateEditFinish->date().month());
          query.bindValue(19,dateEditFinish->date().year());
          query.bindValue(20,DliD);
          query.bindValue(21,lineEditVh->text().trimmed());
          query.bindValue(22,lineEditReg->text().trimmed());
          query.bindValue(23,lineEditCh->text().trimmed());
          query.bindValue(24,lineEditEng->text().trimmed());
          query.bindValue(25,lineEditPfrom->text().trimmed());
          query.bindValue(26,lineEditPto->text().trimmed());
          query.bindValue(27,lineEditBK->text().trimmed());
          query.bindValue(28,lineEditGRfile->text().trimmed());
          query.bindValue(29,spinBoxPenalty->value());
          query.bindValue(30,lineEditDlPayment->text().trimmed());

          if (checkBox->isChecked())
          {
                query.bindValue(31,1);
          }else{
                query.bindValue(31,0);
          }

       //   qDebug()<<  query.lastError();
          query.exec();
      //    qDebug()<<  query.lastError();
         /* QSqlQuery qry2;
          qry2.prepare("INSERT INTO `dealerledger`(lnid,dlid,dtdy,dtmm,dtyy,debit,credit,balance)VALUES(?,?,?,?,?,?,?,?");
          qry2.bindValue(0,lineEditID->text().trimmed());
          qry2.bindValue(1,DliD);
          qry2.bindValue(2,dateEditCase->date().day());
          qry2.bindValue(3,dateEditCase->date().month());
          qry2.bindValue(4,dateEditCase->date().year());
*/
      }else{

          QSqlQuery query("");

          query.prepare(QString("UPDATE LOAN SET csdy = ?,csmn = ?,csyr = ?,custid = ?,type = ?,grntr = ?,cost = ?,hire = ?,amount =?,emi = ?,no = ?,flrate = ?,rdrate =?,startdy = ?,startmn = ?,startyr = ?,enddy = ?,endmn = ?,endyr = ?,dealer = ?,vhname = ?,regno = ?,chno = ?,engno = ?,pdcfrom = ?,pdcto = ?,pdcbk = ?,grfile = ?,penalty = ?,dlramt = ?,closed = ? WHERE id = ").append(lineEditID->text().remove(0,2)));
          query.bindValue(0,dateEditCase->date().day());
          query.bindValue(1,dateEditCase->date().month());
          query.bindValue(2,dateEditCase->date().year());
          query.bindValue(3,CsID);
          query.bindValue(4,cboType->currentText());
          query.bindValue(5,GrID);
          query.bindValue(6,lineEditCost->text().trimmed());
          query.bindValue(7,lineEditHire->text().trimmed());
          query.bindValue(8,lineEditAmount->text().trimmed());
          query.bindValue(9,lineEditEMI->text().trimmed());
          query.bindValue(10,lineEditNoEMI->text().trimmed());
          query.bindValue(11,lineEditIR->text().trimmed());
          query.bindValue(12,lineEditReducing->text().trimmed());
          query.bindValue(13,dateEditStart->date().day());
          query.bindValue(14,dateEditStart->date().month());
          query.bindValue(15,dateEditStart->date().year());
          query.bindValue(16,dateEditFinish->date().day());
          query.bindValue(17,dateEditFinish->date().month());
          query.bindValue(18,dateEditFinish->date().year());
          query.bindValue(19,DliD);
          query.bindValue(20,lineEditVh->text().trimmed());
          query.bindValue(21,lineEditReg->text().trimmed());
          query.bindValue(22,lineEditCh->text().trimmed());
          query.bindValue(23,lineEditEng->text().trimmed());
          query.bindValue(24,lineEditPfrom->text().trimmed());
          query.bindValue(25,lineEditPto->text().trimmed());
          query.bindValue(26,lineEditBK->text().trimmed());
          query.bindValue(27,lineEditGRfile->text().trimmed());
          query.bindValue(28,spinBoxPenalty->value());
          query.bindValue(29,lineEditDlPayment->text().trimmed());
          if (checkBox->isChecked())
          {
                query.bindValue(30,1);
          }else{
                query.bindValue(30,0);
          }
          qDebug()<<  query.lastError();
          query.exec();

          qDebug()<<  query.lastError();
          query.exec(QString("Drop table ").append(lineEditID->text()));
         //  qDebug()<<  query.lastError();
        }
    //    db.close();
          GenSaveSchedule();
          delete msg;
          accept();
       }

 //  }

   qApp->restoreOverrideCursor();

}

}
void LoanDialog::getGrID()
{

  QStandardItemModel *mdl=static_cast<QStandardItemModel*>(cbogrntr->model());
  GrID=mdl->item(cbogrntr->currentIndex(),1)->data(0).toString().remove(0,2).toInt();
 // qDebug()<<"GrID";

}
void LoanDialog::getDlID()
{

  QStandardItemModel *mdl=static_cast<QStandardItemModel*>(cboDealer->model());
  DliD=mdl->item(cboDealer->currentIndex(),1)->data(0).toString().remove(0,2).toInt();
 // qDebug()<<"dlID";

}
void LoanDialog::getCsID()
{

  QStandardItemModel *mdl=static_cast<QStandardItemModel*>(cboName->model());
  CsID=mdl->item(cboName->currentIndex(),1)->data(0).toString().remove(0,2).toInt();
  //qDebug()<<"CsID";

}
void LoanDialog::showPopup()
{
    cboName->showPopup();
}
void LoanDialog::GenSaveSchedule()
{

      QStringList connectionNames = QSqlDatabase::connectionNames();
      QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

     if(db.open()){

         QSqlQuery query;

            QString str("CREATE TABLE ");
            str.append(lineEditID->text());
            str.append("(`id` INTEGER, `datedy` INTEGER ,`datemn` INTEGER,`dateyr` INTEGER,`emi` INTEGER,`P` INTEGER,`I` INTEGER)");
            query.exec(str);
      //      qDebug()<<"table"<<query.lastError();
       }

       int Emi=lineEditEMI->text().toInt();
       int NoEmi=lineEditNoEMI->text().toInt();
       float rate=lineEditReducing->text().toFloat();
       int amount=lineEditAmount->text().toInt();

     SaveSchedule(schedule(amount,rate,Emi,NoEmi,dateEditStart->date().year(),dateEditStart->date().month(),dateEditStart->date().day()));
}

QStandardItemModel* LoanDialog::schedule(int a,float rt,int e,int n,int Yr,int Mn,int Day)
{

   QStandardItemModel *model = new QStandardItemModel();

//   QDate dt(Yr,Mn,Day);

//   int TempAmount=a;

//   rt=rt/12;
//   float totP;
//   float totI;


//   for(int i=0;i<n;i++){

//       model->setItem(i,0,new QStandardItem(QVariant(i+1).toString()));
//       model->item(i,0)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,1,new QStandardItem(QVariant(dt.day()).toString()));
//       model->item(i,1)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,2,new QStandardItem(QVariant(dt.month()).toString()));
//       model->item(i,2)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,3,new QStandardItem(QVariant(dt.year()).toString()));
//       model->item(i,3)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,4,new QStandardItem(QVariant(e).toString()));
//       model->item(i,4)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,5,new QStandardItem(QVariant(qRound(e-((rt/100)*TempAmount))).toString()));
//       model->item(i,5)->setTextAlignment(Qt::AlignRight);
//       model->setItem(i,6,new QStandardItem(QVariant(qRound((rt/100)*TempAmount)).toString()));
//       model->item(i,6)->setTextAlignment(Qt::AlignRight);
//       totP = totP+model->item(i,5)->data(Qt::DisplayRole).toString().toFloat();
//       totI = totI+model->item(i,6)->data(Qt::DisplayRole).toString().toFloat();
//       QDate TempDt(dt.addMonths(1));
//       dt.setDate(TempDt.year(),TempDt.month(),TempDt.day());
//       TempAmount=TempAmount - model->item(i,5)->data(Qt::DisplayRole).toString().toFloat();

//   }

//   if((totP-a)!=0){

//       if(totP>a){

//           int diff =totP-a;
//           totP=totP-diff;
//           totI=totI+diff;
//           model->setItem(n-1,5,new QStandardItem(QVariant(model->item(n-1,5)->data(Qt::DisplayRole).toInt()-diff).toString()));
//           model->setItem(n-1,6,new QStandardItem(QVariant(model->item(n-1,6)->data(Qt::DisplayRole).toInt()+diff).toString()));
//           model->item(n-1,5)->setTextAlignment(Qt::AlignRight);
//           model->item(n-1,6)->setTextAlignment(Qt::AlignRight);

//       }else{

//           int diff =totP-a;
//           totP=totP-diff;
//           totI=totI+diff;
//           model->setItem(n-1,5,new QStandardItem(QVariant(model->item(n-1,5)->data(Qt::DisplayRole).toInt()+diff).toString()));
//           model->setItem(n-1,6,new QStandardItem(QVariant(model->item(n-1,6)->data(Qt::DisplayRole).toInt()-diff).toString()));
//           model->item(n-1,5)->setTextAlignment(Qt::AlignRight);
//           model->item(n-1,6)->setTextAlignment(Qt::AlignRight);

//       }
//   }

    QDate dt(Yr,Mn,Day);
    QStringList hdr;
    hdr <<"No"<<"Date"<<"EMI"<<"Principal"<<"Interest";
   // model = new QStandardItemModel();
    model->setHorizontalHeaderLabels(hdr);
    int TempAmount=a;
    rt=rt/12;
    int totP=0;
    int totI=0;
  //  int Gtot=0;

    for(int i=0;i<n;i++){

        model->setItem(i,0,new QStandardItem(QVariant(i+1).toString()));
        model->item(i,0)->setTextAlignment(Qt::AlignRight);
   model->setItem(i,1,new QStandardItem(QVariant(dt.day()).toString()));
   model->item(i,1)->setTextAlignment(Qt::AlignRight);
   model->setItem(i,2,new QStandardItem(QVariant(dt.month()).toString()));
   model->item(i,2)->setTextAlignment(Qt::AlignRight);
   model->setItem(i,3,new QStandardItem(QVariant(dt.year()).toString()));
   model->item(i,3)->setTextAlignment(Qt::AlignRight);
        model->setItem(i,4,new QStandardItem(QVariant(e).toString()));
        model->item(i,4)->setTextAlignment(Qt::AlignRight);
        model->setItem(i,5,new QStandardItem(QVariant(qRound((e-(rt/100)*TempAmount))).toString()));
        model->item(i,5)->setTextAlignment(Qt::AlignRight);
        model->setItem(i,6,new QStandardItem(QVariant(qRound((rt/100)*TempAmount)).toString()));
        model->item(i,6)->setTextAlignment(Qt::AlignRight);
        totP = totP+model->item(i,5)->data(Qt::DisplayRole).toString().toInt();
        totI = totI+model->item(i,6)->data(Qt::DisplayRole).toString().toInt();
        QDate TempDt(dt.addMonths(1));
        dt.setDate(TempDt.year(),TempDt.month(),TempDt.day());
        //qDebug()<<a;
        TempAmount = TempAmount - model->item(i,5)->data(Qt::DisplayRole).toString().toInt();
       //  qDebug()<<model->item(i,3)->data(Qt::DisplayRole).toString().toInt();
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
            model->setItem(n-1,5,new QStandardItem(QVariant(model->item(n-1,5)->data(Qt::DisplayRole).toInt()-diff).toString()));
            model->setItem(n-1,6,new QStandardItem(QVariant(model->item(n-1,6)->data(Qt::DisplayRole).toInt()+diff).toString()));
            model->item(n-1,5)->setTextAlignment(Qt::AlignRight);
            model->item(n-1,6)->setTextAlignment(Qt::AlignRight);

        }else{

            int diff =a-totP;
            totP=totP+diff;
            totI=totI-diff;
            model->setItem(n-1,5,new QStandardItem(QVariant(model->item(n-1,5)->data(Qt::DisplayRole).toInt()+diff).toString()));
            model->setItem(n-1,6,new QStandardItem(QVariant(model->item(n-1,6)->data(Qt::DisplayRole).toInt()-diff).toString()));
            model->item(n-1,5)->setTextAlignment(Qt::AlignRight);
            model->item(n-1,6)->setTextAlignment(Qt::AlignRight);

        }
    }

//     Gtot=totP+totI;
     //lineEditTotI->setText(QVariant(totI).toString());
     //lineEditTotP->setText(QVariant(totP).toString());
     //lineEditGtot->setText(QVariant(Gtot).toString());
    // tableView->setModel(model);
    // tableView->setColumnWidth(0,25);
    // tableView->resizeRowsToContents();
 return model;

}
void LoanDialog::SaveSchedule(QStandardItemModel* mdl)
{

     QStringList connectionNames = QSqlDatabase::connectionNames();
     QSqlDatabase db = QSqlDatabase::database(connectionNames.at(0), false);

     if(db.open()){

         QSqlQuery query("",db);
         QString str("INSERT INTO ");

          str.append(lineEditID->text());

          str.append("(id,datedy,datemn,dateyr,emi,P,I) VALUES (?,?,?,?,?,?,?)");


          int rc = mdl->rowCount();

          for(int i=0;i<rc;i++){

            query.prepare(str);
         //   qDebug()<<mdl->item(i,0)->text();
            query.bindValue(0,mdl->item(i,0)->text());
            query.bindValue(1,mdl->item(i,1)->text());
            query.bindValue(2,mdl->item(i,2)->text());
            query.bindValue(3,mdl->item(i,3)->text());
            query.bindValue(4,mdl->item(i,4)->text());
            query.bindValue(5,mdl->item(i,5)->text());
            query.bindValue(6,mdl->item(i,6)->text());
            //query.bindValue(7,mdl->item(i,7)->text());
            query.exec();

            query.clear();

         }

     }

}
void LoanDialog::enableAuto()
{
    if(cboType->currentText()=="Auto Loan"){
       groupAuto->setEnabled(true);
    }else{
       groupAuto->setEnabled(false);
    }
}
void LoanDialog::getAmountFinanced()
{
    lineEditAmount->setText(QVariant(lineEditCost->text().toDouble()-lineEditHire->text().toDouble()).toString());
}
void LoanDialog::setCompleter()
{

    QSqlQueryModel *qry = new QSqlQueryModel();
    completer = new QCompleter(qry,this);

    qry->setQuery("select Distinct(vhname) from loan");
 //   qDebug()<<qry->rowCount();
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    lineEditVh->setCompleter(completer);

    QSqlQueryModel *qry2 = new QSqlQueryModel();
    completer2 = new QCompleter(qry2,this);

    qry2->setQuery("select Distinct(pdcbk) from loan");
  //  qDebug()<<qry2->rowCount();
    completer2->setCompletionMode(QCompleter::PopupCompletion);
    completer2->setCaseSensitivity(Qt::CaseInsensitive);
    lineEditBK->setCompleter(completer2);

}
void LoanDialog::showPdc()
{

    lineEditPto->setText(QVariant(lineEditPfrom->text().toInt()+spinBox->value()-1).toString());

}
