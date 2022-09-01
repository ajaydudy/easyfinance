#include "messagewindow.h"
#include "ui_messagewindow.h"

MessageWindow::MessageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageWindow)
{
    ui->setupUi(this);

}

MessageWindow::~MessageWindow()
{
    delete ui;
}
