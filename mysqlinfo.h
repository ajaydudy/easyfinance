#ifndef MYSQLINFO_H
#define MYSQLINFO_H

#include <QDialog>
#include <QString>

namespace Ui {
    class MysqlInfo;
}

class MysqlInfo : public QDialog
{
    Q_OBJECT

public:
    explicit MysqlInfo(QWidget *parent = 0);
    ~MysqlInfo();
    QString HostName;
    QString DatabaseName;
    QString User;
    QString Pasword;
    QString Port;

private:
    Ui::MysqlInfo *ui;
    void accept();
};

#endif // MYSQLINFO_H
