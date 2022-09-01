#ifndef STATUSDIALOG_H
#define STATUSDIALOG_H

#include "ui_statusdialog.h"

class StatusDialog : public QDialog, private Ui::StatusDialog {

    Q_OBJECT

public:

    StatusDialog(QWidget *parent = 0);
    QString GrID;

    int dy;
    int mn;
    int yr;
    bool all;

private:

    void fillComboGr();

private slots:

    void accept();
    void reject();
    void enableDisable();

};

#endif // STATUSDIALOG_H
