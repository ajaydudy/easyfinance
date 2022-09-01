#include "ledgerinput.h"
#include <QtSql>
#include <QTreeView>
#include <QStandardItemModel>
#include <QCompleter>

LedgerInput::LedgerInput(QWidget *parent) :QDialog(parent)
{

    setupUi(this);
    dateEdit->setDate(QDate::currentDate());
    QSqlQuery queyloan("select id from loan");

    while (queyloan.next())
    {
       cboLoan->addItem(queyloan.value(0).toString().prepend("LN0"));
    }
    setCompleter();
}

void LedgerInput::accept()
{

    LoanID=cboLoan->currentText().remove(0,2);
    dy=dateEdit->date().day();
    mn=dateEdit->date().month();
    yr=dateEdit->date().year();
    QDialog::accept();



}
void LedgerInput::reject()
{

    QDialog::reject();

}
void LedgerInput::setCompleter()
{

    QStandardItemModel *model= new QStandardItemModel(this);

    QSqlQuery query("SELECT id,name FROM Customer");

             if ( query.isActive() ) {

                 while ( query.next() ) {

                      model->setItem(query.at(),0, new QStandardItem( query.value(1).toString()));
                      model->setItem(query.at(),1, new QStandardItem("CS0"+query.value(0).toString()));

                     }
              }

       QTreeView *treeWidget = new QTreeView;
       QCompleter *completer2 = new QCompleter(this);
       completer2->setModel(model);
       completer2->setPopup(treeWidget);
       completer2->setCompletionMode(QCompleter::PopupCompletion);
       completer2->setCaseSensitivity(Qt::CaseInsensitive);
       treeWidget->setRootIsDecorated(false);
       treeWidget->header()->hide();
       treeWidget->header()->setStretchLastSection(false);
       treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
       treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
       lineEditCustName->setCompleter(completer2);


}
void LedgerInput::refreshLoanNo()
{

   QSqlQuery qry;
   QSqlQuery qryA;
   QString id;

   //QStandardItemModel *mdl=static_cast<QStandardItemModel*>(ui->lineEditCustName->completer()->model());
   //qDebug()<<lineEditCustName->text().trimmed();
 if(lineEditCustName->text().trimmed().length()!=0)
  {
   qryA.exec(QString("Select id from customer where name = '").append(lineEditCustName->text().trimmed().append("'")));
   qryA.next();
   id=qryA.value(0).toString();
   //qDebug()<<id;
   qry.exec(QString("Select id from loan where custid = ").append(id));
   qry.next();
   //qDebug()<<qry.value(0).toString();
   cboLoan->setCurrentIndex(cboLoan->findText(qry.value(0).toString().prepend("LN0")));
  }
   if (cboLoan->currentIndex()==-1)
    {
      cboLoan->setCurrentIndex(0);
    }
}



