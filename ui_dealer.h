/********************************************************************************
** Form generated from reading ui file 'dealer.ui'
**
** Created: Fri Mar 25 17:44:10 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_DEALER_H
#define UI_DEALER_H

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
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dealer
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEditID;
    QLabel *label_6;
    QLineEdit *lineEditName;
    QPlainTextEdit *txtAddress;
    QLabel *label_4;
    QLineEdit *lineEditPhone;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dealer)
    {
        if (Dealer->objectName().isEmpty())
            Dealer->setObjectName(QString::fromUtf8("Dealer"));
        Dealer->resize(388, 274);
        gridLayout_2 = new QGridLayout(Dealer);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Dealer);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));
        lineEditID->setDragEnabled(false);
        lineEditID->setReadOnly(true);

        gridLayout->addWidget(lineEditID, 0, 1, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 1, 1, 2);

        txtAddress = new QPlainTextEdit(groupBox);
        txtAddress->setObjectName(QString::fromUtf8("txtAddress"));
        txtAddress->setMinimumSize(QSize(0, 84));
        txtAddress->setFrameShape(QFrame::Box);
        txtAddress->setTabChangesFocus(true);
        txtAddress->setBackgroundVisible(false);
        txtAddress->setCenterOnScroll(false);

        gridLayout->addWidget(txtAddress, 2, 1, 1, 2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEditPhone = new QLineEdit(groupBox);
        lineEditPhone->setObjectName(QString::fromUtf8("lineEditPhone"));

        gridLayout->addWidget(lineEditPhone, 4, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        lineEditEmail = new QLineEdit(groupBox);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        gridLayout->addWidget(lineEditEmail, 5, 1, 1, 2);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(201, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Dealer);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Dealer);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_7->setBuddy(lineEditID);
        label_6->setBuddy(lineEditName);
        label_4->setBuddy(lineEditPhone);
        label_3->setBuddy(lineEditEmail);
        label_5->setBuddy(txtAddress);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dealer);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Dealer, SLOT(reject()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Dealer, SLOT(Save()));

        QMetaObject::connectSlotsByName(Dealer);
    } // setupUi

    void retranslateUi(QDialog *Dealer)
    {
        Dealer->setWindowTitle(QApplication::translate("Dealer", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_7->setText(QApplication::translate("Dealer", "Dealer No.", 0, QApplication::UnicodeUTF8));
        lineEditID->setStyleSheet(QApplication::translate("Dealer", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dealer", "Name       *", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dealer", "Phone No.  *", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dealer", "Email", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dealer", "Address    *", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dealer", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dealer", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Dealer);
    } // retranslateUi

};

namespace Ui {
    class Dealer: public Ui_Dealer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALER_H
