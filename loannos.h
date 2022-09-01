#ifndef LOANNOS_H
#define LOANNOS_H

#include <QSqlQueryModel>

class LoanNos : public QSqlQueryModel
{
   Q_OBJECT
public:
    LoanNos();
    QVariant data(const QModelIndex &item, int role) const;
};

#endif // LOANNOS_H
