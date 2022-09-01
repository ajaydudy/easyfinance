#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTreeWidgetItem>
#include <QStandardItemModel>
#include <QDate>
#include <QCompleter>
#include "emitool.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

     MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QDate asOnDate;

private:

    Ui::MainWindow *ui;
    void fillLoans();
    void fillCustomers();
    void fillVouchers();
    void fillLedger();
    void fillStatus();
    void fillDealerLedger();
    void setCompleter();

    int recid;
    void filePrintPdf();
    QCompleter *completer;
    QCompleter *completer2;
    bool validateLoanNo();
    void fillComplCust ();
    void fillPrePayment();
    void printLedger(QStandardItemModel*,int,int,int);
    void printForeClose(QStandardItemModel*,int,int,int);
    void calculatePenalty(QStandardItemModel*);
    QString bounceChrg(QStandardItemModel*);

 protected:
     void closeEvent(QCloseEvent *event);

private slots:

    void on_actionTotal_Interest_Earned_triggered();
    void showEmiTool();
    void showCustomer();
    void showLoan();
    void showEdit();
    void recDelete();
    void showAbout();
    void filePrintPreview();
    void printPreview(QPrinter *);
    void Activated();
    void showVoucher();
    void onTableViewActivated(QModelIndex idx);
    void crypt();
    void refreshPenalty();
    void refreshLedger();
    void refreshLoanNo();
};

#endif // MAINWINDOW_H
