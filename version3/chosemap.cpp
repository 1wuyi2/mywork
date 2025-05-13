#include "chosemap.h"
#include "ui_chosemap.h"
#include"game.h"
#include"floor.h"
int chosemap::y=1;
chosemap::chosemap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chosemap)
{
    ui->setupUi(this);
    setStyleSheet("QWidget#chosemap{ border-image: url(:/.jpg); }");

}
chosemap::~chosemap()
{
    delete ui;
}
int chosemap::x=0;
void chosemap::on_map_2_clicked() {
    this->close();
         x=1;
    // 创建新窗口并设置父对象
    m = new MainWindow(this);
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/dust.jpg);");

    m->show();
    m->startgame();
}

void chosemap::on_map_3_clicked()
{
    this->close();
    x=2;
    m=new MainWindow;
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/mirragemap.jpg);");
    m->showFullScreen();
     m->startgame();
}
void chosemap::on_map_4_clicked()
{
    this->close();
    x=3;
    m=new MainWindow;
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/ancientmap.jpg);");
    m->showFullScreen();
     m->startgame();
}
void chosemap::on_Wbutton1_clicked()
{
    chosemap::y=1;
}
void chosemap::on_Wbutton2_clicked()
{
    y=2;
}
void chosemap::on_Wbutton3_clicked()
{
    y=3;
}
void chosemap::on_Wbutton4_clicked()
{
    y=4;
}
void chosemap::on_Wbutton5_clicked()
{
    y=5;
}
void chosemap::on_Wbutton6_clicked()
{
    y=6;
}
void chosemap::on_Wbutton7_clicked()
{
    y=7;
}
void chosemap::on_Wbutton8_clicked()
{
    y=8;
}
void chosemap::on_Wbutton9_clicked()
{
    y=9;
}
void chosemap::on_Wbutton10_clicked()
{
    y=10;
}

