/********************************************************************************
** Form generated from reading ui file 'ledgerinput.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LEDGERINPUT_H
#define UI_LEDGERINPUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LedgerInput
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEditCustName;
    QComboBox *cboLoan;

    void setupUi(QDialog *LedgerInput)
    {
        if (LedgerInput->objectName().isEmpty())
            LedgerInput->setObjectName(QString::fromUtf8("LedgerInput"));
        LedgerInput->resize(420, 120);
        gridLayout = new QGridLayout(LedgerInput);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(LedgerInput);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label = new QLabel(LedgerInput);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(LedgerInput);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dateEdit = new QDateEdit(LedgerInput);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 2, 1, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(93, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 4);

        pushButton_3 = new QPushButton(LedgerInput);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 4, 1, 1);

        pushButton_2 = new QPushButton(LedgerInput);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 5, 1, 1);

        lineEditCustName = new QLineEdit(LedgerInput);
        lineEditCustName->setObjectName(QString::fromUtf8("lineEditCustName"));
        lineEditCustName->setReadOnly(false);

        gridLayout->addWidget(lineEditCustName, 0, 1, 1, 5);

        cboLoan = new QComboBox(LedgerInput);
        cboLoan->setObjectName(QString::fromUtf8("cboLoan"));

        gridLayout->addWidget(cboLoan, 1, 1, 1, 5);

        QWidget::setTabOrder(lineEditCustName, cboLoan);
        QWidget::setTabOrder(cboLoan, dateEdit);
        QWidget::setTabOrder(dateEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(LedgerInput);
        QObject::connect(pushButton_3, SIGNAL(clicked()), LedgerInput, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), LedgerInput, SLOT(reject()));
        QObject::connect(lineEditCustName, SIGNAL(editingFinished()), LedgerInput, SLOT(refreshLoanNo()));

        QMetaObject::connectSlotsByName(LedgerInput);
    } // setupUi

    void retranslateUi(QDialog *LedgerInput)
    {
        LedgerInput->setWindowTitle(QApplication::translate("LedgerInput", "Select Loan", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LedgerInput", "Customer Name", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LedgerInput", "Loan No", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LedgerInput", "As On Date", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("LedgerInput", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("LedgerInput", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LedgerInput", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LedgerInput);
    } // retranslateUi

};

namespace Ui {
    class LedgerInput: public Ui_LedgerInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEDGERINPUT_H
