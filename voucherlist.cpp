
#include "voucherlist.h"
#include <QStandardItem>

VoucherList::VoucherList(QObject *parent)
    : QSqlQueryModel(parent)
{

}

//! [0]
QVariant VoucherList::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if (value.isValid() && role == Qt::DisplayRole) {

        if(index.column()== 0){
            //QStandardItem *mdl = qobject_cast<QStandardItem *>();
            return value.toString().prepend("VS0");
        }else if(index.column()== 2){
            return value.toString().prepend("LN0");
        }
    }

    return value;
}
