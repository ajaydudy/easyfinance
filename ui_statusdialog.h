/********************************************************************************
** Form generated from reading ui file 'statusdialog.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STATUSDIALOG_H
#define UI_STATUSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_StatusDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cboGr;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonAll;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *StatusDialog)
    {
        if (StatusDialog->objectName().isEmpty())
            StatusDialog->setObjectName(QString::fromUtf8("StatusDialog"));
        StatusDialog->resize(265, 120);
        gridLayout = new QGridLayout(StatusDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(StatusDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        cboGr = new QComboBox(StatusDialog);
        cboGr->setObjectName(QString::fromUtf8("cboGr"));
        cboGr->setEnabled(false);

        gridLayout->addWidget(cboGr, 1, 1, 1, 3);

        label_2 = new QLabel(StatusDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        dateEdit = new QDateEdit(StatusDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(dateEdit, 2, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(82, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 0, 1, 2);

        pushButton_3 = new QPushButton(StatusDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 2, 1, 1);

        pushButton_2 = new QPushButton(StatusDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 3, 1, 1);

        frame = new QFrame(StatusDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setMargin(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonAll = new QRadioButton(frame);
        radioButtonAll->setObjectName(QString::fromUtf8("radioButtonAll"));
        radioButtonAll->setChecked(true);

        horizontalLayout->addWidget(radioButtonAll);

        radioButton_2 = new QRadioButton(frame);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);


        gridLayout->addWidget(frame, 0, 0, 1, 4);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(cboGr);
        label_2->setBuddy(dateEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cboGr, dateEdit);
        QWidget::setTabOrder(dateEdit, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_2);

        retranslateUi(StatusDialog);
        QObject::connect(pushButton_3, SIGNAL(clicked()), StatusDialog, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), StatusDialog, SLOT(reject()));
        QObject::connect(radioButtonAll, SIGNAL(clicked()), StatusDialog, SLOT(enableDisable()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), StatusDialog, SLOT(enableDisable()));

        QMetaObject::connectSlotsByName(StatusDialog);
    } // setupUi

    void retranslateUi(QDialog *StatusDialog)
    {
        StatusDialog->setWindowTitle(QApplication::translate("StatusDialog", "Enter Values", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("StatusDialog", "Guarantor Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("StatusDialog", "As On Date", 0, QApplication::UnicodeUTF8));
        dateEdit->setDisplayFormat(QApplication::translate("StatusDialog", "dd/MM/yyyy", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("StatusDialog", "Ok", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("StatusDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        radioButtonAll->setText(QApplication::translate("StatusDialog", "All Guarantors", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("StatusDialog", "Select Guarantors ", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(StatusDialog);
    } // retranslateUi

};

namespace Ui {
    class StatusDialog: public Ui_StatusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUSDIALOG_H
