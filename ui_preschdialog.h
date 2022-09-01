/********************************************************************************
** Form generated from reading ui file 'preschdialog.ui'
**
** Created: Fri Mar 25 17:44:09 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PRESCHDIALOG_H
#define UI_PRESCHDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PreSchDialog
{
public:

    void setupUi(QDialog *PreSchDialog)
    {
        if (PreSchDialog->objectName().isEmpty())
            PreSchDialog->setObjectName(QString::fromUtf8("PreSchDialog"));
        PreSchDialog->resize(400, 300);

        retranslateUi(PreSchDialog);

        QMetaObject::connectSlotsByName(PreSchDialog);
    } // setupUi

    void retranslateUi(QDialog *PreSchDialog)
    {
        PreSchDialog->setWindowTitle(QApplication::translate("PreSchDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(PreSchDialog);
    } // retranslateUi

};

namespace Ui {
    class PreSchDialog: public Ui_PreSchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRESCHDIALOG_H
