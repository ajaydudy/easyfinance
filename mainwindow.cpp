#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CustomerDialog.h"
#include "loandialog.h"
#include "about.h"
#include "customer.h"
#include "voucher.h"
#include "voucherlist.h"
#include "loannos.h"
#include "ledgerinput.h"
#include "statusdialog.h"
#include "totalinterest.h"
#include "messagewindow.h"
#include "messagedialog.h"
#include "customqsqlrelationaltablemodel.h"
#include <QSqlRelationalTableModel>
#include <Qtsql>
#include <QInputDialog>
#include <math.h>
#include <QTextEdit>
#include <QStandardItemModel>
#include "DealerLedger.h"
#include <QMenu>
#include <QIcon>
#include <QToolButton>
#include <QSplashScreen>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //ui->treeWidget2->setVisible(false);
    //ui->mainToolBar->font().setStyleStrategy(QFont::ForceOutline);
  //  QString styl;
 //   styl.append("background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,");
  //  styl.append(" stop:0 #616161, stop: 0.5 #505050,");
  //  styl.append(" stop: 0.6 #434343, stop:1 #656565 color: white; padding-left: 4px;border: 1px solid #6c6c6c;");
    //QString styl(""
  //  ui->tableView->horizontalHeader()->setStyleSheet(styl);

   QMenu *menu = new QMenu();

    //menu->setIcon(QIcon(":/new/prefix1/images/Mashup-4.2/Mashup/categories/applications-accessories.png"));
    //menu->addAction(QIcon(":/new/prefix1/images/Cal.png"),"E.M.I.Tool");
     menu->addAction(ui->actionEmiTool);
     menu->addAction(ui->actionTotal_Interest_Earned);
     ui->actionTotal_Interest_Earned->setEnabled(false);
   // menu->addAction("B");
  //  menu->addAction("C");

   // ui->mainToolBar->addSeparator();
    //ui->mainToolBar->addAction(ui->actionAdd_Customer);
    ui->mainToolBar->addAction(ui->actionAdd_Loan);

    ui->actionAdd_Loan->setShortcut(QKeySequence(tr("Alt+l")));
    ui->mainToolBar->addAction(ui->actionNew_Voucher);
    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actionEdit_Record);
    ui->mainToolBar->addAction(ui->actionDelete_Record);
    ui->mainToolBar->addAction(ui->actionPrintPreview);

   // ui->mainToolBar->addAction(menu->menuAction());
    QToolButton *btn = new QToolButton();
     btn->setMenu(menu);
     btn->setPopupMode(QToolButton::InstantPopup);
     btn->setText("Tools and\nAccessories   ");
     btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
     btn->setIcon(QIcon(":/new/prefix1/images/Mashup-4.2/Mashup/categories/applications-accessories.png"));
     ui->mainToolBar->addWidget(btn);
     ui->mainToolBar->addSeparator();
   // ui->mainToolBar->addAction(ui->actionTools);

  //  ui->mainToolBar->addSeparator();

    //ui->mainToolBar->addWidget(new QToolBar());

    ui->toolBar->addAction(ui->actionQuit_nApplication);
    ui->toolBar->addAction(ui->actionAbout);
    ui->toolBar->addAction(ui->actionHelp);

     ui->toolBar->addSeparator();

    //ui->treeWidget->expandAll();
    ui->frameDetail->setVisible(false);
    ui->frameFooter->setVisible(false);
   // QTextEdit *textEdit = new QTextEdit(this);
    ui->textEdit->setVisible(false);
    ui->actionDelete_Record->setEnabled(false);
    ui->actionEdit_Record->setEnabled(false);
    setCompleter();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::showCustomer()
{

    CustomerDialog *cst = new CustomerDialog(this,1,0);
    cst->exec();
    delete cst;

}
void MainWindow::showLoan()
{

   LoanDialog *ln =new LoanDialog(this,1);
   if(ln->exec()==QDialog::Accepted)
   {
      // fillLoans();
   }
   delete ln;

}
void MainWindow::showEdit()
{
    if (ui->treeWidget->currentItem()->text()=="Loans"){

        LoanDialog *ln = new LoanDialog(this,0,recid);
        qDebug()<<recid;
        ln->exec();
        delete ln;
        fillLoans();

    }else if( ui->treeWidget->currentItem()->text()=="Loan Ledger" && recid!=0){

       Voucher *vc = new Voucher(this,0,recid);
       vc->exec();
       delete vc;

    }else if( ui->treeWidget->currentItem()->text()=="Customers" && recid!=0){

      CustomerDialog *cst = new CustomerDialog(this,0,recid);
      cst->exec();
      delete cst;

   }
}
void MainWindow::onTableViewActivated(QModelIndex idx)
{

   if(ui->treeWidget->currentItem()->text()!="Loan Ledger"){

        recid= ui->tableView->model()->data(ui->tableView->model()->index(idx.row(),0)).toString().remove(0,2).toInt();
        if(recid!=0){
            ui->actionEdit_Record->setEnabled(true);
        }else{
            ui->actionEdit_Record->setEnabled(false);
        }

   }else{

       recid= ui->tableView->model()->data(ui->tableView->model()->index(idx.row(),2)).toString().remove(0,2).toInt();
       if(recid!=0){
             ui->actionDelete_Record->setEnabled(true);
             ui->actionEdit_Record->setEnabled(true);
       }else{
             ui->actionDelete_Record->setEnabled(false);
             ui->actionEdit_Record->setEnabled(false);
       }
   }
}
void MainWindow::showVoucher()
{

   QSqlQuery qr("select Count(*) from loan");
   qr.next();
   if(qr.value(0).toInt()!=0){
        Voucher *vc = new Voucher(this,1,recid);
        vc->exec();
        delete vc;
   }

}
void MainWindow::fillLoans()
{

    QSqlDatabase::database().transaction();
     QStandardItemModel *model = new QStandardItemModel();
     QStringList hdr;
     hdr<<"Loan No."<<"Case Date"<<"Customer"<<"Loan Type"<<"Guarantor"<<"Total Cost"<<"Initial Hire"<<"Financed Amount"<<"EMI"<<"EMI No's "<<"FlatRate"<<"I.R.R."<<"StartDate"<<"FinishDate"<<"Dealer"<<"Vehicle"<<"RGD.No."<<"ChassisNo."<<"EngineNo."<<"PDC From"<<"PDC To"<<"PDC Bank"<<"File Guarantor";
     model->setHorizontalHeaderLabels(hdr);
     QSqlQuery qry ;
     QSqlQuery qryCust;
     QSqlQuery qryGrntr;
     QSqlQuery qryDealer;
     qry.exec("Select * from loan");
     QDate dt;

     ui->frameDetail->setVisible(false);
     ui->frameFooter->setVisible(false);

     if(qry.isActive()){

         while (qry.next()){

           model->setItem(qry.at(),0,new QStandardItem(qry.value(0).toString().prepend("LN0")));
            dt.setDate(qry.value(3).toInt(),qry.value(2).toInt(),qry.value(1).toInt());
           model->setItem(qry.at(),1,new QStandardItem(dt.toString("dd/MM/yyyy")));
            qryCust.exec(QString("select name from customer where id= ").append(qry.value(4).toString()));
            qryCust.next();
           model->setItem(qry.at(),2,new QStandardItem(qryCust.value(0).toString()));
           model->setItem(qry.at(),3,new QStandardItem(qry.value(5).toString()));
           qryGrntr.exec(QString("select name from guarantor where id= ").append(qry.value(6).toString()));
            qryGrntr.next();
           model->setItem(qry.at(),4,new QStandardItem(qryGrntr.value(0).toString()));
           model->setItem(qry.at(),5,new QStandardItem(qry.value(7).toString()));
           model->setItem(qry.at(),6,new QStandardItem(qry.value(8).toString()));
           model->setItem(qry.at(),7,new QStandardItem(qry.value(9).toString()));
           model->setItem(qry.at(),8,new QStandardItem(qry.value(10).toString()));
           model->setItem(qry.at(),9,new QStandardItem(qry.value(11).toString()));
           model->setItem(qry.at(),10,new QStandardItem(qry.value(12).toString()));
           model->setItem(qry.at(),11,new QStandardItem(qry.value(13).toString()));
             dt.setDate(qry.value(16).toInt(),qry.value(15).toInt(),qry.value(14).toInt());
           model->setItem(qry.at(),12,new QStandardItem(dt.toString("dd/MM/yyyy")));
             dt.setDate(qry.value(19).toInt(),qry.value(18).toInt(),qry.value(17).toInt());
           model->setItem(qry.at(),13,new QStandardItem(dt.toString("dd/MM/yyyy")));
             qryDealer.exec(QString("select name from dealer where id=").append(qry.value(20).toString()));
             qryDealer.next();
           model->setItem(qry.at(),14,new QStandardItem(qryDealer.value(0).toString()));
           model->setItem(qry.at(),15,new QStandardItem(qry.value(21).toString()));
           model->setItem(qry.at(),16,new QStandardItem(qry.value(22).toString()));
           model->setItem(qry.at(),17,new QStandardItem(qry.value(23).toString()));
           model->setItem(qry.at(),18,new QStandardItem(qry.value(24).toString()));
           model->setItem(qry.at(),19,new QStandardItem(qry.value(25).toString()));
           model->setItem(qry.at(),20,new QStandardItem(qry.value(26).toString()));
           model->setItem(qry.at(),21,new QStandardItem(qry.value(27).toString()));
           model->setItem(qry.at(),22,new QStandardItem(qry.value(28).toString()));

        }


     }
    QSqlDatabase::database().commit();
     ui->tableView->setModel(model);
     ui->tableView->resizeColumnsToContents();


}
void MainWindow::showAbout()
{
  About *abt = new About();
  abt->exec();
  delete abt;
  //About::exec();
}



