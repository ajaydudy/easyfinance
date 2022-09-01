#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include "ui_messagedialog.h"

class messageDialog : public QDialog, private Ui::messageDialog {
    Q_OBJECT
public:
    messageDialog(QWidget *parent = 0);
};

#endif // MESSAGEDIALOG_H
