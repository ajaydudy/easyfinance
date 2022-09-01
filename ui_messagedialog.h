/********************************************************************************
** Form generated from reading ui file 'messagedialog.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_messageDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QDialog *messageDialog)
    {
        if (messageDialog->objectName().isEmpty())
            messageDialog->setObjectName(QString::fromUtf8("messageDialog"));
        messageDialog->setWindowModality(Qt::ApplicationModal);
        messageDialog->resize(213, 53);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messageDialog->sizePolicy().hasHeightForWidth());
        messageDialog->setSizePolicy(sizePolicy);
        messageDialog->setMaximumSize(QSize(378, 97));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        messageDialog->setFont(font);
        messageDialog->setModal(false);
        gridLayout = new QGridLayout(messageDialog);
        gridLayout->setSpacing(0);
        gridLayout->setMargin(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(messageDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(213, 53));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(26);
        label->setFont(font1);
        label->setAutoFillBackground(true);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setFrameShape(QFrame::Panel);
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/wait2.png")));
        label->setScaledContents(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(messageDialog);

        QMetaObject::connectSlotsByName(messageDialog);
    } // setupUi

    void retranslateUi(QDialog *messageDialog)
    {
        messageDialog->setWindowTitle(QApplication::translate("messageDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        Q_UNUSED(messageDialog);
    } // retranslateUi

};

namespace Ui {
    class messageDialog: public Ui_messageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
