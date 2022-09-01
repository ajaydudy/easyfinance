/********************************************************************************
** Form generated from reading ui file 'about.ui'
**
** Created: Wed Apr 13 16:40:29 2011
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QFrame *frame;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(440, 279);
        About->setMinimumSize(QSize(440, 279));
        About->setMaximumSize(QSize(440, 279));
        frame = new QFrame(About);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1, 0, 439, 231));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 98, 281, 131));
        label_6->setFrameShape(QFrame::NoFrame);
        label_6->setFrameShadow(QFrame::Plain);
        label_6->setWordWrap(true);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(149, 15, 261, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(true);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStyleStrategy(QFont::PreferAntialias);
        label_5->setFont(font);
        label_5->setWordWrap(true);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 60, 291, 31));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(384, 32, 31, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(149, 14, 231, 40));
        label_4->setFont(font);
        label_4->setFrameShape(QFrame::NoFrame);
        label_4->setWordWrap(true);
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 91, 91));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/Mashup-4.2/Mashup/apps/invest-applet.png")));
        label_7->setScaledContents(true);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(142, 83, 211, 16));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 85, 255);"));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 130, 71, 81));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/logo128.png")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(frame);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(90, 116, 21, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(6);
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("background-color:transparent;"));
        pushButton = new QPushButton(About);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(354, 240, 81, 31));

        retranslateUi(About);
        QObject::connect(pushButton, SIGNAL(clicked()), About, SLOT(reject()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0, QApplication::UnicodeUTF8));
        frame->setStyleSheet(QApplication::translate("About", "background-color: rgb(255, 255, 255);", 0, QApplication::UnicodeUTF8));
        label_6->setStyleSheet(QApplication::translate("About", "background color:opaque;", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("About", "Warning: This computer program is protected by copyright law and international treaties. Unauthorized reproduction or distribution of this program, or any portion of it, may result in severe civil and criminal penalties, and will be prosecuted to the maximum extent possible under the law.", 0, QApplication::UnicodeUTF8));
        label_5->setStyleSheet(QApplication::translate("About", "background-color:transparent;", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("About", "Easy Finance", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("About", "Copyright 2009 Gloria Systems. All rights reserved.", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("About", "1.0", 0, QApplication::UnicodeUTF8));
        label_4->setStyleSheet(QApplication::translate("About", "color: rgb(255, 231, 44);\n"
"background-color:transparent;", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("About", "Easy Finance", 0, QApplication::UnicodeUTF8));
        label_7->setText(QString());
        label->setText(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.21053pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"www.gloria.co.in\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://www.dudtytech.com</span></a></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QString());
        label_9->setText(QApplication::translate("About", "TM", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("About", "OK", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(About);
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
