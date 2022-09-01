/********************************************************************************
** Form generated from reading ui file 'emitool.ui'
**
** Created: Fri Mar 25 17:44:10 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_EMITOOL_H
#define UI_EMITOOL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_EmiTool
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLineEdit *lineEditEMI;
    QLabel *label_14;
    QLineEdit *lineEditReducing;
    QLabel *label_15;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditCost;
    QLabel *label_6;
    QLineEdit *lineEditHire;
    QLabel *label_7;
    QLineEdit *lineEditAmount;
    QLineEdit *lineEditIR;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *lineEditNoEMI;
    QPushButton *pushButton_2;

    void setupUi(QDialog *EmiTool)
    {
        if (EmiTool->objectName().isEmpty())
            EmiTool->setObjectName(QString::fromUtf8("EmiTool"));
        EmiTool->resize(317, 310);
        gridLayout = new QGridLayout(EmiTool);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(EmiTool);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        groupBox_3 = new QGroupBox(EmiTool);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        lineEditEMI = new QLineEdit(groupBox_3);
        lineEditEMI->setObjectName(QString::fromUtf8("lineEditEMI"));
        lineEditEMI->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 226, 226);"));
        lineEditEMI->setReadOnly(true);

        gridLayout_3->addWidget(lineEditEMI, 1, 1, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 4, 0, 1, 1);

        lineEditReducing = new QLineEdit(groupBox_3);
        lineEditReducing->setObjectName(QString::fromUtf8("lineEditReducing"));
        lineEditReducing->setReadOnly(true);

        gridLayout_3->addWidget(lineEditReducing, 4, 1, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 4, 2, 1, 1);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 2);

        groupBox_2 = new QGroupBox(EmiTool);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lineEditCost = new QLineEdit(groupBox_2);
        lineEditCost->setObjectName(QString::fromUtf8("lineEditCost"));

        gridLayout_2->addWidget(lineEditCost, 0, 1, 1, 1);

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

        lineEditIR = new QLineEdit(groupBox_2);
        lineEditIR->setObjectName(QString::fromUtf8("lineEditIR"));
        lineEditIR->setStyleSheet(QString::fromUtf8(""));
        lineEditIR->setReadOnly(false);

        gridLayout_2->addWidget(lineEditIR, 3, 1, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 3, 0, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 3, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        lineEditNoEMI = new QLineEdit(groupBox_2);
        lineEditNoEMI->setObjectName(QString::fromUtf8("lineEditNoEMI"));

        gridLayout_2->addWidget(lineEditNoEMI, 4, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 2);

        pushButton_2 = new QPushButton(EmiTool);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setIconSize(QSize(32, 32));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label_10->setBuddy(lineEditEMI);
        label_14->setBuddy(lineEditReducing);
        label_5->setBuddy(lineEditCost);
        label_6->setBuddy(lineEditHire);
        label_7->setBuddy(lineEditAmount);
        label_13->setBuddy(lineEditIR);
        label_11->setBuddy(lineEditNoEMI);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(lineEditCost, lineEditHire);
        QWidget::setTabOrder(lineEditHire, lineEditAmount);
        QWidget::setTabOrder(lineEditAmount, lineEditIR);
        QWidget::setTabOrder(lineEditIR, lineEditNoEMI);
        QWidget::setTabOrder(lineEditNoEMI, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton);
        QWidget::setTabOrder(pushButton, lineEditEMI);
        QWidget::setTabOrder(lineEditEMI, lineEditReducing);

        retranslateUi(EmiTool);
        QObject::connect(pushButton_2, SIGNAL(clicked()), EmiTool, SLOT(calculateEmi()));
        QObject::connect(pushButton, SIGNAL(clicked()), EmiTool, SLOT(reject()));

        QMetaObject::connectSlotsByName(EmiTool);
    } // setupUi

    void retranslateUi(QDialog *EmiTool)
    {
        EmiTool->setWindowTitle(QApplication::translate("EmiTool", "EMI Calculator", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("EmiTool", "Close", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_10->setText(QApplication::translate("EmiTool", "EMI Amount      *", 0, QApplication::UnicodeUTF8));
        lineEditEMI->setText(QString());
        label_14->setText(QApplication::translate("EmiTool", "Reducing Rate %", 0, QApplication::UnicodeUTF8));
        lineEditReducing->setStyleSheet(QApplication::translate("EmiTool", "background-color: rgb(226, 226, 226);", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("EmiTool", "%", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_5->setText(QApplication::translate("EmiTool", "Total Cost             *", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EmiTool", "Initial Hire             *", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EmiTool", "Amount Financed *", 0, QApplication::UnicodeUTF8));
        lineEditAmount->setText(QString());
        label_13->setText(QApplication::translate("EmiTool", "Flat Rate %         *", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("EmiTool", "%   ", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EmiTool", "No of EMI's          *", 0, QApplication::UnicodeUTF8));
        lineEditNoEMI->setText(QString());
        pushButton_2->setText(QApplication::translate("EmiTool", "Calculate EMI", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(EmiTool);
    } // retranslateUi

};

namespace Ui {
    class EmiTool: public Ui_EmiTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMITOOL_H
