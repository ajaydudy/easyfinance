#ifndef TOTALINTEREST_H
#define TOTALINTEREST_H

#include <QDialog>
#include <QDate>
#include <QStandardItemModel>

namespace Ui {
    class TotalInterest;
}

class TotalInterest : public QDialog
{
    Q_OBJECT

public:
    explicit TotalInterest(QWidget *parent = 0);
    ~TotalInterest();

private:
    Ui::TotalInterest *ui;
    void FillLedger(int lnid);
    void CalculateInterest();
    QStandardItemModel *model;


   // QStringList returnDate();
};

#endif // TOTALINTEREST_H
