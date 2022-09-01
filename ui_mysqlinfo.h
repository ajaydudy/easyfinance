/********************************************************************************
** Form generated from reading ui file 'mysqlinfo.ui'
**
** Created: Fri Mar 25 17:44:10 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MYSQLINFO_H
#define UI_MYSQLINFO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_MysqlInfo
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditHost;
    QLabel *label_2;
    QLineEdit *lineEditDatabase;
    QLabel *label_4;
    QLineEdit *lineEditUser;
    QLabel *label_3;
    QLineEdit *lineEditPassword;
    QLabel *label_5;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEditPort;
    QLabel *label_6;

    void setupUi(QDialog *MysqlInfo)
    {
        if (MysqlInfo->objectName().isEmpty())
            MysqlInfo->setObjectName(QString::fromUtf8("MysqlInfo"));
        MysqlInfo->resize(331, 215);
        formLayout = new QFormLayout(MysqlInfo);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(MysqlInfo);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        lineEditHost = new QLineEdit(MysqlInfo);
        lineEditHost->setObjectName(QString::fromUtf8("lineEditHost"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditHost);

        label_2 = new QLabel(MysqlInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEditDatabase = new QLineEdit(MysqlInfo);
        lineEditDatabase->setObjectName(QString::fromUtf8("lineEditDatabase"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditDatabase);

        label_4 = new QLabel(MysqlInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        lineEditUser = new QLineEdit(MysqlInfo);
        lineEditUser->setObjectName(QString::fromUtf8("lineEditUser"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditUser);

        label_3 = new QLabel(MysqlInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEditPassword = new QLineEdit(MysqlInfo);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditPassword);

        label_5 = new QLabel(MysqlInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        buttonBox = new QDialogButtonBox(MysqlInfo);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(6, QFormLayout::SpanningRole, buttonBox);

        lineEditPort = new QLineEdit(MysqlInfo);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditPort);

        label_6 = new QLabel(MysqlInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_6->setFont(font);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label_6);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEditHost);
        label_2->setBuddy(lineEditDatabase);
        label_4->setBuddy(lineEditUser);
        label_3->setBuddy(lineEditPassword);
        label_5->setBuddy(lineEditPort);
#endif // QT_NO_SHORTCUT

        retranslateUi(MysqlInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), MysqlInfo, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MysqlInfo, SLOT(reject()));

        QMetaObject::connectSlotsByName(MysqlInfo);
    } // setupUi

    void retranslateUi(QDialog *MysqlInfo)
    {
        MysqlInfo->setWindowTitle(QApplication::translate("MysqlInfo", "MYSQL database information", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MysqlInfo", "Host Name *", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MysqlInfo", "Database Name *", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MysqlInfo", "User Name *", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MysqlInfo", "Password *", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MysqlInfo", "Port", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MysqlInfo", "Please enter your MYSQL database information.", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MysqlInfo);
    } // retranslateUi

};

namespace Ui {
    class MysqlInfo: public Ui_MysqlInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQLINFO_H
