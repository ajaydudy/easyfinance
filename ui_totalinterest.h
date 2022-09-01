/********************************************************************************
** Form generated from reading ui file 'totalinterest.ui'
**
** Created: Sat Mar 26 10:04:08 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_TOTALINTEREST_H
#define UI_TOTALINTEREST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QTableView>

QT_BEGIN_NAMESPACE

class Ui_TotalInterest
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;
    QFrame *frame;
    QFormLayout *formLayout;
    QLineEdit *lineEditTotal;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TotalInterest)
    {
        if (TotalInterest->objectName().isEmpty())
            TotalInterest->setObjectName(QString::fromUtf8("TotalInterest"));
        TotalInterest->resize(367, 682);
        gridLayout = new QGridLayout(TotalInterest);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(TotalInterest);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);

        frame = new QFrame(TotalInterest);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        lineEditTotal = new QLineEdit(frame);
        lineEditTotal->setObjectName(QString::fromUtf8("lineEditTotal"));
        lineEditTotal->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        lineEditTotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotal->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditTotal);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        gridLayout->addWidget(frame, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(TotalInterest);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(TotalInterest);
        QObject::connect(buttonBox, SIGNAL(accepted()), TotalInterest, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TotalInterest, SLOT(reject()));

        QMetaObject::connectSlotsByName(TotalInterest);
    } // setupUi

    void retranslateUi(QDialog *TotalInterest)
    {
        TotalInterest->setWindowTitle(QApplication::translate("TotalInterest", "Total Interest Earned", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TotalInterest", "Total Interest Earned upto today:", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(TotalInterest);
    } // retranslateUi

};

namespace Ui {
    class TotalInterest: public Ui_TotalInterest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOTALINTEREST_H
