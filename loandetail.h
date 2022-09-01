#ifndef LOANDETAIL_H
#define LOANDETAIL_H

#include "ui_loandetail.h"

class LoanDetail : public QDialog, private Ui::LoanDetail {
    Q_OBJECT
public:
    LoanDetail(QWidget *parent = 0);
};

#endif // LOANDETAIL_H
