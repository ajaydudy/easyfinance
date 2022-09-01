#ifndef MYAPP_H
#define MYAPP_H
#include <QApplication>

class MyApp : public QApplication
{
    Q_OBJECT

public:

    MyApp(int &argc, char **argv);
    ~MyApp();
// void ChkInstance();
private:

    void encrypt();
   // void ChkInstance();

private slots:

    void startquit();

};

#endif // MYAPP_H
