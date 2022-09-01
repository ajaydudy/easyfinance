/********************************************************************************
** Form generated from reading ui file 'loandetail.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOANDETAIL_H
#define UI_LOANDETAIL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoanDetail
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *LoanDetail)
    {
        if (LoanDetail->objectName().isEmpty())
            LoanDetail->setObjectName(QString::fromUtf8("LoanDetail"));
        LoanDetail->resize(280, 112);
        LoanDetail->setMaximumSize(QSize(280, 112));
        verticalLayout = new QVBoxLayout(LoanDetail);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(LoanDetail);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(225, 19));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(LoanDetail);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(label_4);

        label = new QLabel(LoanDetail);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(261, 19));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(LoanDetail);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(label_2);


        retranslateUi(LoanDetail);

        QMetaObject::connectSlotsByName(LoanDetail);
    } // setupUi

    void retranslateUi(QDialog *LoanDetail)
    {
        LoanDetail->setWindowTitle(QApplication::translate("LoanDetail", "Dialog", 0, QApplication::UnicodeUTF8));
        LoanDetail->setStyleSheet(QApplication::translate("LoanDetail", "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(221, 221, 221, 255), stop:1 rgba(255, 255, 255, 255));", 0, QApplication::UnicodeUTF8));
        label_3->setStyleSheet(QApplication::translate("LoanDetail", "background-color: transparent;", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LoanDetail", "Customer No:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        label->setStyleSheet(QApplication::translate("LoanDetail", "background-color: transparent;", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoanDetail", "Customer Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        Q_UNUSED(LoanDetail);
    } // retranslateUi

};

namespace Ui {
    class LoanDetail: public Ui_LoanDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOANDETAIL_H
