/********************************************************************************
** Form generated from reading ui file 'schedule.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SCHEDULE_H
#define UI_SCHEDULE_H

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
#include <QtGui/QTableView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Schedule
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QFrame *frame;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditTotP;
    QLineEdit *lineEditTotI;
    QLabel *label_4;
    QLineEdit *lineEditGtot;
    QPushButton *pushButton;

    void setupUi(QDialog *Schedule)
    {
        if (Schedule->objectName().isEmpty())
            Schedule->setObjectName(QString::fromUtf8("Schedule"));
        Schedule->resize(516, 681);
        Schedule->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(Schedule);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableView = new QTableView(Schedule);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableView->setAlternatingRowColors(true);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tableView);

        frame = new QFrame(Schedule);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEditTotP = new QLineEdit(frame);
        lineEditTotP->setObjectName(QString::fromUtf8("lineEditTotP"));
        lineEditTotP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotP->setReadOnly(true);

        gridLayout->addWidget(lineEditTotP, 1, 1, 1, 1);

        lineEditTotI = new QLineEdit(frame);
        lineEditTotI->setObjectName(QString::fromUtf8("lineEditTotI"));
        lineEditTotI->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditTotI->setReadOnly(true);

        gridLayout->addWidget(lineEditTotI, 1, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEditGtot = new QLineEdit(frame);
        lineEditGtot->setObjectName(QString::fromUtf8("lineEditGtot"));
        lineEditGtot->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditGtot->setReadOnly(true);

        gridLayout->addWidget(lineEditGtot, 2, 1, 1, 2);


        verticalLayout->addWidget(frame);

        pushButton = new QPushButton(Schedule);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Schedule);
        QObject::connect(pushButton, SIGNAL(clicked()), Schedule, SLOT(reject()));

        QMetaObject::connectSlotsByName(Schedule);
    } // setupUi

    void retranslateUi(QDialog *Schedule)
    {
        Schedule->setWindowTitle(QApplication::translate("Schedule", "Repayment Schedule", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Schedule", "Principal", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Schedule", "Interest", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Schedule", "Total:", 0, QApplication::UnicodeUTF8));
        lineEditTotP->setStyleSheet(QApplication::translate("Schedule", "background-color: rgb(227, 227, 227);\n"
"color: rgb(255, 0, 0);", 0, QApplication::UnicodeUTF8));
        lineEditTotI->setStyleSheet(QApplication::translate("Schedule", "background-color: rgb(227, 227, 227);\n"
"color: rgb(255, 0, 0);", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Schedule", "Grand Total:", 0, QApplication::UnicodeUTF8));
        lineEditGtot->setStyleSheet(QApplication::translate("Schedule", "background-color: rgb(227, 227, 227);\n"
"color: rgb(255, 0, 0);", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Schedule", "Close", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Schedule);
    } // retranslateUi

};

namespace Ui {
    class Schedule: public Ui_Schedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEDULE_H
