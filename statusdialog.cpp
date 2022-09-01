#include "statusdialog.h"
#include <QStandardItemModel>
#include <QtSql>
#include <QTreeView>

StatusDialog::StatusDialog(QWidget *parent) :
    QDialog(parent){
    setupUi(this);
    fillComboGr();
    dateEdit->setDate(QDate::currentDate());
}
void StatusDialog::fillComboGr()
{
     QStandardItemModel *model=new QStandardItemModel();
     //QStringList connectionNames = QSqlDatabase::connectionNames();
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
  //    }

    QTreeView *treeWidget = new QTreeView;
    treeWidget->setModel(model);
    treeWidget->setRootIsDecorated(false);
    treeWidget->header()->hide();
    treeWidget->header()->setStretchLastSection(false);
    treeWidget->header()->setResizeMode(0, QHeaderView::Stretch);
    treeWidget->header()->setResizeMode(1, QHeaderView::ResizeToContents);
    treeWidget->setAllColumnsShowFocus(false);
    cboGr->setModel(treeWidget->model());
    cboGr->setView(treeWidget);

}

void StatusDialog::accept()
{

    dy=dateEdit->date().day();
    mn=dateEdit->date().month();
    yr=dateEdit->date().year();

    if (cboGr->isEnabled())
    {
        QStandardItemModel *mdl=static_cast<QStandardItemModel*>(cboGr->model());
        GrID=mdl->item(cboGr->currentIndex(),1)->data(0).toString().remove(0,2);

    }else{
        GrID="0";
    }

        QDialog::accept();
}
void StatusDialog::reject()
{
    QDialog::reject();
}
void StatusDialog::enableDisable()
{

 if (radioButtonAll->isChecked())
   {
     cboGr->setEnabled(false);
   }else{
     cboGr->setEnabled(true);
   }



}
