#include "chosemap.h"
#include"mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();
    chosemap chosemap;
    chosemap.show();
    return a.exec();
}
