/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Customer;
    QAction *actionAdd_Loan;
    QAction *actionLedger;
    QAction *actionLoan_Report;
    QAction *actionAbout;
    QAction *actionEdit_Record;
    QAction *actionDelete_Record;
    QAction *actionNew_Voucher;
    QAction *actionPrintPreview;
    QAction *actionHelp;
    QAction *action_Customer;
    QAction *action_Loan;
    QAction *action_Voucher;
    QAction *actionHelp_2;
    QAction *actionAbout_Easy_Finance;
    QAction *actionQuit;
    QAction *action_Edit_Record;
    QAction *action_Delete_Record;
    QAction *actionQuit_nApplication;
    QAction *actionEmiTool;
    QAction *actionTotal_Interest_Earned;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frameDetail;
    QGridLayout *gridLayout;
    QLabel *labelHeader;
    QLabel *label;
    QLineEdit *lineEditLoanNo;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_8;
    QLineEdit *lineEditEMI;
    QLabel *labelRt;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *lineEditCustName;
    QLabel *labelAg;
    QLineEdit *lineEditAmount;
    QLabel *labelPl;
    QLineEdit *lineEditPenalty;
    QTableView *tableView;
    QTextEdit *textEdit;
    QFrame *frameFooter;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEditPPAmt;
    QLabel *label_9;
    QLineEdit *lineEditOverdue;
    QLabel *label_6;
    QLineEdit *lineEditHireRC;
    QLabel *labelAg_2;
    QLineEdit *lineEditBounce;
    QLabel *label_5;
    QLineEdit *lineEditPossesion;
    QLabel *labelPl_2;
    QLineEdit *lineEditTotal;
    QListWidget *treeWidget;
    QToolBar *mainToolBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 711);
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionAdd_Customer = new QAction(MainWindow);
        actionAdd_Customer->setObjectName(QString::fromUtf8("actionAdd_Customer"));
        actionAdd_Customer->setEnabled(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/categories/preferences-desktop-personal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Customer->setIcon(icon);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        actionAdd_Customer->setFont(font);
        actionAdd_Loan = new QAction(MainWindow);
        actionAdd_Loan->setObjectName(QString::fromUtf8("actionAdd_Loan"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/mimetypes/x-office-document.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Loan->setIcon(icon1);
        actionAdd_Loan->setFont(font);
        actionLedger = new QAction(MainWindow);
        actionLedger->setObjectName(QString::fromUtf8("actionLedger"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/mimetypes/application-vnd.ms-excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLedger->setIcon(icon2);
        actionLedger->setFont(font);
        actionLoan_Report = new QAction(MainWindow);
        actionLoan_Report->setObjectName(QString::fromUtf8("actionLoan_Report"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/stock_print-setup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoan_Report->setIcon(icon3);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/apps/invest-applet.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon4);
        actionAbout->setFont(font);
        actionEdit_Record = new QAction(MainWindow);
        actionEdit_Record->setObjectName(QString::fromUtf8("actionEdit_Record"));
        actionEdit_Record->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/document-save-as.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_Record->setIcon(icon5);
        actionEdit_Record->setFont(font);
        actionDelete_Record = new QAction(MainWindow);
        actionDelete_Record->setObjectName(QString::fromUtf8("actionDelete_Record"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/editdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_Record->setIcon(icon6);
        actionDelete_Record->setFont(font);
        actionNew_Voucher = new QAction(MainWindow);
        actionNew_Voucher->setObjectName(QString::fromUtf8("actionNew_Voucher"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/edit-select-all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Voucher->setIcon(icon7);
        actionNew_Voucher->setFont(font);
        actionPrintPreview = new QAction(MainWindow);
        actionPrintPreview->setObjectName(QString::fromUtf8("actionPrintPreview"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/gtk-print-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrintPreview->setIcon(icon8);
        actionPrintPreview->setFont(font);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/apps/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon9);
        actionHelp->setFont(font);
        action_Customer = new QAction(MainWindow);
        action_Customer->setObjectName(QString::fromUtf8("action_Customer"));
        action_Customer->setIcon(icon);
        action_Loan = new QAction(MainWindow);
        action_Loan->setObjectName(QString::fromUtf8("action_Loan"));
        action_Loan->setIcon(icon1);
        action_Voucher = new QAction(MainWindow);
        action_Voucher->setObjectName(QString::fromUtf8("action_Voucher"));
        action_Voucher->setIcon(icon7);
        actionHelp_2 = new QAction(MainWindow);
        actionHelp_2->setObjectName(QString::fromUtf8("actionHelp_2"));
        actionHelp_2->setIcon(icon9);
        actionAbout_Easy_Finance = new QAction(MainWindow);
        actionAbout_Easy_Finance->setObjectName(QString::fromUtf8("actionAbout_Easy_Finance"));
        actionAbout_Easy_Finance->setIcon(icon4);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/actions/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon10);
        action_Edit_Record = new QAction(MainWindow);
        action_Edit_Record->setObjectName(QString::fromUtf8("action_Edit_Record"));
        action_Edit_Record->setIcon(icon5);
        action_Delete_Record = new QAction(MainWindow);
        action_Delete_Record->setObjectName(QString::fromUtf8("action_Delete_Record"));
        action_Delete_Record->setIcon(icon6);
        actionQuit_nApplication = new QAction(MainWindow);
        actionQuit_nApplication->setObjectName(QString::fromUtf8("actionQuit_nApplication"));
        actionQuit_nApplication->setIcon(icon10);
        actionQuit_nApplication->setFont(font);
        actionEmiTool = new QAction(MainWindow);
        actionEmiTool->setObjectName(QString::fromUtf8("actionEmiTool"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/prefix1/images/Cal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEmiTool->setIcon(icon11);
        actionTotal_Interest_Earned = new QAction(MainWindow);
        actionTotal_Interest_Earned->setObjectName(QString::fromUtf8("actionTotal_Interest_Earned"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(1);
        gridLayout_3->setMargin(1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(1);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 0, 1, 1);
        frameDetail = new QFrame(frame);
        frameDetail->setObjectName(QString::fromUtf8("frameDetail"));
        frameDetail->setFont(font);
        frameDetail->setFrameShape(QFrame::Box);
        frameDetail->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frameDetail);
        gridLayout->setSpacing(6);
        gridLayout->setMargin(11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, -1);
        labelHeader = new QLabel(frameDetail);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        labelHeader->setFont(font1);
        labelHeader->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0.443, x2:1, y2:0.489, stop:0 rgba(9, 98, 183, 255), stop:1 rgba(123, 183, 242, 255));\n"
"color: rgb(255, 255, 255);"));
        labelHeader->setFrameShape(QFrame::StyledPanel);
        labelHeader->setTextFormat(Qt::PlainText);
        labelHeader->setScaledContents(false);
        labelHeader->setAlignment(Qt::AlignCenter);
        labelHeader->setMargin(3);
        labelHeader->setIndent(2);

        gridLayout->addWidget(labelHeader, 0, 0, 1, 9);

        label = new QLabel(frameDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditLoanNo = new QLineEdit(frameDetail);
        lineEditLoanNo->setObjectName(QString::fromUtf8("lineEditLoanNo"));
        lineEditLoanNo->setFont(font);
        lineEditLoanNo->setReadOnly(false);

        gridLayout->addWidget(lineEditLoanNo, 1, 1, 1, 1);

        label_3 = new QLabel(frameDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        dateEdit = new QDateEdit(frameDetail);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setFont(font);
        dateEdit->setReadOnly(true);

        gridLayout->addWidget(dateEdit, 1, 3, 1, 1);

        label_8 = new QLabel(frameDetail);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label_8, 1, 4, 1, 1);

        lineEditEMI = new QLineEdit(frameDetail);
        lineEditEMI->setObjectName(QString::fromUtf8("lineEditEMI"));
        lineEditEMI->setFont(font);
        lineEditEMI->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditEMI->setReadOnly(true);

        gridLayout->addWidget(lineEditEMI, 1, 5, 1, 1);

        labelRt = new QLabel(frameDetail);
        labelRt->setObjectName(QString::fromUtf8("labelRt"));
        labelRt->setFont(font);
        labelRt->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(labelRt, 1, 6, 1, 1);

        spinBox = new QSpinBox(frameDetail);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(48, 20));
        spinBox->setFont(font);
        spinBox->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(spinBox, 1, 7, 1, 1);

        pushButton = new QPushButton(frameDetail);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 8, 1, 1);

        label_2 = new QLabel(frameDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEditCustName = new QLineEdit(frameDetail);
        lineEditCustName->setObjectName(QString::fromUtf8("lineEditCustName"));
        lineEditCustName->setFont(font);
        lineEditCustName->setReadOnly(false);

        gridLayout->addWidget(lineEditCustName, 2, 1, 1, 3);

        labelAg = new QLabel(frameDetail);
        labelAg->setObjectName(QString::fromUtf8("labelAg"));
        labelAg->setFont(font);
        labelAg->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(labelAg, 2, 4, 1, 1);

        lineEditAmount = new QLineEdit(frameDetail);
        lineEditAmount->setObjectName(QString::fromUtf8("lineEditAmount"));
        lineEditAmount->setFont(font);
        lineEditAmount->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditAmount->setReadOnly(true);

        gridLayout->addWidget(lineEditAmount, 2, 5, 1, 1);

        labelPl = new QLabel(frameDetail);
        labelPl->setObjectName(QString::fromUtf8("labelPl"));
        labelPl->setFont(font);
        labelPl->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(labelPl, 2, 6, 1, 1);

        lineEditPenalty = new QLineEdit(frameDetail);
        lineEditPenalty->setObjectName(QString::fromUtf8("lineEditPenalty"));
        lineEditPenalty->setFont(font);
        lineEditPenalty->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        lineEditPenalty->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditPenalty, 2, 7, 1, 2);


        verticalLayout->addWidget(frameDetail);

        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMouseTracking(true);
        tableView->setFrameShape(QFrame::Box);
        tableView->setFrameShadow(QFrame::Sunken);
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setTextElideMode(Qt::ElideRight);
        tableView->setShowGrid(true);
        tableView->setSortingEnabled(false);
        tableView->setWordWrap(true);
        tableView->setCornerButtonEnabled(false);
        tableView->horizontalHeader()->setDefaultSectionSize(100);
        tableView->horizontalHeader()->setStretchLastSection(false);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        frameFooter = new QFrame(frame);
        frameFooter->setObjectName(QString::fromUtf8("frameFooter"));
        frameFooter->setFont(font);
        frameFooter->setFrameShape(QFrame::Box);
        frameFooter->setFrameShadow(QFrame::Sunken);
        gridLayout_2 = new QGridLayout(frameFooter);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(frameFooter);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        lineEditPPAmt = new QLineEdit(frameFooter);
        lineEditPPAmt->setObjectName(QString::fromUtf8("lineEditPPAmt"));
        lineEditPPAmt->setFont(font);
        lineEditPPAmt->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPPAmt->setReadOnly(true);

        gridLayout_2->addWidget(lineEditPPAmt, 0, 1, 1, 1);

        label_9 = new QLabel(frameFooter);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(label_9, 0, 2, 1, 1);

        lineEditOverdue = new QLineEdit(frameFooter);
        lineEditOverdue->setObjectName(QString::fromUtf8("lineEditOverdue"));
        lineEditOverdue->setFont(font);
        lineEditOverdue->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditOverdue->setReadOnly(true);

        gridLayout_2->addWidget(lineEditOverdue, 0, 3, 1, 1);

        label_6 = new QLabel(frameFooter);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEditHireRC = new QLineEdit(frameFooter);
        lineEditHireRC->setObjectName(QString::fromUtf8("lineEditHireRC"));
        lineEditHireRC->setFont(font);
        lineEditHireRC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditHireRC->setReadOnly(true);

        gridLayout_2->addWidget(lineEditHireRC, 1, 1, 1, 1);

        labelAg_2 = new QLabel(frameFooter);
        labelAg_2->setObjectName(QString::fromUtf8("labelAg_2"));
        labelAg_2->setFont(font);
        labelAg_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(labelAg_2, 1, 2, 1, 1);

        lineEditBounce = new QLineEdit(frameFooter);
        lineEditBounce->setObjectName(QString::fromUtf8("lineEditBounce"));
        lineEditBounce->setFont(font);
        lineEditBounce->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditBounce->setReadOnly(true);

        gridLayout_2->addWidget(lineEditBounce, 1, 3, 1, 1);

        label_5 = new QLabel(frameFooter);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineEditPossesion = new QLineEdit(frameFooter);
        lineEditPossesion->setObjectName(QString::fromUtf8("lineEditPossesion"));
        lineEditPossesion->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);"));
        lineEditPossesion->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditPossesion->setReadOnly(true);

        gridLayout_2->addWidget(lineEditPossesion, 2, 1, 1, 1);

        labelPl_2 = new QLabel(frameFooter);
        labelPl_2->setObjectName(QString::fromUtf8("labelPl_2"));
        labelPl_2->setFont(font);
        labelPl_2->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout_2->addWidget(labelPl_2, 2, 2, 1, 1);

        lineEditTotal = new QLineEdit(frameFooter);
        lineEditTotal->setObjectName(QString::fromUtf8("lineEditTotal"));
        lineEditTotal->setFont(font);
        lineEditTotal->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);"));
        lineEditTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotal->setReadOnly(true);

        gridLayout_2->addWidget(lineEditTotal, 2, 3, 1, 1);


        verticalLayout->addWidget(frameFooter);


        gridLayout_3->addWidget(frame, 0, 1, 1, 1);

        treeWidget = new QListWidget(centralWidget);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/prefix1/images/User-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(treeWidget);
        __qlistwidgetitem->setIcon(icon12);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/prefix1/images/money.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem1->setIcon(icon13);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/prefix1/images/check.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem2->setIcon(icon14);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/prefix1/images/liquid-ledger-demo.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem3->setIcon(icon15);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem4->setIcon(icon15);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/mimetypes/x-office-tasks.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem5 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem5->setIcon(icon16);
        QListWidgetItem *__qlistwidgetitem6 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem6->setIcon(icon2);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/prefix1/images/login-page-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem7 = new QListWidgetItem(treeWidget);
        __qlistwidgetitem7->setIcon(icon17);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setMaximumSize(QSize(152, 16777215));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        treeWidget->setFont(font2);
        treeWidget->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(220, 207, 187, 255), stop:1 rgba(239, 239, 239, 255));\n"
"\n"
"}\n"
"\n"
"/* QListWidget::item :selected {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"	color: rgb(4, 4, 4);\n"
"	border-color: rgb(0, 0, 0);\n"
" }*/\n"
""));
        treeWidget->setFrameShape(QFrame::Box);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setAlternatingRowColors(false);
        treeWidget->setIconSize(QSize(42, 46));
        treeWidget->setTextElideMode(Qt::ElideRight);
        treeWidget->setMovement(QListView::Static);
        treeWidget->setFlow(QListView::TopToBottom);
        treeWidget->setProperty("isWrapping", QVariant(false));
        treeWidget->setResizeMode(QListView::Adjust);
        treeWidget->setLayoutMode(QListView::SinglePass);
        treeWidget->setSpacing(4);
        treeWidget->setViewMode(QListView::ListMode);
        treeWidget->setUniformItemSizes(true);
        treeWidget->setWordWrap(true);
        treeWidget->setSelectionRectVisible(true);

        gridLayout_3->addWidget(treeWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Segoe UI"));
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        mainToolBar->setFont(font3);
        mainToolBar->setLayoutDirection(Qt::LeftToRight);
        mainToolBar->setStyleSheet(QString::fromUtf8("QToolBar{\n"
"	background-color: qlineargradient(spread:pad, x1:0.467, y1:1, x2:0.473, y2:0, stop:0 rgba(220, 207, 187, 255), stop:1 rgba(239, 239, 239, 255));\n"
"  border-width: 2px;\n"
"	\n"
"	color: rgb(8, 8, 8);\n"
"}\n"
"QToolButton { /* all types of tool button */\n"
"    /* border: 1px solid #8f8f91;*/\n"
"     border-radius: 2px;\n"
"	font: 75 8pt \"Segoe UI\";\n"
"    font:Bold;\n"
"    /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                         stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
" }\n"
"\n"
" QToolButton[popupMode=\"1\"] { /* only for MenuButtonPopup */\n"
"     padding-right: 20px; /* make way for the popup button */\n"
" }\n"
" QToolButton:hover {\n"
"	\n"
"	\n"
"	\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.656, fx:0.517, fy:1, stop:0 rgba(1, 116, 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.656, fx:0.517, fy:1, stop:0 rgba(0, 255,"
                        " 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"  border: 1px  solid #8f8f91;\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.964, fx:0.494273, fy:1, stop:0 rgba(0, 255, 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"	/*border-color: rgb(0, 255, 213);*/\n"
"	border-color: rgb(217, 217, 217);\n"
"\n"
" }\n"
" QToolButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"	color: rgb(4, 4, 4);\n"
"	border-color: rgb(0, 0, 0);\n"
" }\n"
"\n"
" /* the subcontrols below are used only in the MenuButtonPopup mode */\n"
" /*QToolButton::menu-button {\n"
"     border: 2px solid gray;\n"
"     border-top-right-radius: 6px;\n"
"     border-bottom-right-radius: 6px;\n"
"     /* 16px width + 4px for border = 20px allocated above */\n"
"    /* width: 16px;\n"
" }*/\n"
"\n"
""));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setLayoutDirection(Qt::RightToLeft);
        toolBar->setStyleSheet(QString::fromUtf8("QToolBar{\n"
"	background-color: qlineargradient(spread:pad, x1:0.467, y1:1, x2:0.473, y2:0, stop:0 rgba(220, 207, 187, 255), stop:1 rgba(239, 239, 239, 255));\n"
"  border-width: 2px;\n"
"	\n"
"	color: rgb(8, 8, 8);\n"
"}\n"
"QToolButton { /* all types of tool button */\n"
"    /* border: 1px solid #8f8f91;*/\n"
"     border-radius: 2px;\n"
"	font: 75 8pt \"Segoe UI\";\n"
"    font:Bold;\n"
"    /* background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                         stop: 0 #f6f7fa, stop: 1 #dadbde);*/\n"
" }\n"
"\n"
" QToolButton[popupMode=\"1\"] { /* only for MenuButtonPopup */\n"
"     padding-right: 20px; /* make way for the popup button */\n"
" }\n"
" QToolButton:hover {\n"
"	\n"
"	\n"
"	\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.656, fx:0.517, fy:1, stop:0 rgba(1, 116, 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.656, fx:0.517, fy:1, stop:0 rgba(0, 255,"
                        " 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"  border: 1px  solid #8f8f91;\n"
"	background-color: qradialgradient(spread:pad, cx:0.488, cy:1, radius:0.964, fx:0.494273, fy:1, stop:0 rgba(0, 255, 255, 255), stop:0.846591 rgba(255, 255, 255, 0));\n"
"	/*border-color: rgb(0, 255, 213);*/\n"
"	border-color: rgb(217, 217, 217);\n"
"\n"
" }\n"
" QToolButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"	color: rgb(4, 4, 4);\n"
"	border-color: rgb(0, 0, 0);\n"
" }\n"
"\n"
" /* the subcontrols below are used only in the MenuButtonPopup mode */\n"
" /*QToolButton::menu-button {\n"
"     border: 2px solid gray;\n"
"     border-top-right-radius: 6px;\n"
"     border-bottom-right-radius: 6px;\n"
"     /* 16px width + 4px for border = 20px allocated above */\n"
"    /* width: 16px;\n"
" }*/\n"
"\n"
""));
        toolBar->setMovable(false);
        toolBar->setAllowedAreas(Qt::TopToolBarArea);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);
        QObject::connect(actionAdd_Customer, SIGNAL(triggered()), MainWindow, SLOT(showCustomer()));
        QObject::connect(actionAdd_Loan, SIGNAL(triggered()), MainWindow, SLOT(showLoan()));
        QObject::connect(actionAbout, SIGNAL(triggered()), MainWindow, SLOT(showAbout()));
        QObject::connect(actionNew_Voucher, SIGNAL(triggered()), MainWindow, SLOT(showVoucher()));
        QObject::connect(actionEdit_Record, SIGNAL(triggered()), MainWindow, SLOT(showEdit()));
        QObject::connect(MainWindow, SIGNAL(destroyed()), MainWindow, SLOT(crypt()));
        QObject::connect(actionPrintPreview, SIGNAL(triggered()), MainWindow, SLOT(filePrintPreview()));
        QObject::connect(actionDelete_Record, SIGNAL(triggered()), MainWindow, SLOT(recDelete()));
        QObject::connect(treeWidget, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(Activated()));
        QObject::connect(tableView, SIGNAL(clicked(QModelIndex)), MainWindow, SLOT(onTableViewActivated(QModelIndex)));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(refreshPenalty()));
        QObject::connect(lineEditLoanNo, SIGNAL(editingFinished()), MainWindow, SLOT(refreshLedger()));
        QObject::connect(actionQuit_nApplication, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(lineEditCustName, SIGNAL(editingFinished()), MainWindow, SLOT(refreshLoanNo()));
        QObject::connect(actionEmiTool, SIGNAL(triggered()), MainWindow, SLOT(showEmiTool()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Easy Finance 1.0", 0, QApplication::UnicodeUTF8));
        actionAdd_Customer->setIconText(QApplication::translate("MainWindow", "New \n"
"&Customer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_Customer->setToolTip(QApplication::translate("MainWindow", "New Customer", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAdd_Customer->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0, QApplication::UnicodeUTF8));
        actionAdd_Loan->setText(QApplication::translate("MainWindow", "New &Loan(ALT+L)", 0, QApplication::UnicodeUTF8));
        actionAdd_Loan->setIconText(QApplication::translate("MainWindow", "New \n"
"&Loan", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_Loan->setToolTip(QApplication::translate("MainWindow", "New Loan", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAdd_Loan->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0, QApplication::UnicodeUTF8));
        actionLedger->setText(QApplication::translate("MainWindow", "&Ledger", 0, QApplication::UnicodeUTF8));
        actionLedger->setIconText(QApplication::translate("MainWindow", "&Ledger", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionLedger->setToolTip(QApplication::translate("MainWindow", "Ledger", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionLedger->setShortcut(QApplication::translate("MainWindow", "Alt+G", 0, QApplication::UnicodeUTF8));
        actionLoan_Report->setText(QApplication::translate("MainWindow", "Loan Report", 0, QApplication::UnicodeUTF8));
        actionLoan_Report->setIconText(QApplication::translate("MainWindow", "Loan\n"
"Report", 0, QApplication::UnicodeUTF8));
        actionLoan_Report->setShortcut(QApplication::translate("MainWindow", "Alt+R", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About Easy Finance", 0, QApplication::UnicodeUTF8));
        actionAbout->setIconText(QApplication::translate("MainWindow", "About\n"
"Easy Finance", 0, QApplication::UnicodeUTF8));
        actionEdit_Record->setText(QApplication::translate("MainWindow", "Edit Record(ALT+E)", 0, QApplication::UnicodeUTF8));
        actionEdit_Record->setIconText(QApplication::translate("MainWindow", "&Edit\n"
"Record", 0, QApplication::UnicodeUTF8));
        actionEdit_Record->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0, QApplication::UnicodeUTF8));
        actionDelete_Record->setText(QApplication::translate("MainWindow", "Delete Record(ALT+D)", 0, QApplication::UnicodeUTF8));
        actionDelete_Record->setIconText(QApplication::translate("MainWindow", "&Delete\n"
"Record", 0, QApplication::UnicodeUTF8));
        actionDelete_Record->setShortcut(QApplication::translate("MainWindow", "Alt+D", 0, QApplication::UnicodeUTF8));
        actionNew_Voucher->setText(QApplication::translate("MainWindow", "New Voucher(ALT+V)", 0, QApplication::UnicodeUTF8));
        actionNew_Voucher->setIconText(QApplication::translate("MainWindow", "New\n"
"&Voucher", 0, QApplication::UnicodeUTF8));
        actionNew_Voucher->setShortcut(QApplication::translate("MainWindow", "Alt+V", 0, QApplication::UnicodeUTF8));
        actionPrintPreview->setText(QApplication::translate("MainWindow", "Print Preview", 0, QApplication::UnicodeUTF8));
        actionPrintPreview->setIconText(QApplication::translate("MainWindow", "&Print\n"
"Preview", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp->setIconText(QApplication::translate("MainWindow", "Help and\n"
"Support", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionHelp->setToolTip(QApplication::translate("MainWindow", "Help and Support", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Customer->setText(QApplication::translate("MainWindow", "New &Customer", 0, QApplication::UnicodeUTF8));
        action_Customer->setShortcut(QApplication::translate("MainWindow", "Alt+C", 0, QApplication::UnicodeUTF8));
        action_Loan->setText(QApplication::translate("MainWindow", "New &Loan", 0, QApplication::UnicodeUTF8));
        action_Loan->setShortcut(QApplication::translate("MainWindow", "Alt+L", 0, QApplication::UnicodeUTF8));
        action_Voucher->setText(QApplication::translate("MainWindow", "New &Voucher", 0, QApplication::UnicodeUTF8));
        action_Voucher->setShortcut(QApplication::translate("MainWindow", "Alt+V", 0, QApplication::UnicodeUTF8));
        actionHelp_2->setText(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
        actionHelp_2->setShortcut(QApplication::translate("MainWindow", "Alt+H", 0, QApplication::UnicodeUTF8));
        actionAbout_Easy_Finance->setText(QApplication::translate("MainWindow", "About Easy Finance", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Alt+Q", 0, QApplication::UnicodeUTF8));
        action_Edit_Record->setText(QApplication::translate("MainWindow", "&Edit Record", 0, QApplication::UnicodeUTF8));
        action_Edit_Record->setShortcut(QApplication::translate("MainWindow", "Alt+E", 0, QApplication::UnicodeUTF8));
        action_Delete_Record->setText(QApplication::translate("MainWindow", "&Delete Record", 0, QApplication::UnicodeUTF8));
        action_Delete_Record->setShortcut(QApplication::translate("MainWindow", "Alt+D", 0, QApplication::UnicodeUTF8));
        actionQuit_nApplication->setIconText(QApplication::translate("MainWindow", "Quit\n"
"Easy Finance", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionQuit_nApplication->setToolTip(QApplication::translate("MainWindow", "Quit Application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEmiTool->setText(QApplication::translate("MainWindow", "E.M.I. Tool", 0, QApplication::UnicodeUTF8));
        actionEmiTool->setIconText(QApplication::translate("MainWindow", "Tools and\n"
"Accessories", 0, QApplication::UnicodeUTF8));
        actionTotal_Interest_Earned->setText(QApplication::translate("MainWindow", "Total Interest Earned", 0, QApplication::UnicodeUTF8));
        labelHeader->setText(QApplication::translate("MainWindow", "Loan Account ledger", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Loan No", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Case Date", 0, QApplication::UnicodeUTF8));
        dateEdit->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("MainWindow", "dd/MMM/yyyy", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "E.M.I.", 0, QApplication::UnicodeUTF8));
        lineEditEMI->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        labelRt->setText(QApplication::translate("MainWindow", "Rate of Penalty", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "&View", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Customer Name", 0, QApplication::UnicodeUTF8));
        labelAg->setText(QApplication::translate("MainWindow", "Amount Agreed", 0, QApplication::UnicodeUTF8));
        lineEditAmount->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        labelPl->setText(QApplication::translate("MainWindow", "Total Penalty", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        tableView->setStatusTip(QApplication::translate("MainWindow", "099887", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.21053pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Pre -Payment Amount", 0, QApplication::UnicodeUTF8));
        lineEditPPAmt->setStyleSheet(QApplication::translate("MainWindow", "\n"
"background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Overdue Charges", 0, QApplication::UnicodeUTF8));
        lineEditOverdue->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Hire Money Receivable", 0, QApplication::UnicodeUTF8));
        lineEditHireRC->setStyleSheet(QApplication::translate("MainWindow", "\n"
"background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        labelAg_2->setText(QApplication::translate("MainWindow", "Cheque Boucing Charges", 0, QApplication::UnicodeUTF8));
        lineEditBounce->setStyleSheet(QApplication::translate("MainWindow", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Repossession Charges", 0, QApplication::UnicodeUTF8));
        labelPl_2->setText(QApplication::translate("MainWindow", "Total Premature Amount", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = treeWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Customers", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = treeWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Loans", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = treeWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Vouchers", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = treeWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Loan Ledger", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = treeWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Dealer Ledger", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = treeWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Guarantor Status", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = treeWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MainWindow", "Pre-Payment Schedule", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = treeWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MainWindow", "Users", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
