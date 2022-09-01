#ifndef SCHEDULE_H
#define SCHEDULE_H
#include "ui_schedule.h"
#include <QStandardItemModel>

class Schedule : public QDialog, private Ui::Schedule {
    Q_OBJECT
public:
    Schedule(QWidget *parent);
    ~Schedule();
    //void setValues();
      void genSchedule(int a,float rt,int e,int n,int Yr,int Mn,int Day);

private:
    QStandardItemModel *model;


protected:
    void changeEvent(QEvent *e);


};

#endif // SCHEDULE_H
