#ifndef PRESCHDIALOG_H
#define PRESCHDIALOG_H
#include "ui_preschdialog.h"
#include <QDialog>


class PreSchDialog : public QDialog, private Ui::PreSchDialog{
    Q_OBJECT
public:
    PreSchDialog(QWidget *parent);
    ~PreSchDialog();

protected:
   // void changeEvent(QEvent *e);

private:
   //  *ui;
};

#endif // PRESCHDIALOG_H
