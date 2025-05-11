#include "chosemap.h"
#include"game.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow w;
    chosemap chosemap;
    chosemap.show();
    return a.exec();
}
