#ifndef LEDGERINPUT_H
#define LEDGERINPUT_H

#include "ui_ledgerinput.h"

class LedgerInput : public QDialog, private Ui::LedgerInput {

    Q_OBJECT

public:

    LedgerInput(QWidget *parent = 0);
    QString LoanID;
    int dy;
    int mn;
    int yr;

private:
    void setCompleter();


private slots:
    void accept();
    void reject();
    void refreshLoanNo();


};

#endif // LEDGERINPUT_H
