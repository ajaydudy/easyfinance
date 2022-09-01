/********************************************************************************
** Form generated from reading ui file 'gaurantor.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_GAURANTOR_H
#define UI_GAURANTOR_H

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

class Ui_Gaurantor
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLineEdit *lineEditID;
    QLabel *label_6;
    QLineEdit *lineEditName;
    QLabel *label_5;
    QPlainTextEdit *txtAddress;
    QLabel *label_4;
    QLineEdit *lineEditPhone;
    QLabel *label_3;
    QLineEdit *lineEditEmail;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Gaurantor)
    {
        if (Gaurantor->objectName().isEmpty())
            Gaurantor->setObjectName(QString::fromUtf8("Gaurantor"));
        Gaurantor->resize(386, 275);
        Gaurantor->setSizeGripEnabled(true);
        gridLayout_2 = new QGridLayout(Gaurantor);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(Gaurantor);
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

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

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

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEditPhone = new QLineEdit(groupBox);
        lineEditPhone->setObjectName(QString::fromUtf8("lineEditPhone"));

        gridLayout->addWidget(lineEditPhone, 3, 1, 1, 2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEditEmail = new QLineEdit(groupBox);
        lineEditEmail->setObjectName(QString::fromUtf8("lineEditEmail"));

        gridLayout->addWidget(lineEditEmail, 4, 1, 1, 2);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(199, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(Gaurantor);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(Gaurantor);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 2, 1, 1);

#ifndef QT_NO_SHORTCUT
        label_7->setBuddy(lineEditID);
        label_6->setBuddy(lineEditName);
        label_5->setBuddy(txtAddress);
        label_4->setBuddy(lineEditPhone);
        label_3->setBuddy(lineEditEmail);
#endif // QT_NO_SHORTCUT

        retranslateUi(Gaurantor);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Gaurantor, SLOT(Save()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Gaurantor, SLOT(reject()));

        QMetaObject::connectSlotsByName(Gaurantor);
    } // setupUi

    void retranslateUi(QDialog *Gaurantor)
    {
        Gaurantor->setWindowTitle(QApplication::translate("Gaurantor", "Enter new Guarantor", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_7->setText(QApplication::translate("Gaurantor", "Guarantor No.", 0, QApplication::UnicodeUTF8));
        lineEditID->setStyleSheet(QApplication::translate("Gaurantor", "background-color: rgb(226, 226, 226);\n"
"color: rgb(234, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Gaurantor", "Name       *", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Gaurantor", "Address    *", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Gaurantor", "Phone No.  *", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Gaurantor", "Email", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Gaurantor", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Gaurantor", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Gaurantor);
    } // retranslateUi

};

namespace Ui {
    class Gaurantor: public Ui_Gaurantor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAURANTOR_H