void MainWindow::Activated()
{

        if(ui->treeWidget->currentItem()->text()=="Customers"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillCustomers();

        }else if(ui->treeWidget->currentItem()->text()=="Loans"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillLoans();
        }else if(ui->treeWidget->currentItem()->text()=="Vouchers"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillVouchers();

        }else if(ui->treeWidget-> currentItem()->text()=="Loan Ledger"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillLedger();

        }else if(ui->treeWidget-> currentItem()->text()=="Guarantor Status"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillStatus();

        }else if(ui->treeWidget-> currentItem()->text()=="Pre-Payment Schedule"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillPrePayment();
        }else if(ui->treeWidget-> currentItem()->text()=="Dealer Ledger"){
            ui->actionDelete_Record->setEnabled(false);
            ui->actionEdit_Record->setEnabled(false);
            fillDealerLedger();

      }

}
void MainWindow::fillStatus()
{


 //   QString no;
   // QStringList list;

    QStandardItemModel *modelSt = new QStandardItemModel();
    StatusDialog st(this);

   if ( st.exec()==QDialog::Accepted)

    {
       messageDialog *msg =new messageDialog();
       msg->setWindowFlags(Qt::Popup);
       msg->show();
       qApp->setOverrideCursor(Qt::BusyCursor);
       qApp->processEvents();
      ui->textEdit->clear();
      ui->frameDetail->setVisible(false);
      ui->frameFooter->setVisible(false);
     // qApp->setOverrideCursor(Qt::BusyCursor);
      QSqlDatabase::database().transaction();
      QSqlQuery qryGr;
      int grid=0;

      if (st.GrID.toInt()!=0)
      {
        qryGr.exec(QString("select id,grntr from loan where closed = 0 AND grntr = ").append(st.GrID));

      }else{

        qryGr.exec(QString("select id,grntr from loan where closed = 0"));

      }

      QTextCursor cursor(ui->textEdit->textCursor());
      cursor.movePosition(QTextCursor::Start);
      QTextCharFormat headBlockFormat;
      headBlockFormat.setFontUnderline(true);
      headBlockFormat.setFontPointSize(12);
      QString hstr("Guarantor Status        As On Date: ");
      hstr.append(QDate(st.yr,st.mn,st.dy).toString("dd/MMMM/yyyy"));
      cursor.insertText(hstr,headBlockFormat);
      QTextCharFormat boldFormat;
      boldFormat.setFontWeight(QFont::Bold);
      QTextTableFormat TableFormat;
      TableFormat.setCellPadding(5);
      TableFormat.setCellSpacing(0);
      TableFormat.setBorder(1);
      TableFormat.setBorderBrush(Qt::black);
      TableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
      QTextBlockFormat rightBlockFormat;
      rightBlockFormat.setAlignment(Qt::AlignRight);
      QTextBlockFormat topBlockFormat;
     //QTextCharFormat boldFormat;
      boldFormat.setFontWeight(QFont::Bold);



      while (qryGr.next())
      {

     //----------------add from schedule--------------
        //grid=qryGr.value(1).toInt();
        QSqlQuery queryInsert;
        QString str("select id,datedy,datemn,dateyr,emi from ");
        str.append("LN0").append(QVariant(abs(qryGr.value(0).toInt())).toString());
        QSqlQuery querySchedule(str);
        querySchedule.exec();
        queryInsert.exec("delete from ledger");
        queryInsert.clear();

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
        str.append(qryGr.value(0).toString());
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
                queryInsert.bindValue(7,querySchedule.value(7));
                queryInsert.exec();
         }

       }
    //--------------------------------------------------------------
    //----------------view ledger-----------------------------------

    QString strAg("select csdy,csmn,csyr,emi,no,custid,type,vhname from loan where id= ");
            strAg.append(qryGr.value(0).toString());
    QSqlQuery queryAgreed(strAg);
    QSqlQuery qryCust;


    double agamount;
    queryAgreed.exec();
    queryAgreed.next();
    qryCust.exec(QString("Select name,phone from customer where id=").append(queryAgreed.value(5).toString()));
    qryCust.next();

    agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();

    double tempStkBalance;
    double totalCredit=0.0;
    double totalDebit=0.0;

    QStandardItemModel *model = new QStandardItemModel();
    QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
    model->setItem(0,6,new QStandardItem("0.0"));
    model->setItem(0,8,new QStandardItem(QVariant(agamount).toString()));
    model->item(0,8)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    tempStkBalance=agamount;

    QSqlQuery queryLedger(QString("select * from ledger order by dateyr,datemn,datedy"));

    if ( queryLedger.isActive() ) {

        while (queryLedger.next())

         {
          dt.setDate(queryLedger.value(2).toInt(),queryLedger.value(1).toInt(),queryLedger.value(0).toInt());
          if(dt<=QDate(st.yr,st.mn,st.dy))
          {

            model->setItem(queryLedger.at()+1,1,new QStandardItem(queryLedger.value(3).toString()));
            totalDebit=totalDebit+queryLedger.value(6).toDouble();
            totalCredit=totalCredit+queryLedger.value(7).toDouble();
            model->setItem(queryLedger.at()+1,6,new QStandardItem(QVariant((totalDebit-totalCredit)).toString().append(".0")));

            if( totalCredit-totalDebit==0){
               model->setItem(queryLedger.at()+1,6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0")));
            }

            model->item(queryLedger.at()+1,6)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
            QString st(model->item(queryLedger.at()+1,1)->text());
            st.truncate(11);

           if(st=="INSTALLMENT" && model->item(queryLedger.at()+1,1)->text()!="INSTALLMENT RECD" ){

              model->setItem(queryLedger.at()+1,7,new QStandardItem(queryLedger.value(6).toString()));
              tempStkBalance = tempStkBalance - QVariant(queryLedger.value(6)).toDouble();
           }
              model->setItem(queryLedger.at()+1,8,new QStandardItem(QVariant(tempStkBalance).toString().append(".0")));
         }
       }
     }

     QList<QStandardItem*>items ;
     QStringList hdr;

     hdr<<"Case No"<<"Name"<<"Phone"<<"Type"<<"Vehicle"<<"Balance"<<"Stock"<<"gr";

     items<<new QStandardItem(qryGr.value(0).toString().prepend("LN0"))<<new QStandardItem(qryCust.value(0).toString())<< new QStandardItem(qryCust.value(1).toString())<<new QStandardItem(queryAgreed.value(6).toString())<<new QStandardItem(queryAgreed.value(7).toString())<< new QStandardItem(model->item(model->rowCount()-1,6)->text())<< new QStandardItem(model->item(model->rowCount()-1,8)->text())<<new QStandardItem(qryGr.value(1).toString());
     //<<new QStandardItem(qryGr.value(1).toString());
    // qDebug()<<qryGr.value(1).toString();
     modelSt->setHorizontalHeaderLabels(hdr);
     modelSt->appendRow(items);
     modelSt->item(modelSt->rowCount()-1,5)->setTextAlignment(Qt::AlignRight);
     modelSt->item(modelSt->rowCount()-1,6)->setTextAlignment(Qt::AlignRight);
     delete model;

 }

     modelSt->sort(0,Qt::AscendingOrder);
     modelSt->sort(1,Qt::AscendingOrder);

     ui->tableView->setModel(modelSt);
     ui->tableView->resizeColumnsToContents();
      ui->tableView->setColumnHidden(7,true);
     double blTotal=0,stkTotal=0;

     cursor.insertTable(1,7,TableFormat);
     cursor.currentTable()->cellAt(0,0).firstCursorPosition();
     cursor.insertText("Case No.",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,1).firstCursorPosition();
     cursor.insertText("Name",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,2).firstCursorPosition();
     cursor.insertText("Phone",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,3).firstCursorPosition();
     cursor.insertText("Type",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,4).firstCursorPosition();
     cursor.insertText("Vehicle",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,5).firstCursorPosition();
     cursor.insertText("Balance",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,6).firstCursorPosition();
     // cursor.setBlockFormat(blockFormat);
     cursor.insertText("Stock",boldFormat);
     //--------
     grid = modelSt->item(0,6)->data(0).toInt();
     //cursor.currentTable()->appendRows(1);
//     QSqlQuery qryGrName;
//     qryGrName.exec(QString("Select name from guarantor where id = ").append(QVariant(grid).toString()));
//     qryGrName.next();
//     cursor.currentTable()->mergeCells(cursor.currentTable()->rows()-1,0,1,6);
//     cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,0).firstCursorPosition();
//     cursor.insertText(qryGrName.value(0).toString().prepend("Guarantor :  "),boldFormat);
//     cursor.currentTable()->mergeCells(cursor.currentTable()->rows()-1,0,1,6);


     for (int j = 0; j < modelSt->rowCount(); ++j) {

         cursor.currentTable()->appendRows(1);

       if(grid!= modelSt->item(j,6)->data(0).toInt())
        {
          grid=modelSt->item(j,6)->data(0).toInt();

         /* qryGrName.exec(QString("Select name from guarantor where id = ").append(QVariant(grid).toString()));
          qryGrName.next();

          cursor.currentTable()->mergeCells(cursor.currentTable()->rows()-1,0,1,6);
          cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,0).firstCursorPosition();
          cursor.insertText(qryGrName.value(0).toString().prepend("Guarantor :  "),boldFormat);
          cursor.currentTable()->mergeCells(cursor.currentTable()->rows()-1,0,1,6);
          cursor.currentTable()->appendRows(1)*/;

        }
        for (int i = 0; i < modelSt->columnCount()-1; ++i) {

         cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,i).firstCursorPosition();
         cursor.insertText(modelSt->item(j,i)->text());

         if (i>=4){
             cursor.setBlockFormat(rightBlockFormat);
         }

        }
        blTotal=blTotal+modelSt->item(j,5)->text().toDouble();
        qDebug()<<modelSt->item(j,5)->text().toDouble();;
        stkTotal=stkTotal+modelSt->item(j,6)->text().toDouble();
//        if (cursor.atEnd()){
//            cursor.insertText("and");
//        }
     }
     cursor.currentTable()->appendRows(1);
     cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,2).firstCursorPosition();
     cursor.insertText("Total",boldFormat);
     cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,5).firstCursorPosition();
     cursor.insertText(QVariant(blTotal).toString(),boldFormat);
     cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,6).firstCursorPosition();
     cursor.insertText(QVariant(stkTotal).toString(),boldFormat);
     cursor.movePosition(QTextCursor::Start);
    ui->textEdit->setDocumentTitle("Guarantor Status");
   // ui->frameDetail->setVisible(true);
     qApp->restoreOverrideCursor();
     delete msg;
     ui->tableView->model()->sort(1,Qt::AscendingOrder);
     QSqlDatabase::database().commit();
  }

}
void MainWindow::fillCustomers()
{

     Customer *model = new Customer();
     model->setQuery("select * from customer");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("No."));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Address"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Phone"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
     ui->frameDetail->setVisible(false);
     ui->frameFooter->setVisible(false);
     ui->tableView->setModel(model);
     ui->tableView->resizeColumnsToContents();

}
void MainWindow::fillVouchers()
{
    VoucherList *model = new VoucherList();
   // model->setQuery("select id,CAST(datedy as varchar(2) )||'/'|| CAST(datemn as varchar(2)) || '/' || CAST(dateyr as varchar(4)) ,lnid,vno,des,dc,amount from voucher");
    model->setQuery("select id,CONCAT(CAST(datedy as char(2) ),'/',CAST(datemn as char(2)), '/',CAST(dateyr as char(4))) ,lnid,vno,des,dc,amount from voucher");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Voucher No."));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date."));
    
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Loan.No."));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Chq./Rcpt.No."));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    //model->setHeaderData(5, Qt::Horizontal, QObject::tr(""));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Debit/Credit"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Amount"));

    ui->frameDetail->setVisible(false);
    ui->frameFooter->setVisible(false);
    ui->tableView->setModel(model);

   
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::fillLedger()
{

    LedgerInput lgr (this);


   if ( lgr.exec()==QDialog::Accepted)
    {
        QSqlDatabase::database().transaction();
        ui->frameFooter->setVisible(false);
         QSqlQuery queryInsert;
         asOnDate.setDate(lgr.yr,lgr.mn,lgr.dy);

         //----------------add from schedule--------------

            QString str("select id,datedy,datemn,dateyr,emi from ");
            str.append("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString());
            QSqlQuery querySchedule(str);
            querySchedule.exec();
           // qDebug()<<  querySchedule.lastError();
            queryInsert.exec("delete from ledger");
            queryInsert.clear();

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
            str.append(lgr.LoanID);
            querySchedule.exec(str);
         //   qDebug()<<querySchedule.lastError();
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
               //    qDebug()<<"ins"<<queryInsert.lastError();
                  // queryInsert.clear();
             }

           }
        //--------------------------------------------------------------
        //----------------view ledger-----------------------------------

        QString strAg("select csdy,csmn,csyr,emi,no,penalty from loan where id= ");
        strAg.append(lgr.LoanID);
        QSqlQuery queryAgreed(strAg);

        double agamount;
        queryAgreed.exec();
        queryAgreed.next();
        agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();
        double tempStkBalance;
        double totalCredit=0.0;
        double totalDebit=0.0;
        QStandardItemModel *model = new QStandardItemModel();
        QStringList hdr;
        hdr <<"Date"<<"Description"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance"<<"Stock Amount"<<"Stock Balance";
        model->setHorizontalHeaderLabels(hdr);
        QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
        model->setItem(0,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
        model->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        model->setItem(0,1,new QStandardItem("AGREED  VALUE"));
      //model->item(0,7)->setTextAlignment(Qt::AlignVCenter);
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
             if(dt<=QDate(lgr.yr,lgr.mn,lgr.dy))
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


        delete ui->tableView->model();
 //qDebug()<<"sdfsd"<<QDate::fromString( model->item(36,0)->text(),"dd/MM/yyyy");
        ui->tableView->setModel(model);
        ui->lineEditLoanNo->setText(QString("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString()));
        ui->lineEditAmount->setText(QVariant(agamount).toString().append(".00"));
        QSqlQuery qryCust;
         qryCust.exec(QString("select name from customer where id=(select custid from loan where id= ").append(QVariant(abs(lgr.LoanID.toInt())).toString().append(")")));
         qryCust.lastError();
         qryCust.next();
         QDoubleValidator *vl= new QDoubleValidator(ui->lineEditPenalty);
         vl->setNotation(QDoubleValidator::StandardNotation);
         vl->setDecimals(2);
         ui->lineEditPenalty->setValidator(vl);
        ui->lineEditCustName->setText(qryCust.value(0).toString());
        ui->lineEditEMI->setText(QVariant(queryAgreed.value(3).toDouble()).toString().append(".00"));
        ui->spinBox->setValue(queryAgreed.value(5).toInt());
        //ui->lineEditPenalty->setText(QVariant(totPenalty).toString().append(".00"));
        ui->lineEditPenalty->clear();;
        calculatePenalty(model);
        QDate CaseDt;
        CaseDt = CaseDt.fromString(model->item(0,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
       // qDebug()<<CaseDt;
        QSqlDatabase::database().commit();
        ui->dateEdit->setDate(CaseDt);
        ui->tableView->resizeColumnsToContents();
        ui->frameDetail->setVisible(true);
        ui->tableView->selectRow(0);
        ui->labelHeader->setText("Loan Account Ledger");
        ui->spinBox->setVisible(true);
        ui->pushButton->setVisible(true);
        ui->lineEditPenalty->setVisible(true);
        ui->labelPl->setVisible(true);
        ui->labelRt->setVisible(true);
        ui->labelAg->setText("Amount Agreed");
        ui->lineEditCustName->setReadOnly(false);
        ui->lineEditLoanNo->setReadOnly(false);
      }
        printLedger( model,lgr.yr,lgr.mn,lgr.dy);
    }

}
void MainWindow::crypt()
{
 //  qDebug()<<"crypt";
//   QByteArray line;
   QFile file ;
   if (file.exists("lg"))
   {
       file.remove("lg");

   }
//   file.open(QIODevice::ReadOnly);
//   line = file.readAll();
//   QByteArray r("00haveahardfuck");
//   line.replace(0,15,r);
//   file.close();
//   file.remove("Msvc+.dll");
//   QFile file2("Msvc+.dll");
//   file2.open(QIODevice::WriteOnly);
// //  qDebug()<<file2.write(line);
//   file2.close();




}
void MainWindow::closeEvent(QCloseEvent *event)
{

    crypt();

}
 void MainWindow::filePrintPreview()
 {
    // ui->textEdit->setText("12345678901234567890123456789012345678901234567890123456789012345678901234567890");

  #ifndef QT_NO_PRINTER
    //filePrintPdf();
     QPixmap pixmap(":/new/prefix1/images/wait.jpg");
    // qDebug()<<pixmap.size();
     QSplashScreen splash(pixmap);
     splash.show();
  //   splash.raise();
     qApp->processEvents();
     QPrinter printer(QPrinter::HighResolution);
     printer.setPageOrder(QPrinter::FirstPageFirst );
     QPrintPreviewDialog preview(&printer, this);
     preview.resize(this->width()-400,this->height()-200);
     connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
     preview.setWindowTitle("Print Preview");
     preview.exec();

  #endif
 }

 void MainWindow::printPreview(QPrinter *printer)
 {
  #ifdef QT_NO_PRINTER
     Q_UNUSED(printer);
  #else


     ui->textEdit->print(printer);
     printer->setPageOrder(QPrinter::FirstPageFirst );
     printer->setPaperSize(QPrinter::A4);

  #endif
 }
 void MainWindow::recDelete()
 {

  //if (ui->treeWidget->currentItem()->text()=="Loan Ledger"){
   if (ui->treeWidget->currentItem()->text()=="Loan Ledger"&& recid!=0){
     // qDebug()<<recid;
      if(QMessageBox::critical(this,"Easy Finance","Do you want to delete this 'Voucher'' ?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes){
        QSqlQuery qry;
        qry.exec(QString("delete from voucher where id = ").append(QVariant(recid).toString()));

     }
    }
   ui->actionDelete_Record->setEnabled(false);
 //  }
 }
 void MainWindow::filePrintPdf()
 {
    qApp->setOverrideCursor(Qt::BusyCursor);
  #ifndef QT_NO_PRINTER
     QString fileName = QFileDialog::getSaveFileName(this, "Export PDF",
                                                     QString(), "*.pdf");
     if (!fileName.isEmpty()) {
         if (QFileInfo(fileName).suffix().isEmpty())
             fileName.append(".pdf");
         QPrinter printer(QPrinter::HighResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setOutputFileName(fileName);
         ui->textEdit->document()->print(&printer);
     }
  #endif
     qApp->restoreOverrideCursor();
 }
 void MainWindow::refreshPenalty()
 {
     QStandardItemModel *model =  qobject_cast<QStandardItemModel *>(ui->tableView->model());
     calculatePenalty(model);
 }


 void MainWindow::refreshLedger()
 {

  if(ui->treeWidget->currentItem()->text()!="Pre-Payment Schedule") {
   if (validateLoanNo()==true)
    {

     QSqlQuery queryInsert;

     //----------------add from schedule--------------

        QString str("select id,datedy,datemn,dateyr,emi from ");
        str.append(ui->lineEditLoanNo->text().trimmed());
        QSqlQuery querySchedule(str);
        querySchedule.exec();
        queryInsert.exec("delete from ledger");
        queryInsert.clear();

       if ( querySchedule.isActive() ) {

        while (querySchedule.next())
         {

            queryInsert.prepare("INSERT INTO `ledger`(datedy,datemn,dateyr,des,debit) VALUES (?,?,?,?,?)");
            queryInsert.bindValue(0,querySchedule.value(1));
            queryInsert.bindValue(1,querySchedule.value(2));
            queryInsert.bindValue(2,querySchedule.value(3));
            queryInsert.bindValue(3,QString("INSTALLMENT ").append(querySchedule.value(0).toString()));
            queryInsert.bindValue(4,querySchedule.value(4));
          //  qDebug()<<  queryInsert.lastError();
            queryInsert.exec();
          //  qDebug()<<  queryInsert.lastError();
         }
       }
      //--------------------------------------------------------------
      //--------add from vouchers-------------------------------------

        str.clear();
        querySchedule.clear();
        str.append("select datedy,datemn,dateyr,des,vno,dc,amount,id from voucher where des != 'DEALER PAYMENT' And lnid= ");
        str.append(ui->lineEditLoanNo->text().remove(0,2));
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
               queryInsert.bindValue(7,querySchedule.value(7));
               queryInsert.exec();
         }

       }
    //--------------------------------------------------------------
    //----------------view ledger-----------------------------------

    QString strAg("select csdy,csmn,csyr,emi,no,penalty from loan where id= ");
    //qDebug()<<no;
    strAg.append(ui->lineEditLoanNo->text().remove(0,2));
   // qDebug()<<strAg;
    QSqlQuery queryAgreed(strAg);
    double agamount;
    queryAgreed.exec();
    queryAgreed.next();
    agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();
    double tempStkBalance;
    double totalCredit=0.0;
    double totalDebit=0.0;
    QStandardItemModel *model = new QStandardItemModel();
    QStringList hdr;
    hdr <<"Date"<<"Description"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance"<<"Stock Amount"<<"Stock Balance";
    model->setHorizontalHeaderLabels(hdr);
    QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
    model->setItem(0,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
    model->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    model->setItem(0,1,new QStandardItem("AGREED VALUE"));
  //model->item(0,7)->setTextAlignment(Qt::AlignVCenter);
    model->setItem(0,7,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
    model->item(0,7)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    model->setItem(0,8,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
    model->item(0,8)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    tempStkBalance=agamount;

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


    delete ui->tableView->model();
    ui->tableView->setModel(model);
    //ui->lineEditLoanNo->setText(QString("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString()));
    ui->lineEditAmount->setText(QVariant(agamount).toString().append(".00"));
    QSqlQuery qryCust;
     qryCust.exec(QString("select name from customer where id=(select custid from loan where id= ").append(ui->lineEditLoanNo->text().remove(0,2).append(")")));
     qryCust.next();
     QDoubleValidator *vl= new QDoubleValidator(ui->lineEditPenalty);
     vl->setNotation(QDoubleValidator::StandardNotation);
     vl->setDecimals(2);
     ui->lineEditPenalty->setValidator(vl);
    ui->lineEditCustName->setText(qryCust.value(0).toString());
    ui->lineEditEMI->setText(QVariant(queryAgreed.value(3).toDouble()).toString().append(".00"));
    ui->spinBox->setValue(queryAgreed.value(5).toInt());
    //ui->lineEditPenalty->setText(QVariant(totPenalty).toString().append(".00"));
    calculatePenalty(model);
    QDate CaseDt;
    CaseDt = CaseDt.fromString(model->item(0,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
   // qDebug()<<CaseDt;
    ui->dateEdit->setDate(CaseDt);
    ui->tableView->resizeColumnsToContents();
    ui->frameDetail->setVisible(true);
    ui->tableView->selectRow(0);

    }
     printLedger( model,QDate::currentDate().year(),QDate::currentDate().month(),QDate::currentDate().day());
   }

  }
 }
 void MainWindow::setCompleter()
 {

     LoanNos *qry = new LoanNos();
     qry->setQuery("select id from loan");
     QStringList list;

     for(int i=0;i<qry->rowCount();i++)
     {
         list.append(qry->data(qry->index(i,0),0).toString());
     }

     delete qry;

     completer = new QCompleter(list);
     completer->setCompletionMode(QCompleter::PopupCompletion);
     completer->setCaseSensitivity(Qt::CaseInsensitive);
     ui->lineEditLoanNo->setCompleter(completer);;
     QStandardItemModel *model=new QStandardItemModel();
     QSqlQuery query("SELECT id,name FROM Customer");

              if ( query.isActive() ) {

                  while ( query.next() ) {

                       model->setItem(query.at(),0, new QStandardItem( query.value(1).toString()));
                       model->setItem(query.at(),1, new QStandardItem("CS0"+query.value(0).toString()));

                      }
               }

        QTreeView *treeWidget = new QTreeView;
        completer2 = new QCompleter(this);
        completer2->setModel(model);
        completer2->setPopup(treeWidget);
        completer2->setCompletionMode(QCompleter::PopupCompletion);
        completer2->setCaseSensitivity(Qt::CaseInsensitive);
        treeWidget->setRootIsDecorated(false);
        treeWidget->header()->hide();
        treeWidget->header()->setStretchLastSection(false);
        treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
        treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
        ui->lineEditCustName->setCompleter(completer2);


 }
 bool MainWindow::validateLoanNo()
 {

     bool found;
     found=false;
     QString no;
     QAbstractItemModel *mdl = ui->lineEditLoanNo->completer()->model();
     no=ui->lineEditLoanNo->text().trimmed();
     //int i=0;
     for(int i=0;i<mdl->rowCount();i++ )
     {

        if(mdl->data(mdl->index(i,0))==no)
         {
             found=true;
             break;
         }

      }

     return found;
 }

 void MainWindow::refreshLoanNo()
 {

    QSqlQuery qry;
    QSqlQuery qryA;
    QString id;



    qryA.exec(QString("Select id from customer where name = '").append(ui->lineEditCustName->text().trimmed().append("'")));
    qryA.next();
    id=qryA.value(0).toString();
    qry.exec(QString("Select id from loan where custid = ").append(id));
    qry.next();
    ui->lineEditLoanNo->setText(qry.value(0).toString().prepend("LN0"));
    refreshLedger();

 }

 void MainWindow::fillPrePayment()
 {
     QStandardItemModel *modelPre = new QStandardItemModel();
     QStandardItemModel *model = new QStandardItemModel();
     LedgerInput lgr (this);

    if ( lgr.exec()==QDialog::Accepted)
     {

        QSqlDatabase::database().transaction();
        ui->frameDetail->setVisible(true);
        ui->frameFooter->setVisible(true);
        QString strAg1("select csdy,csmn,csyr,amount,emi from loan where id= ");
        strAg1.append(lgr.LoanID);

        QSqlQuery queryLoanMaster(strAg1);
        queryLoanMaster.exec();
        queryLoanMaster.next();

        ui->lineEditLoanNo->setText(QString("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString()));
        ui->lineEditAmount->setText(queryLoanMaster.value(3).toString().append(".0"));
        QSqlQuery qryCust;
        qryCust.exec(QString("select name from customer where id=(select custid from loan where id= ").append(QVariant(abs(lgr.LoanID.toInt())).toString().append(")")));
        qryCust.next( );
        QDoubleValidator *vl= new QDoubleValidator(ui->lineEditPenalty);
        vl->setNotation(QDoubleValidator::StandardNotation);
        vl->setDecimals(2);
        ui->lineEditCustName->setText(qryCust.value(0).toString());
        ui->lineEditEMI->setText(QVariant(queryLoanMaster.value(4).toDouble()).toString().append(".00"));
        QDate CaseDt(queryLoanMaster.value(2).toInt(),queryLoanMaster.value(1).toInt(),queryLoanMaster.value(0).toInt());
       // CaseDt = CaseDt.fromString(model->item(0,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
        ui->dateEdit->setDate(CaseDt);
        ui->labelHeader->setText("Loan Fore-Closure Statement");
        ui->spinBox->setVisible(false);
        ui->pushButton->setVisible(false);
        ui->lineEditPenalty->setVisible(false);
        ui->labelPl->setVisible(false);
        ui->labelRt->setVisible(false);
        ui->labelAg->setText("Amount Financed");
 //       ui->lineEditCustName->setReadOnly(true);;
 //       ui->lineEditLoanNo->setReadOnly(true);


        QString str1("select datedy,datemn,dateyr,p,i from ");
        str1.append("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString());

        QSqlQuery querySchedule1(str1);
        querySchedule1.exec();


     while (querySchedule1.next())

     {

       QDate dt1(querySchedule1.value(2).toInt(),querySchedule1.value(1).toInt(),querySchedule1.value(0).toInt());

       if(dt1<=QDate(lgr.yr,lgr.mn,lgr.dy))

       {

        modelPre->setItem(querySchedule1.at(),0,new QStandardItem(dt1.toString("dd/MM/yyyy")));
        modelPre->item(querySchedule1.at(),0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);

        modelPre->setItem(querySchedule1.at(),1,new QStandardItem(querySchedule1.value(3).toString()));
        modelPre->item(querySchedule1.at(),1)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);

        modelPre->setItem(querySchedule1.at(),2,new QStandardItem(querySchedule1.value(4).toString()));
        modelPre->item(querySchedule1.at(),0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);

       if(querySchedule1.at()==0)

       {
           modelPre->setItem(querySchedule1.at(),3,new QStandardItem(querySchedule1.value(4).toString()));
           //TempIntrst=querySchedule1.value(3).toDouble();
           modelPre->setItem(querySchedule1.at(),4,new QStandardItem(QVariant(queryLoanMaster.value(3).toDouble()-querySchedule1.value(3).toDouble()).toString()));
           //qDebug()<<queryLoanMaster.value(3).toDouble()-querySchedule1.value(1).toDouble();

       }else{

           int intOut;
           intOut = querySchedule1.value(4).toInt() + modelPre->item(querySchedule1.at()-1,3)->data(0).toInt();
           modelPre->setItem(querySchedule1.at(),3,new QStandardItem(QVariant(intOut).toString()));
           double prnOut;
           prnOut = modelPre->item(querySchedule1.at()-1,4)->data(0).toDouble() - querySchedule1.value(3).toDouble();
           modelPre->setItem(querySchedule1.at(),4,new QStandardItem(QVariant(prnOut).toString()));

       }

        modelPre->item(querySchedule1.at(),3)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        modelPre->item(querySchedule1.at(),4)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        int PP;
        PP = modelPre->item(querySchedule1.at(),4)->data(0).toInt()+(modelPre->item(querySchedule1.at(),4)->data(0).toInt()*.04);
        modelPre->setItem(querySchedule1.at(),5,new QStandardItem(QVariant(PP).toString()));
        modelPre->item(querySchedule1.at(),5)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }

   }
       QStringList hdr;
       hdr <<"Date"<<"Principal"<<"Interest"<<"Interest Outstanding"<<"Principal Outstanding"<<"Pre-Payment Amount";
       modelPre->setHorizontalHeaderLabels(hdr);
       ui->tableView->setModel(modelPre);
       ui->tableView->resizeColumnsToContents();
       ui->lineEditPPAmt->setText(modelPre->item(modelPre->rowCount()-1,5)->data(0).toString().append(".00"));

//---------------------------------------------------------
          QSqlQuery queryInsert;
          asOnDate.setDate(lgr.yr,lgr.mn,lgr.dy);

   /*       //----------------add from schedule--------------

             QString str("select id,datedy,datemn,dateyr,emi from ");
             str.append("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString());
             QSqlQuery querySchedule(str);
             querySchedule.exec();
            // qDebug()<<  queryInsert.lastError();
             queryInsert.exec("delete from ledger");
             queryInsert.clear();

            if ( querySchedule.isActive() ) {

             while (querySchedule.next())
              {

                 queryInsert.prepare("INSERT INTO `ledger`(datedy,datemn,dateyr,des,debit) VALUES (?,?,?,?,?)");
                 queryInsert.bindValue(0,querySchedule.value(1));
                 queryInsert.bindValue(1,querySchedule.value(2));
                 queryInsert.bindValue(2,querySchedule.value(3));
                 queryInsert.bindValue(3,QString("INSTALLMENT ").append(querySchedule.value(0).toString()));
                 queryInsert.bindValue(4,querySchedule.value(4));
                 //qDebug()<<  queryInsert.lastError();
                 queryInsert.exec();
                 //qDebug()<<  queryInsert.lastError();
              }
            }
           //--------------------------------------------------------------
           //--------add from vouchers-------------------------------------

             str.clear();
             querySchedule.clear();
             str.append("select datedy,datemn,dateyr,des,vno,dc,amount,id from voucher where des != 'DEALER PAYMENT' And lnid= ");
             str.append(lgr.LoanID);
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
                     queryInsert.bindValue(5,"");
                     queryInsert.bindValue(6,querySchedule.value(6));

                 }else{

                     queryInsert.bindValue(6,"");
                     queryInsert.bindValue(5,querySchedule.value(6));
                 }
                    queryInsert.bindValue(7,querySchedule.value(7));
               //  qDebug()<<  queryInsert.lastError();
                     queryInsert.exec();
               //  qDebug()<<  queryInsert.lastError();
              }

            }
         //--------------------------------------------------------------
         //----------------view ledger-----------------------------------

         QString strAg("select csdy,csmn,csyr,emi,no,penalty from loan where id= ");
        // qDebug()<<no;
         strAg.append(lgr.LoanID);
 //        qDebug()<<strAg;
         QSqlQuery queryAgreed(strAg);

         double agamount;
         queryAgreed.exec();
   //      qDebug()<<queryAgreed.lastError();
         queryAgreed.next();
         agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();
         double tempStkBalance;
         double totalCredit=0.0;
         double totalDebit=0.0;

         //QStringList hdr;
     //    hdr <<"Date"<<"Description"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance"<<"Stock Amount"<<"Stock Balance";
      //   model->setHorizontalHeaderLabels(hdr);
         QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
         model->setItem(0,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
         model->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
         model->setItem(0,1,new QStandardItem("AGREED VALUE"));
       //model->item(0,7)->setTextAlignment(Qt::AlignVCenter);
         model->setItem(0,7,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
         model->item(0,7)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
         model->setItem(0,8,new QStandardItem(QVariant(agamount).toString().append(" Dr")));
         model->item(0,8)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
         tempStkBalance=agamount;

         QSqlQuery queryLedger(QString("select * from ledger order by dateyr,datemn,datedy"));

         if ( queryLedger.isActive() ) {
         //    double totPenalty=0;
             while (queryLedger.next())

              {

                dt.setDate(queryLedger.value(2).toInt(),queryLedger.value(1).toInt(),queryLedger.value(0).toInt());
              if(dt<=QDate(lgr.yr,lgr.mn,lgr.dy))
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
*/
                  //----------------add from schedule--------------

            QString str("select id,datedy,datemn,dateyr,emi from ");
            str.append("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString());
            QSqlQuery querySchedule(str);
            querySchedule.exec();
           // qDebug()<<  querySchedule.lastError();
            queryInsert.exec("delete from ledger");
            queryInsert.clear();

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
            str.append(lgr.LoanID);
            querySchedule.exec(str);
         //   qDebug()<<querySchedule.lastError();
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
               //    qDebug()<<"ins"<<queryInsert.lastError();
                  // queryInsert.clear();
             }

           }
        //--------------------------------------------------------------
        //----------------view ledger-----------------------------------

        QString strAg("select csdy,csmn,csyr,emi,no,penalty from loan where id= ");
        strAg.append(lgr.LoanID);
        QSqlQuery queryAgreed(strAg);

        double agamount;
        queryAgreed.exec();
        queryAgreed.next();
        agamount = queryAgreed.value(3).toDouble() * queryAgreed.value(4).toDouble();
        double tempStkBalance;
        double totalCredit=0.0;
        double totalDebit=0.0;
        QStandardItemModel *model = new QStandardItemModel();
       // QStringList hdr;
     //   hdr <<"Date"<<"Description"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance"<<"Stock Amount"<<"Stock Balance";
     //   model->setHorizontalHeaderLabels(hdr);
        QDate dt(queryAgreed.value(2).toInt(),queryAgreed.value(1).toInt(),queryAgreed.value(0).toInt());
        model->setItem(0,0,new QStandardItem(dt.toString("dd/MM/yyyy")));
        model->item(0,0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
        model->setItem(0,1,new QStandardItem("AGREED VALUE"));
      //model->item(0,7)->setTextAlignment(Qt::AlignVCenter);
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
             if(dt<=QDate(lgr.yr,lgr.mn,lgr.dy))
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


      //   delete ui->tableView->model();
       //  if (model->rowCount()==0)
     //    {
   //          return;
 //        }
      //   ui->tableView->setModel(model);
      //   ui->lineEditLoanNo->setText(QString("LN0").append(QVariant(abs(lgr.LoanID.toInt())).toString()));
       //  ui->lineEditAmount->setText(QVariant(agamount).toString().append(".00"));
      //   QSqlQuery qryCust;
       //   qryCust.exec(QString("select name from customer where id=(select custid from loan where id= ").append(QVariant(abs(lgr.LoanID.toInt())).toString().append(")")));
      //    qryCust.lastError();
      //    qryCust.next();
          QDoubleValidator *vl= new QDoubleValidator(ui->lineEditPenalty);
          vl->setNotation(QDoubleValidator::StandardNotation);
          vl->setDecimals(2);
          ui->lineEditPenalty->setValidator(vl);
         ui->lineEditCustName->setText(qryCust.value(0).toString());
         ui->lineEditEMI->setText(QVariant(queryAgreed.value(3).toDouble()).toString().append(".00"));
         ui->spinBox->setValue(queryAgreed.value(5).toInt());
         //ui->lineEditPenalty->setText(QVariant(totPenalty).toString().append(".00"));
         ui->lineEditPenalty->clear();;

         QDate CaseDt;
         CaseDt = CaseDt.fromString(model->item(0,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
        // qDebug()<<CaseDt;
         ui->dateEdit->setDate(CaseDt);
         ui->tableView->resizeColumnsToContents();
       //  ui->frameDetail->setVisible(true);
         ui->tableView->selectRow(0);

         calculatePenalty(model);

         QSqlQuery qryPenalty;
         QString strPnl("select SUM(amount) from voucher where lnid =");
         strPnl.append(lgr.LoanID);
         strPnl.append(" AND des='PENALTY RECD.'");
        //qDebug()<< strPnl;
        qryPenalty.exec(strPnl);
        qryPenalty.next();

        if (qryPenalty.isActive()){
            QString str;
            str.append(QVariant(ui->lineEditOverdue->text().toDouble()-qryPenalty.value(0).toDouble()).toString());
              int pos;
                 pos= str.indexOf(".");
             //   qDebug()<<"pos"<<pos;
               // str = QVariant(totPenalty).toString();
                str.truncate(pos+3);
                ui->lineEditOverdue->setText(str);
//            qDebug()<<"pl"<<qryPenalty.value(0);
        }

        QSqlQuery qryRepos;
        strPnl.clear();
        strPnl.append("select SUM(amount) from voucher where lnid =");
         strPnl.append(lgr.LoanID);
         strPnl.append(" AND des='REPOSSESION CHRGS.'");
       //  qDebug()<<strPnl;
        qryRepos.exec(strPnl);
        qryRepos.next();
        if (qryRepos.isActive()){

            ui->lineEditPossesion->setText(QVariant(qryRepos.value(0).toDouble()).toString());
           // qDebug()<<"rp"<<qryRepos.value(0);
        }

        // ui->lineEditOverdue->setText(ui->lineEditPenalty->text());
       }

QSqlDatabase::database().commit();
         QString hireMoney;
         hireMoney=model->item(model->rowCount()-1,6)->data(0).toString();
    //     qDebug()<<hireMoney;
         if (hireMoney.endsWith("Dr"))
         {
             hireMoney.chop(2);
         }else{
             hireMoney="0.00";
         }

          ui->lineEditBounce->setText(bounceChrg(model));
          ui->lineEditHireRC->setText(QVariant(hireMoney.toDouble()-ui->lineEditBounce->text().toDouble()).toString());
/*qDebug()<<hireMoney;
qDebug()<<ui->lineEditOverdue->text().toDouble();
qDebug()<<ui->lineEditBounce->text().toDouble();
qDebug()<<ui->lineEditPPAmt->text().toDouble();
          qDebug()<<hireMoney.toDouble()+ui->lineEditOverdue->text().toDouble()+ui->lineEditBounce->text().toDouble()+ui->lineEditPPAmt->text().toDouble();
*/
          QString strTotAmount;
        strTotAmount.append(QVariant(ui->lineEditHireRC->text().toDouble()+ui->lineEditOverdue->text().toDouble()+ui->lineEditBounce->text().toDouble()+ui->lineEditPPAmt->text().toDouble()).toString());

              int pos;
                 pos= strTotAmount.indexOf(".");
               // qDebug()<<"pos"<<pos;
               // str = QVariant(totPenalty).toString();
                strTotAmount.truncate(pos+3);
                ui->lineEditTotal->setText(strTotAmount);

        delete model;
        printForeClose(modelPre,lgr.yr,lgr.mn,lgr.dy);

    }


 }
 void MainWindow::calculatePenalty(QStandardItemModel* model)
 {

     double P=0;
     double Rt=0;
     double tempP=0;
     int noDays=0;
     double totPenalty=0;
     QDate Pdate;
     QDate Cdate;
     QString Ps;


     //QStandardItemModel *model =  qobject_cast<QStandardItemModel *>(ui->tableView->model());
 if (model->rowCount()<=1)
 {
    return;
 }
     for( int i =1;i<model->rowCount();i++){

          P=0;
          Rt=0;
          tempP=0;
          noDays=0;

        if ( i!=1 && model->item(i-1,6)->text().endsWith("Dr")){
         // QMessageBox::information(this,"yes", model->item(i-1,6)->text());
          Pdate=Pdate.fromString(model->item(i-1,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
          Ps = model->item(i-1,6)->text();
          Ps.chop(3);
          P = QVariant(Ps).toDouble();
          Cdate=Cdate.fromString(model->item(i,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
          noDays =Pdate.daysTo(Cdate);

    //    qDebug()<<"Pdate"<<Pdate.toString("dd/MM/yyyy");
    //    qDebug()<<"Adate"<<Cdate.toString("dd/MM/yyyy");
     //   qDebug()<<"dys"<<noDays;

          Rt = ui->spinBox->text().toDouble();
          tempP=(((Rt/100)*P)/365)*noDays;
          totPenalty= totPenalty+tempP;

      //   qDebug()<<"tempP"<<tempP;
    //    qDebug()<<"totpenalty"<<totPenalty;

        }
//        else{
//
//           //Pdate=Pdate.fromString(model->item(i,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
//           P=0;
//        }


     }

//----------------------
     P=0;
     Rt=0;
     tempP=0;
     noDays=0;


    if ( model->item(model->rowCount()-1,6)->text().endsWith("Dr")){
        Pdate=Pdate.fromString(model->item(model->rowCount()-1,0)->data(Qt::DisplayRole).toString(),"dd/MM/yyyy");
        noDays =Pdate.daysTo(asOnDate);
     //   qDebug()<<"dys"<<noDays;
     Rt = ui->spinBox->text().toDouble();
     Ps = model->item(model->rowCount()-1,6)->text();
     Ps.chop(3);
     P=QVariant(Ps).toDouble();
     tempP=(((Rt/100)*P)/365)*noDays;
   //  qDebug()<<"tempP"<<totPenalty;
     totPenalty= totPenalty+tempP;
         //qDebug()<<"tempP"<<totPenalty;
    }

    else{
      P=0;
    }

    QSqlQuery qryPenalty;

    qryPenalty.exec("Select SUM(credit)FROM LEDGER where des='PENALTY RECD.'");
    qryPenalty.next();
    totPenalty=totPenalty-qryPenalty.value(0).toDouble();
     int pos;

     pos=QVariant(totPenalty).toString().indexOf(".");
     QString str;
     str = QVariant(totPenalty).toString();
      //qDebug()<<str;
     //qDebug()<<totPenalty;
    //  qDebug()<<pos;
     if(pos!=-1){
        str.truncate(pos+3);
     }

    //  qDebug()<<str;
     ui->lineEditPenalty->setText(str);
     ui->lineEditOverdue->setText(str);

 }
 QString MainWindow::bounceChrg(QStandardItemModel* model)
 {

     double bChrg=0;

     for(int i = 0;i<=model->rowCount()-1;i++)

     {

       if(model->item(i,1)->data(0).toString()=="CHEQUE BOUNCE CHRG.")
         {
            bChrg=bChrg+model->item(i,4)->data(0).toDouble();

         }

     }

     return QVariant(bChrg).toString();
 }

 void MainWindow::fillDealerLedger()
 {

    QStandardItemModel *model = new QStandardItemModel();
    DealerLedger lgr (this);
    QDate AsOnDate;

    if ( lgr.exec()==QDialog::Accepted)

     {
        ui->frameFooter->setVisible(false);
        QSqlQuery queryLoan;
        AsOnDate.setDate(lgr.yr,lgr.mn,lgr.dy);
        queryLoan.exec("delete from dealerledger");
        QString str("select id,csdy,csmn,csyr,dlramt from loan where dealer = ");
        str.append(QVariant(abs(lgr.Dlid.toInt())).toString());
        queryLoan.exec(str);

        QSqlQuery qryInsert;

       if ( queryLoan.isActive() ) {

        while (queryLoan.next())
         {

          qryInsert.prepare("INSERT INTO `dealerledger`(lnid,dtdy,dtmm,dtyy,debit,credit) VALUES (?,?,?,?,?,?)");
          qryInsert.bindValue(0,queryLoan.value(0));
          qryInsert.bindValue(1,queryLoan.value(1));
          qryInsert.bindValue(2,queryLoan.value(2));
          qryInsert.bindValue(3,queryLoan.value(3));
          qryInsert.bindValue(4,"");
          qryInsert.bindValue(5,queryLoan.value(4));
          qryInsert.exec();

        }

        queryLoan.seek(-1);

        while (queryLoan.next())

          {

            QSqlQuery qryVoucher;
            qryVoucher.exec(QString("select * from voucher where des = 'DEALER PAYMENT' and lnid = ").append(queryLoan.value(0).toString()));

            while (qryVoucher.next())

              {

                qryInsert.prepare("INSERT INTO `dealerledger`(lnid,dtdy,dtmm,dtyy,debit,credit) VALUES (?,?,?,?,?,?)");
                qryInsert.bindValue(0,qryVoucher.value(1));
                qryInsert.bindValue(1,qryVoucher.value(6));
                qryInsert.bindValue(2,qryVoucher.value(7));
                qryInsert.bindValue(3,qryVoucher.value(8));

                if (qryVoucher.value(4).toString()=="Credit")
                {
                       qryInsert.bindValue(5,qryVoucher.value(5));
                       qryInsert.bindValue(4,"");
                }else{
                       qryInsert.bindValue(5,"");
                       qryInsert.bindValue(4,qryVoucher.value(5));
                }
                qryInsert.exec();

             }
        }

    }

       QStringList hdr;

       hdr <<"Date"<<"Loan No"<<"V.No."<<"Chq.No."<<"Debit"<<"Credit"<<"Balance";

       model->setHorizontalHeaderLabels(hdr);

       QSqlQuery queryLedger(QString("select * from dealerledger order by dtyy,dtmm,dtdy"));
       double totalCredit=0.0;
       double totalDebit=0.0;
       QDate dt;

       if ( queryLedger.isActive() ) {

           while (queryLedger.next())

            {

              dt.setDate(queryLedger.value(3).toInt(),queryLedger.value(2).toInt(),queryLedger.value(1).toInt());

            if(dt<=QDate(lgr.yr,lgr.mn,lgr.dy))

             {

              model->setItem(queryLedger.at(),0,new QStandardItem(dt.toString("dd/MM/yyyy")));
              model->item(queryLedger.at(),0)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
              model->setItem(queryLedger.at(),1,new QStandardItem(queryLedger.value(0).toString().prepend("LN0")));
             // model->item(queryLedger.at()+1,1)->setTextAlignment(Qt::AlignVCenter);
              if( queryLedger.value(6).toString()!=""){
                model->setItem(queryLedger.at(),2,new QStandardItem(queryLedger.value(6).toString().prepend("VC0")));
                model->item(queryLedger.at(),2)->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
              }

              model->setItem(queryLedger.at(),3,new QStandardItem(queryLedger.value(7).toString()));
              model->item(queryLedger.at(),3)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
              model->setItem(queryLedger.at(),4,new QStandardItem(queryLedger.value(4).toString()));
              model->item(queryLedger.at(),4)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
              totalDebit=totalDebit+queryLedger.value(4).toDouble();
              model->setItem(queryLedger.at(),5,new QStandardItem(queryLedger.value(5).toString()));
              model->item(queryLedger.at(),5)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
              totalCredit=totalCredit+queryLedger.value(5).toDouble();

              if(totalCredit>totalDebit){
                model->setItem(queryLedger.at(),6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0 Cr")));
              }else {
                model->setItem(queryLedger.at(),6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0 Dr")));
              }

              if( totalCredit-totalDebit==0){
                  model->setItem(queryLedger.at(),6,new QStandardItem(QVariant(abs(totalDebit-totalCredit)).toString().append(".0")));
              }

               model->item(queryLedger.at(),6)->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);


          }

       }
     }

       delete ui->tableView->model();
       ui->tableView->setModel(model);
       ui->tableView->resizeColumnsToContents();
   }


}
 void MainWindow::printForeClose(QStandardItemModel* model,int yr,int mn,int dy)
 {

     ui->textEdit->clear();
     ui->textEdit->setDocumentTitle("Loan Fore-Closure Statement");
     QTextCursor cursor(ui->textEdit->textCursor());
     cursor.movePosition(QTextCursor::Start);
     cursor.movePosition(QTextCursor::Start);
     QTextFrame *topFrame = cursor.currentFrame();
     QTextCharFormat headBlockFormat;
     headBlockFormat.setFontUnderline(true);
     headBlockFormat.setFontPointSize(12);

     QString hstr("Loan Fore Closure Statement        As On Date: ");
     hstr.append(QDate(yr,mn,dy).toString("dd/MMMM/yyyy"));
     cursor.insertText(hstr,headBlockFormat);
     cursor.insertBlock();
     cursor.insertText(ui->lineEditCustName->text(),headBlockFormat);
     cursor.insertText("    ");
     cursor.insertText("Loan No. - ",headBlockFormat);
     cursor.insertText(ui->lineEditLoanNo->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Case Date. - ",headBlockFormat);
     cursor.insertText(ui->dateEdit->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("E.M.I. - ",headBlockFormat);
     cursor.insertText(ui->lineEditEMI->text(),headBlockFormat);

     QTextCharFormat boldFormat;
     boldFormat.setFontWeight(QFont::Bold);
     QTextTableFormat TableFormat;
     TableFormat.setCellPadding(5);
     TableFormat.setCellSpacing(0);
     TableFormat.setBorder(1);
     TableFormat.setBorderBrush(Qt::black);
     TableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
     QTextBlockFormat rightBlockFormat;
     rightBlockFormat.setAlignment(Qt::AlignRight);
     QTextBlockFormat topBlockFormat;
    //QTextCharFormat boldFormat;
     boldFormat.setFontWeight(QFont::Bold);
     //----------
     cursor.insertTable(1,6,TableFormat);
     cursor.currentTable()->cellAt(0,0).firstCursorPosition();
     cursor.insertText("Date.",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,1).firstCursorPosition();
     cursor.insertText("Principal",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,2).firstCursorPosition();
     cursor.insertText("Interest",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,3).firstCursorPosition();
     cursor.insertText("Interest Outstanding",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,4).firstCursorPosition();
     cursor.insertText("Principal Outstanding",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,5).firstCursorPosition();
     cursor.insertText("Pre-Payment Amount",boldFormat);

     for (int i = 0; i < model->rowCount(); i++)

     {

       cursor.currentTable()->appendRows(1);

       for (int j = 0; j <6; j++)
       {
           cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,j).firstCursorPosition();

         if(model->item(i,j)!=0)
         {
           cursor.insertText(model->item(i,j)->text());
            cursor.setBlockFormat(rightBlockFormat);
         }
       }
     }
     //QTextFrame *topFrame = cursor.
     cursor.setPosition(topFrame->lastPosition());
     cursor.insertBlock();
     cursor.insertText("Pre-Payment Amount - ",headBlockFormat);
     cursor.insertText(ui->lineEditPPAmt->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Hire Money Recievable. - ",headBlockFormat);
     cursor.insertText(ui->lineEditHireRC->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Overdue Charges. - ",headBlockFormat);
     cursor.insertText(ui->lineEditOverdue->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Cheque Bouncing Charges - ",headBlockFormat);
     cursor.insertText(ui->lineEditBounce->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Repossesion Charges - ",headBlockFormat);
     cursor.insertText(ui->lineEditPossesion->text(),headBlockFormat);
     cursor.insertBlock();
     cursor.insertText("Total Premature Amount - ",headBlockFormat);
     cursor.insertText(ui->lineEditTotal->text(),headBlockFormat);


 }
 void MainWindow::printLedger(QStandardItemModel* model,int yr,int mn,int dy)
 {

     ui->textEdit->setDocumentTitle("Loan Ledger");
     ui->textEdit->clear();
     QTextCursor cursor(ui->textEdit->textCursor());
     cursor.movePosition(QTextCursor::Start);
     QTextCharFormat headBlockFormat;
     headBlockFormat.setFontUnderline(true);
     headBlockFormat.setFontPointSize(12);

     QString hstr("Loan Ledger        As On Date: ");
     hstr.append(QDate(yr,mn,dy).toString("dd/MMMM/yyyy"));
     cursor.insertText(hstr,headBlockFormat);
     cursor.insertBlock();
     cursor.insertText(ui->lineEditCustName->text(),headBlockFormat);
     cursor.insertText("    ");
     cursor.insertText("Loan No. - ",headBlockFormat);
     cursor.insertText(ui->lineEditLoanNo->text(),headBlockFormat);
     QTextCharFormat boldFormat;
     boldFormat.setFontWeight(QFont::Bold);
     QTextTableFormat TableFormat;
     TableFormat.setCellPadding(5);
     TableFormat.setCellSpacing(0);
     TableFormat.setBorder(1);
     TableFormat.setBorderBrush(Qt::black);
     TableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
     QTextBlockFormat rightBlockFormat;
     rightBlockFormat.setAlignment(Qt::AlignRight);
     QTextBlockFormat topBlockFormat;
    //QTextCharFormat boldFormat;
     boldFormat.setFontWeight(QFont::Bold);
     //----------
     cursor.insertTable(1,9,TableFormat);
     cursor.currentTable()->cellAt(0,0).firstCursorPosition();
     cursor.insertText("Date.",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,1).firstCursorPosition();
     cursor.insertText("Description",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,2).firstCursorPosition();
     cursor.insertText("V.no.",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,3).firstCursorPosition();
     cursor.insertText("Chq.No.",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,4).firstCursorPosition();
     cursor.insertText("Debit",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,5).firstCursorPosition();
     cursor.insertText("Credit",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,6).firstCursorPosition();
     cursor.insertText("Balance",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,7).firstCursorPosition();
     cursor.insertText("Stock Amount",boldFormat);
     cursor=cursor.currentTable()->cellAt(0,8).firstCursorPosition();
     cursor.insertText("Stock Balance",boldFormat);
    // QMessageBox::information(this,"qwe",QVariant(model->rowCount()).toString());
   //  QMessageBox::information(this,"qwe",model->item(0,1)->data(0).toString());

    for (int i = 0; i < model->rowCount(); i++)
    {

      cursor.currentTable()->appendRows(1);

      for (int j = 0; j < 9; j++)
      {
          cursor = cursor.currentTable()->cellAt(cursor.currentTable()->rows()-1,j).firstCursorPosition();

        if(model->item(i,j)!=0)
        {
          cursor.insertText(model->item(i,j)->text());
          if(j>3)
          {
            cursor.setBlockFormat(rightBlockFormat);
          }
        //    QMessageBox::information(this,"qwe",model->item(i,j)->data(0).toString());
        }
      }
    }

}
 void MainWindow::showEmiTool()
 {
     EmiTool *emi =new EmiTool(this);
     emi->show();
 }


void MainWindow::on_actionTotal_Interest_Earned_triggered()
{
    messageDialog *msg =new messageDialog();
    msg->setWindowFlags(Qt::Popup);
    msg->show();
    qApp->setOverrideCursor(Qt::BusyCursor);
    qApp->processEvents();
    TotalInterest *Tot =new TotalInterest(this);
    Tot->show();
    delete msg;
    qApp->restoreOverrideCursor();

}
