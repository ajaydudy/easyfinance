#include "loannos.h"

LoanNos::LoanNos()
{
}
QVariant LoanNos::data(const QModelIndex &index, int role) const
{

    QVariant value = QSqlQueryModel::data(index, role);

    if (value.isValid() && role == Qt::DisplayRole) {
        if (index.column() == 0)
            return value.toString().prepend("LN0");

    }

    return value;
}
