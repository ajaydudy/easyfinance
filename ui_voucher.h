/********************************************************************************
** Form generated from reading ui file 'voucher.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VOUCHER_H
#define UI_VOUCHER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Voucher
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEditID;
    QLabel *label_2;
    QComboBox *cboLoan;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_4;
    QDateEdit *dateEdit;
    QLabel *label_6;
    QLineEdit *lineEditNo;
    QComboBox *cboDC;
    QLabel *label_3;
    QLineEdit *lineEditAmount;
    QComboBox *cbodes;
    QPlainTextEdit *lineEditCust;
    QPushButton *pushButtonAdd;
    QTableView *tableView;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_9;
    QLineEdit *lineEditTotal;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Voucher)
    {
        if (Voucher->objectName().isEmpty())
            Voucher->setObjectName(QString::fromUtf8("Voucher"));
        Voucher->resize(808, 476);
        Voucher->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(Voucher);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Voucher);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));
        lineEditID->setReadOnly(true);

        gridLayout->addWidget(lineEditID, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        cboLoan = new QComboBox(groupBox);
        cboLoan->setObjectName(QString::fromUtf8("cboLoan"));

        gridLayout->addWidget(cboLoan, 0, 3, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_8, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 4, 1, 1);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        lineEditNo = new QLineEdit(groupBox);
        lineEditNo->setObjectName(QString::fromUtf8("lineEditNo"));

        gridLayout->addWidget(lineEditNo, 2, 1, 1, 1);

        cboDC = new QComboBox(groupBox);
        cboDC->setObjectName(QString::fromUtf8("cboDC"));

        gridLayout->addWidget(cboDC, 1, 5, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 4, 1, 1);

        lineEditAmount = new QLineEdit(groupBox);
        lineEditAmount->setObjectName(QString::fromUtf8("lineEditAmount"));

        gridLayout->addWidget(lineEditAmount, 2, 5, 1, 1);

        cbodes = new QComboBox(groupBox);
        cbodes->setObjectName(QString::fromUtf8("cbodes"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cbodes->sizePolicy().hasHeightForWidth());
        cbodes->setSizePolicy(sizePolicy);
        cbodes->setDuplicatesEnabled(false);

        gridLayout->addWidget(cbodes, 0, 5, 1, 1);

        lineEditCust = new QPlainTextEdit(groupBox);
        lineEditCust->setObjectName(QString::fromUtf8("lineEditCust"));
        lineEditCust->setMaximumSize(QSize(16777215, 51));

        gridLayout->addWidget(lineEditCust, 1, 3, 2, 1);


        verticalLayout->addWidget(groupBox);

        pushButtonAdd = new QPushButton(Voucher);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial Black"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        pushButtonAdd->setFont(font);

        verticalLayout->addWidget(pushButtonAdd);

        tableView = new QTableView(Voucher);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        frame = new QFrame(Voucher);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 1, -1, 1);
        horizontalSpacer = new QSpacerItem(481, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);

        lineEditTotal = new QLineEdit(frame);
        lineEditTotal->setObjectName(QString::fromUtf8("lineEditTotal"));
        lineEditTotal->setMaximumSize(QSize(160, 16777215));
        lineEditTotal->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditTotal);


        verticalLayout->addWidget(frame);

        frame_2 = new QFrame(Voucher);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(550, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMaximumSize(QSize(77, 16777215));

        horizontalLayout_3->addWidget(pushButton_2);


        verticalLayout->addWidget(frame_2);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(cboLoan);
        label->setBuddy(dateEdit);
        label_4->setBuddy(cboDC);
        label_6->setBuddy(lineEditNo);
        label_3->setBuddy(lineEditAmount);
#endif // QT_NO_SHORTCUT

        retranslateUi(Voucher);
        QObject::connect(pushButtonAdd, SIGNAL(clicked()), Voucher, SLOT(addVoucher()));
        QObject::connect(cboLoan, SIGNAL(currentIndexChanged(int)), Voucher, SLOT(showDetail()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Voucher, SLOT(reject()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Voucher, SLOT(save()));

        QMetaObject::connectSlotsByName(Voucher);
    } // setupUi

    void retranslateUi(QDialog *Voucher)
    {
        Voucher->setWindowTitle(QApplication::translate("Voucher", "Add NewVoucher", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Voucher", "Add Details", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Voucher", "Voucher No.", 0, QApplication::UnicodeUTF8));
        lineEditID->setStyleSheet(QApplication::translate("Voucher", "background-color: rgb(226, 226, 226);\n"
"color: rgb(236, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Voucher", "Loan No.    ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Voucher", "Description.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Voucher", "Date", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Voucher", "Customer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Voucher", "Debit / Credit", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("Voucher", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Voucher", "Chq No./ Rcpt .No.", 0, QApplication::UnicodeUTF8));
        cboDC->clear();
        cboDC->insertItems(0, QStringList()
         << QApplication::translate("Voucher", "Credit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "Debit", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("Voucher", "Amount", 0, QApplication::UnicodeUTF8));
        cbodes->clear();
        cbodes->insertItems(0, QStringList()
         << QApplication::translate("Voucher", "CASH RECD.", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "CHEQUE RECD.", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "CHEQUE BOUNCE CHRG.", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "CHEQUE BOUNCE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "CHEQUE GIVEN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "CASH GIVEN", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "DEALER PAYMENT", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "REPOSSESSION CHARGES", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "PENALTY", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Voucher", "PENALTY RECD.", 0, QApplication::UnicodeUTF8)
        );
        lineEditCust->setStyleSheet(QApplication::translate("Voucher", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("Voucher", "+ Add Voucher ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Voucher", "Total Amount", 0, QApplication::UnicodeUTF8));
        lineEditTotal->setStyleSheet(QApplication::translate("Voucher", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Voucher", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Voucher", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Voucher);
    } // retranslateUi

};

namespace Ui {
    class Voucher: public Ui_Voucher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOUCHER_H
