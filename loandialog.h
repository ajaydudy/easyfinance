#ifndef LOANDIALOG_H
#define LOANDIALOG_H

#include "ui_loandialog.h"
#include <QStandardItemModel>
#include <qtGui>

class LoanDialog : public QDialog, private Ui::LoanDialog {

    Q_OBJECT

public:

    LoanDialog(QWidget *parent,int mode,int lnid =0);
    int mode;
    int lnid;

private:

    QString getFlatRate();
    QString getReducingRate();
    bool validateEmi();
    bool validate();
    bool checkEmi();
    double roundh(double number,int place);
    void fillComboCust();
    void fillComboGr();
    void fillComboDl();
    void getID();
    void GenSaveSchedule();
    void setCompleter();
    QStandardItemModel* schedule(int a,float rt,int e,int n,int Yr,int Mn,int Day);
    QCompleter *completer;
    QCompleter *completer2;
    void SaveSchedule(QStandardItemModel* mdl);
    int GrID;
    int CsID;
    int DliD;


private slots:

   void save();
   void showSchedule();
   void showList();
   void showGuarantor();
   void showCustomer();
   void showDealer();
   void calculateRate();
   void setFinishDate();
   void getGrID();
   void getCsID();
   void getDlID();
   void showPopup();
   void enableAuto();
   void getAmountFinanced();
   void showPdc();

};
#endif // LOANDIALOG_H
