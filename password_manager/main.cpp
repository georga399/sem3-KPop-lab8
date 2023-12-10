#include "mainwindow.h"
#include "authwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    AuthWidget authW;
    authW.show();
    return a.exec();
}
