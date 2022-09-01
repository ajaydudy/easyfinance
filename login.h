#ifndef LOGIN_H
#define LOGIN_H

#include "ui_login.h"

class Login : public QDialog, private Ui::Login {
    Q_OBJECT
public:
    Login(QWidget *parent = 0);
    bool created;
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);
private slots:
    void accept();
    void reject();
    bool checkOpenDatabase();
};

#endif // LOGIN_H
