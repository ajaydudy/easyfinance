#ifndef VOUCHERLIST_H
#define VOUCHERLIST_H


#include <QSqlQueryModel>

//! [0]
class VoucherList : public QSqlQueryModel
{
    Q_OBJECT

public:
    VoucherList(QObject *parent = 0);

    QVariant data(const QModelIndex &item, int role) const;
};

#endif // VOUCHERLIST_H
