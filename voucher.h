#ifndef VOUCHER_H
#define VOUCHER_H

#include "ui_voucher.h"

class Voucher : public QDialog, private Ui::Voucher {
    Q_OBJECT

public:

    Voucher(QWidget *parent,int mode,int vid =0);
    int mode;
    int vid;

private:

    void fillLoans();
    bool validate();
    void getID();
private slots:
   void save();
   //void checkRadio(QAbstractButton *btn);
   void showDetail();
   void addVoucher();
};

#endif // VOUCHER_H
