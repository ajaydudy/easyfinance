/********************************************************************************
** Form generated from reading ui file 'login.ui'
**
** Created: Tue Apr 26 16:49:28 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout_2;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QLineEdit *lineEditName;
    QLabel *label_4;
    QLineEdit *lineEditPass;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(333, 444);
        gridLayout_2 = new QGridLayout(Login);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new QFrame(Login);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(131, 131));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/apps/invest-applet.png")));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame, 0, 0, 1, 4);

        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 71));
        label->setMaximumSize(QSize(16777215, 71));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.497851, y1:0.551, x2:0.498, y2:0.227273, stop:0 rgba(0, 0, 0, 255), stop:0.363184 rgba(144, 144, 144, 255));\n"
"font: 15pt \"Segoe UI\";\n"
"font:Bold;\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer_2, 2, 0, 1, 1);

        label_5 = new QLabel(Login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        gridLayout_2->addWidget(label_5, 3, 0, 1, 4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_2->addItem(verticalSpacer, 4, 0, 1, 1);

        label_3 = new QLabel(Login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        gridLayout_2->addWidget(label_3, 5, 0, 1, 2);

        lineEditName = new QLineEdit(Login);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lineEditName->setFont(font2);

        gridLayout_2->addWidget(lineEditName, 5, 2, 1, 2);

        label_4 = new QLabel(Login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 2);

        lineEditPass = new QLineEdit(Login);
        lineEditPass->setObjectName(QString::fromUtf8("lineEditPass"));
        QFont font3;
        font3.setPointSize(10);
        lineEditPass->setFont(font3);
        lineEditPass->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEditPass, 6, 2, 1, 2);

        horizontalSpacer_2 = new QSpacerItem(133, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 8, 0, 1, 1);

        pushButton_3 = new QPushButton(Login);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font2);

        gridLayout_2->addWidget(pushButton_3, 8, 2, 1, 1);

        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font2);

        gridLayout_2->addWidget(pushButton_2, 8, 3, 1, 1);


        retranslateUi(Login);
        QObject::connect(pushButton_3, SIGNAL(clicked()), Login, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Login, SLOT(reject()));

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        label->setText(QApplication::translate("Login", "Login To EasyFinance", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Login", "You must enter username and password to login to EasyFinance.", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Login", "User Name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Login", "Password", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Login", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Login", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Login);
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
