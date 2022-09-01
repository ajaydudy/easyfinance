/********************************************************************************
** Form generated from reading ui file 'loandialog.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOANDIALOG_H
#define UI_LOANDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_LoanDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEditID;
    QLabel *label_16;
    QDateEdit *dateEditCase;
    QLabel *label;
    QComboBox *cboName;
    QToolButton *cmdCustomer;
    QLabel *label_3;
    QComboBox *cboType;
    QGroupBox *groupAuto;
    QGridLayout *gridLayout_5;
    QLabel *label_17;
    QLineEdit *lineEditVh;
    QLabel *label_18;
    QLineEdit *lineEditReg;
    QLabel *label_19;
    QLineEdit *lineEditCh;
    QLabel *label_20;
    QLineEdit *lineEditEng;
    QLabel *label_21;
    QToolButton *cmdDealer;
    QComboBox *cboDealer;
    QLabel *label_4;
    QComboBox *cbogrntr;
    QLabel *label_22;
    QLineEdit *lineEditGRfile;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_4;
    QSpinBox *spinBoxPenalty;
    QToolButton *cmdGrntr;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_6;
    QLabel *label_24;
    QLineEdit *lineEditPfrom;
    QLabel *label_23;
    QLineEdit *lineEditPto;
    QLabel *label_25;
    QLineEdit *lineEditBK;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_26;
    QSpinBox *spinBox;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonMonthly;
    QRadioButton *radioButtonWeekly;
    QRadioButton *radioButtonDaily;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditCost;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLineEdit *lineEditHire;
    QLabel *label_7;
    QLineEdit *lineEditAmount;
    QLineEdit *lineEditDlPayment;
    QLabel *label_28;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLineEdit *lineEditEMI;
    QLabel *label_11;
    QLineEdit *lineEditNoEMI;
    QLabel *label_13;
    QLineEdit *lineEditIR;
    QLabel *label_12;
    QLabel *label_14;
    QLineEdit *lineEditReducing;
    QLabel *label_15;
    QLabel *label_8;
    QDateEdit *dateEditStart;
    QLabel *label_9;
    QDateEdit *dateEditFinish;
    QPushButton *cmdSchedule;
    QCheckBox *checkBox;
    QFrame *line;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *LoanDialog)
    {
        if (LoanDialog->objectName().isEmpty())
            LoanDialog->setObjectName(QString::fromUtf8("LoanDialog"));
        LoanDialog->resize(757, 617);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoanDialog->sizePolicy().hasHeightForWidth());
        LoanDialog->setSizePolicy(sizePolicy);
        LoanDialog->setLayoutDirection(Qt::LeftToRight);
        LoanDialog->setSizeGripEnabled(true);
        gridLayout_4 = new QGridLayout(LoanDialog);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(LoanDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));
        lineEditID->setReadOnly(true);

        gridLayout->addWidget(lineEditID, 0, 1, 1, 3);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 1, 0, 1, 1);

        dateEditCase = new QDateEdit(groupBox);
        dateEditCase->setObjectName(QString::fromUtf8("dateEditCase"));
        dateEditCase->setCalendarPopup(true);

        gridLayout->addWidget(dateEditCase, 1, 1, 1, 3);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        cboName = new QComboBox(groupBox);
        cboName->setObjectName(QString::fromUtf8("cboName"));
        cboName->setEditable(false);

        gridLayout->addWidget(cboName, 2, 1, 1, 3);

        cmdCustomer = new QToolButton(groupBox);
        cmdCustomer->setObjectName(QString::fromUtf8("cmdCustomer"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        cmdCustomer->setFont(font);

        gridLayout->addWidget(cmdCustomer, 2, 4, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        cboType = new QComboBox(groupBox);
        cboType->setObjectName(QString::fromUtf8("cboType"));
        cboType->setEditable(false);

        gridLayout->addWidget(cboType, 3, 1, 1, 3);

        groupAuto = new QGroupBox(groupBox);
        groupAuto->setObjectName(QString::fromUtf8("groupAuto"));
        gridLayout_5 = new QGridLayout(groupAuto);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_17 = new QLabel(groupAuto);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_5->addWidget(label_17, 1, 0, 1, 1);

        lineEditVh = new QLineEdit(groupAuto);
        lineEditVh->setObjectName(QString::fromUtf8("lineEditVh"));

        gridLayout_5->addWidget(lineEditVh, 1, 2, 1, 1);

        label_18 = new QLabel(groupAuto);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_5->addWidget(label_18, 2, 0, 1, 1);

        lineEditReg = new QLineEdit(groupAuto);
        lineEditReg->setObjectName(QString::fromUtf8("lineEditReg"));

        gridLayout_5->addWidget(lineEditReg, 2, 2, 1, 1);

        label_19 = new QLabel(groupAuto);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_5->addWidget(label_19, 3, 0, 1, 1);

        lineEditCh = new QLineEdit(groupAuto);
        lineEditCh->setObjectName(QString::fromUtf8("lineEditCh"));

        gridLayout_5->addWidget(lineEditCh, 3, 2, 1, 1);

        label_20 = new QLabel(groupAuto);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_5->addWidget(label_20, 4, 0, 1, 1);

        lineEditEng = new QLineEdit(groupAuto);
        lineEditEng->setObjectName(QString::fromUtf8("lineEditEng"));

        gridLayout_5->addWidget(lineEditEng, 4, 2, 1, 1);

        label_21 = new QLabel(groupAuto);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_5->addWidget(label_21, 0, 0, 1, 1);

        cmdDealer = new QToolButton(groupAuto);
        cmdDealer->setObjectName(QString::fromUtf8("cmdDealer"));
        cmdDealer->setFont(font);

        gridLayout_5->addWidget(cmdDealer, 0, 3, 1, 1);

        cboDealer = new QComboBox(groupAuto);
        cboDealer->setObjectName(QString::fromUtf8("cboDealer"));

        gridLayout_5->addWidget(cboDealer, 0, 2, 1, 1);


        gridLayout->addWidget(groupAuto, 4, 0, 1, 5);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        cbogrntr = new QComboBox(groupBox);
        cbogrntr->setObjectName(QString::fromUtf8("cbogrntr"));
        cbogrntr->setEditable(false);

        gridLayout->addWidget(cbogrntr, 5, 1, 1, 3);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 6, 0, 1, 1);

        lineEditGRfile = new QLineEdit(groupBox);
        lineEditGRfile->setObjectName(QString::fromUtf8("lineEditGRfile"));

        gridLayout->addWidget(lineEditGRfile, 6, 1, 1, 4);

        label_27 = new QLabel(groupBox);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout->addWidget(label_27, 7, 0, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(53, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 7, 2, 1, 1);

        spinBoxPenalty = new QSpinBox(groupBox);
        spinBoxPenalty->setObjectName(QString::fromUtf8("spinBoxPenalty"));

        gridLayout->addWidget(spinBoxPenalty, 7, 3, 1, 1);

        cmdGrntr = new QToolButton(groupBox);
        cmdGrntr->setObjectName(QString::fromUtf8("cmdGrntr"));
        cmdGrntr->setFont(font);

        gridLayout->addWidget(cmdGrntr, 5, 4, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 4, 1);

        groupBox_5 = new QGroupBox(LoanDialog);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_6 = new QGridLayout(groupBox_5);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_24 = new QLabel(groupBox_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_6->addWidget(label_24, 1, 0, 1, 1);

        lineEditPfrom = new QLineEdit(groupBox_5);
        lineEditPfrom->setObjectName(QString::fromUtf8("lineEditPfrom"));

        gridLayout_6->addWidget(lineEditPfrom, 1, 2, 1, 1);

        label_23 = new QLabel(groupBox_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_6->addWidget(label_23, 1, 3, 1, 1);

        lineEditPto = new QLineEdit(groupBox_5);
        lineEditPto->setObjectName(QString::fromUtf8("lineEditPto"));

        gridLayout_6->addWidget(lineEditPto, 1, 4, 1, 1);

        label_25 = new QLabel(groupBox_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_6->addWidget(label_25, 2, 0, 1, 1);

        lineEditBK = new QLineEdit(groupBox_5);
        lineEditBK->setObjectName(QString::fromUtf8("lineEditBK"));

        gridLayout_6->addWidget(lineEditBK, 2, 2, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 5, 1, 1);

        label_26 = new QLabel(groupBox_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_6->addWidget(label_26, 0, 0, 1, 1);

        spinBox = new QSpinBox(groupBox_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(1);

        gridLayout_6->addWidget(spinBox, 0, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 0, 1, 1, 1);

        groupBox_4 = new QGroupBox(LoanDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonMonthly = new QRadioButton(groupBox_4);
        radioButtonMonthly->setObjectName(QString::fromUtf8("radioButtonMonthly"));
        radioButtonMonthly->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonMonthly);

        radioButtonWeekly = new QRadioButton(groupBox_4);
        radioButtonWeekly->setObjectName(QString::fromUtf8("radioButtonWeekly"));

        horizontalLayout_2->addWidget(radioButtonWeekly);

        radioButtonDaily = new QRadioButton(groupBox_4);
        radioButtonDaily->setObjectName(QString::fromUtf8("radioButtonDaily"));

        horizontalLayout_2->addWidget(radioButtonDaily);


        gridLayout_4->addWidget(groupBox_4, 1, 1, 1, 1);

        groupBox_2 = new QGroupBox(LoanDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEditCost = new QLineEdit(groupBox_2);
        lineEditCost->setObjectName(QString::fromUtf8("lineEditCost"));

        gridLayout_2->addWidget(lineEditCost, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(26, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEditHire = new QLineEdit(groupBox_2);
        lineEditHire->setObjectName(QString::fromUtf8("lineEditHire"));

        gridLayout_2->addWidget(lineEditHire, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        lineEditAmount = new QLineEdit(groupBox_2);
        lineEditAmount->setObjectName(QString::fromUtf8("lineEditAmount"));

        gridLayout_2->addWidget(lineEditAmount, 2, 1, 1, 1);

        lineEditDlPayment = new QLineEdit(groupBox_2);
        lineEditDlPayment->setObjectName(QString::fromUtf8("lineEditDlPayment"));

        gridLayout_2->addWidget(lineEditDlPayment, 3, 1, 1, 1);

        label_28 = new QLabel(groupBox_2);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_2->addWidget(label_28, 3, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(LoanDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        lineEditEMI = new QLineEdit(groupBox_3);
        lineEditEMI->setObjectName(QString::fromUtf8("lineEditEMI"));

        gridLayout_3->addWidget(lineEditEMI, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        lineEditNoEMI = new QLineEdit(groupBox_3);
        lineEditNoEMI->setObjectName(QString::fromUtf8("lineEditNoEMI"));

        gridLayout_3->addWidget(lineEditNoEMI, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_3->addWidget(label_13, 2, 0, 1, 1);

        lineEditIR = new QLineEdit(groupBox_3);
        lineEditIR->setObjectName(QString::fromUtf8("lineEditIR"));
        lineEditIR->setReadOnly(true);

        gridLayout_3->addWidget(lineEditIR, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 2, 2, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 3, 0, 1, 1);

        lineEditReducing = new QLineEdit(groupBox_3);
        lineEditReducing->setObjectName(QString::fromUtf8("lineEditReducing"));
        lineEditReducing->setReadOnly(true);

        gridLayout_3->addWidget(lineEditReducing, 3, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 3, 2, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        dateEditStart = new QDateEdit(groupBox_3);
        dateEditStart->setObjectName(QString::fromUtf8("dateEditStart"));
        dateEditStart->setCalendarPopup(true);

        gridLayout_3->addWidget(dateEditStart, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 5, 0, 1, 1);

        dateEditFinish = new QDateEdit(groupBox_3);
        dateEditFinish->setObjectName(QString::fromUtf8("dateEditFinish"));
        dateEditFinish->setReadOnly(true);
        dateEditFinish->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateEditFinish->setMinimumDateTime(QDateTime(QDate(1752, 11, 14), QTime(0, 0, 0)));
        dateEditFinish->setCalendarPopup(false);

        gridLayout_3->addWidget(dateEditFinish, 5, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 3, 1, 1, 1);

        cmdSchedule = new QPushButton(LoanDialog);
        cmdSchedule->setObjectName(QString::fromUtf8("cmdSchedule"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        cmdSchedule->setFont(font1);

        gridLayout_4->addWidget(cmdSchedule, 4, 0, 1, 2);

        checkBox = new QCheckBox(LoanDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        checkBox->setFont(font2);
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(217, 0, 0);\n"
""));

        gridLayout_4->addWidget(checkBox, 5, 0, 1, 1);

        line = new QFrame(LoanDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line, 6, 0, 1, 2);

        frame = new QFrame(LoanDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(16777215, 33));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(0);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 2, 2, 2);
        horizontalSpacer = new QSpacerItem(107, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout_4->addWidget(frame, 7, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(lineEditID);
        label_16->setBuddy(dateEditCase);
        label->setBuddy(cboName);
        label_3->setBuddy(cboType);
        label_17->setBuddy(lineEditVh);
        label_18->setBuddy(lineEditReg);
        label_19->setBuddy(lineEditCh);
        label_20->setBuddy(lineEditEng);
        label_21->setBuddy(cboDealer);
        label_4->setBuddy(cbogrntr);
        label_22->setBuddy(lineEditGRfile);
        label_24->setBuddy(lineEditPfrom);
        label_23->setBuddy(lineEditPto);
        label_25->setBuddy(lineEditBK);
        label_5->setBuddy(lineEditCost);
        label_6->setBuddy(lineEditHire);
        label_7->setBuddy(lineEditAmount);
        label_10->setBuddy(lineEditEMI);
        label_11->setBuddy(lineEditNoEMI);
        label_13->setBuddy(lineEditIR);
        label_14->setBuddy(lineEditReducing);
        label_8->setBuddy(dateEditStart);
        label_9->setBuddy(dateEditFinish);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(dateEditCase, cboName);
        QWidget::setTabOrder(cboName, cboType);
        QWidget::setTabOrder(cboType, cboDealer);
        QWidget::setTabOrder(cboDealer, lineEditVh);
        QWidget::setTabOrder(lineEditVh, lineEditReg);
        QWidget::setTabOrder(lineEditReg, lineEditCh);
        QWidget::setTabOrder(lineEditCh, lineEditEng);
        QWidget::setTabOrder(lineEditEng, cbogrntr);
        QWidget::setTabOrder(cbogrntr, lineEditGRfile);
        QWidget::setTabOrder(lineEditGRfile, spinBox);
        QWidget::setTabOrder(spinBox, lineEditPfrom);
        QWidget::setTabOrder(lineEditPfrom, lineEditPto);
        QWidget::setTabOrder(lineEditPto, lineEditBK);
        QWidget::setTabOrder(lineEditBK, lineEditCost);
        QWidget::setTabOrder(lineEditCost, lineEditHire);
        QWidget::setTabOrder(lineEditHire, lineEditAmount);
        QWidget::setTabOrder(lineEditAmount, lineEditEMI);
        QWidget::setTabOrder(lineEditEMI, lineEditNoEMI);
        QWidget::setTabOrder(lineEditNoEMI, lineEditIR);
        QWidget::setTabOrder(lineEditIR, lineEditReducing);
        QWidget::setTabOrder(lineEditReducing, dateEditStart);
        QWidget::setTabOrder(dateEditStart, dateEditFinish);
        QWidget::setTabOrder(dateEditFinish, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, cmdSchedule);
        QWidget::setTabOrder(cmdSchedule, cmdCustomer);
        QWidget::setTabOrder(cmdCustomer, lineEditID);
        QWidget::setTabOrder(lineEditID, cmdDealer);

        retranslateUi(LoanDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), LoanDialog, SLOT(reject()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), LoanDialog, SLOT(save()));
        QObject::connect(cmdGrntr, SIGNAL(clicked()), LoanDialog, SLOT(showGuarantor()));
        QObject::connect(lineEditNoEMI, SIGNAL(editingFinished()), LoanDialog, SLOT(calculateRate()));
        QObject::connect(lineEditEMI, SIGNAL(editingFinished()), LoanDialog, SLOT(calculateRate()));
        QObject::connect(lineEditAmount, SIGNAL(editingFinished()), LoanDialog, SLOT(calculateRate()));
        QObject::connect(cmdCustomer, SIGNAL(clicked()), LoanDialog, SLOT(showCustomer()));
        QObject::connect(dateEditStart, SIGNAL(dateChanged(QDate)), LoanDialog, SLOT(setFinishDate()));
        QObject::connect(lineEditNoEMI, SIGNAL(editingFinished()), LoanDialog, SLOT(setFinishDate()));
        QObject::connect(cbogrntr, SIGNAL(currentIndexChanged(int)), LoanDialog, SLOT(getGrID()));
        QObject::connect(cmdSchedule, SIGNAL(clicked()), LoanDialog, SLOT(showSchedule()));
        QObject::connect(cboName, SIGNAL(currentIndexChanged(int)), LoanDialog, SLOT(getCsID()));
        QObject::connect(cboType, SIGNAL(currentIndexChanged(QString)), LoanDialog, SLOT(enableAuto()));
        QObject::connect(cmdDealer, SIGNAL(clicked()), LoanDialog, SLOT(showDealer()));
        QObject::connect(cboDealer, SIGNAL(currentIndexChanged(int)), LoanDialog, SLOT(getDlID()));
        QObject::connect(lineEditHire, SIGNAL(editingFinished()), LoanDialog, SLOT(getAmountFinanced()));
        QObject::connect(lineEditCost, SIGNAL(editingFinished()), LoanDialog, SLOT(getAmountFinanced()));
        QObject::connect(lineEditPfrom, SIGNAL(editingFinished()), LoanDialog, SLOT(showPdc()));

        QMetaObject::connectSlotsByName(LoanDialog);
    } // setupUi

    void retranslateUi(QDialog *LoanDialog)
    {
        LoanDialog->setWindowTitle(QApplication::translate("LoanDialog", "Enter New Loan", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LoanDialog", "Basic Details", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LoanDialog", "Loan No.", 0, QApplication::UnicodeUTF8));
        lineEditID->setStyleSheet(QApplication::translate("LoanDialog", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("LoanDialog", "Case Date           *", 0, QApplication::UnicodeUTF8));
        dateEditCase->setDisplayFormat(QApplication::translate("LoanDialog", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoanDialog", "Customer Name  *", 0, QApplication::UnicodeUTF8));
        cmdCustomer->setText(QApplication::translate("LoanDialog", "+", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LoanDialog", "Loan Type           *", 0, QApplication::UnicodeUTF8));
        cboType->clear();
        cboType->insertItems(0, QStringList()
         << QApplication::translate("LoanDialog", "Auto Loan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LoanDialog", "Personal Loan", 0, QApplication::UnicodeUTF8)
        );
        groupAuto->setTitle(QApplication::translate("LoanDialog", "Auto Details", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("LoanDialog", "Vehicle Name     ", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("LoanDialog", "Registration No.", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("LoanDialog", "Chassis No.", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("LoanDialog", "Engine No.", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("LoanDialog", "Dealer", 0, QApplication::UnicodeUTF8));
        cmdDealer->setText(QApplication::translate("LoanDialog", "+", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LoanDialog", "Guarantor(Agent) ", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("LoanDialog", "Guarantor(File)", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("LoanDialog", "Penalty( Annual Rate of Percentage) ", 0, QApplication::UnicodeUTF8));
        cmdGrntr->setText(QApplication::translate("LoanDialog", "+", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("LoanDialog", "PDC Details", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("LoanDialog", "P.D.C. No. From", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("LoanDialog", "To", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("LoanDialog", "Bank Name", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("LoanDialog", "Total P.D.C.", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("LoanDialog", "Reducing Balance based on ", 0, QApplication::UnicodeUTF8));
        radioButtonMonthly->setText(QApplication::translate("LoanDialog", "Monthly Rests", 0, QApplication::UnicodeUTF8));
        radioButtonWeekly->setText(QApplication::translate("LoanDialog", "Weekly Rests", 0, QApplication::UnicodeUTF8));
        radioButtonDaily->setText(QApplication::translate("LoanDialog", "Daily Rests", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LoanDialog", "Financial Details", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LoanDialog", "Total Cost         *", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LoanDialog", "Initial Hire         *", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LoanDialog", "Amount Financed", 0, QApplication::UnicodeUTF8));
        lineEditAmount->setText(QString());
        label_28->setText(QApplication::translate("LoanDialog", "Dealer Payment", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("LoanDialog", "EMI's", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LoanDialog", "EMI Amount      *", 0, QApplication::UnicodeUTF8));
        lineEditEMI->setText(QString());
        label_11->setText(QApplication::translate("LoanDialog", "No of EMI's       *", 0, QApplication::UnicodeUTF8));
        lineEditNoEMI->setText(QString());
        label_13->setText(QApplication::translate("LoanDialog", "Flat Rate %", 0, QApplication::UnicodeUTF8));
        lineEditIR->setStyleSheet(QApplication::translate("LoanDialog", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("LoanDialog", "%   ", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("LoanDialog", "Reducing Rate %", 0, QApplication::UnicodeUTF8));
        lineEditReducing->setStyleSheet(QApplication::translate("LoanDialog", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("LoanDialog", "%", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LoanDialog", "Commencing Date", 0, QApplication::UnicodeUTF8));
        dateEditStart->setDisplayFormat(QApplication::translate("LoanDialog", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LoanDialog", "Finishing Date", 0, QApplication::UnicodeUTF8));
        dateEditFinish->setStyleSheet(QApplication::translate("LoanDialog", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        dateEditFinish->setDisplayFormat(QApplication::translate("LoanDialog", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        cmdSchedule->setText(QApplication::translate("LoanDialog", "Show Repayment Schedule", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("LoanDialog", "Loan Closed", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LoanDialog", "Save", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LoanDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LoanDialog);
    } // retranslateUi

};

namespace Ui {
    class LoanDialog: public Ui_LoanDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOANDIALOG_H
