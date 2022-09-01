/********************************************************************************
** Form generated from reading ui file 'dealerledger.ui'
**
** Created: Fri Mar 25 17:44:10 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEALERLEDGER_H
#define UI_DEALERLEDGER_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DealerLedger
{
public:
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *DealerLedger)
    {
        if (DealerLedger->objectName().isEmpty())
            DealerLedger->setObjectName(QString::fromUtf8("DealerLedger"));
        DealerLedger->resize(401, 108);
        gridLayout = new QGridLayout(DealerLedger);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DealerLedger);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color:transparent;"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(DealerLedger);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dateEdit = new QDateEdit(DealerLedger);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 2, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(218, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 2);

        pushButton_3 = new QPushButton(DealerLedger);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 1);

        pushButton_2 = new QPushButton(DealerLedger);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 3, 1, 1);

        comboBox = new QComboBox(DealerLedger);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEditable(true);

        gridLayout->addWidget(comboBox, 0, 1, 1, 3);

#ifndef QT_NO_SHORTCUT
        label_2->setBuddy(dateEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(comboBox, dateEdit);
        QWidget::setTabOrder(dateEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(DealerLedger);

        QMetaObject::connectSlotsByName(DealerLedger);
    } // setupUi

    void retranslateUi(QDialog *DealerLedger)
    {
        DealerLedger->setWindowTitle(QApplication::translate("DealerLedger", "Dealer Ledger", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DealerLedger", "Dealer Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DealerLedger", "As On Date", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("DealerLedger", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("DealerLedger", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DealerLedger", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(DealerLedger);
    } // retranslateUi

};

namespace Ui {
    class DealerLedger: public Ui_DealerLedger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALERLEDGER_H
