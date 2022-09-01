#ifndef GAURANTOR_H
#define GAURANTOR_H

#include "ui_gaurantor.h"
#include <QtSql>

class Gaurantor : public QDialog, private Ui::Gaurantor {
    Q_OBJECT
public:
    Gaurantor(QWidget *parent = 0);
    ~Gaurantor();
protected:
    void changeEvent(QEvent *e);
    bool validate();
    void getID();

private slots:
    void Save();

};

#endif // GAURANTOR_H
