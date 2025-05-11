#include "chosemap.h"
#include "ui_chosemap.h"
#include"game.h"
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


void chosemap::on_map_2_clicked() {
    this->close();

    // 创建新窗口并设置父对象
    m = new MainWindow(this);
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/dust.jpg);");
    m->show();

}

void chosemap::on_map_3_clicked()
{
    this->close();
    m=new MainWindow;
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/mirragemap.jpg);");
    m->showFullScreen();
}


void chosemap::on_map_4_clicked()
{
    this->close();
    m=new MainWindow;
    m->setAttribute(Qt::WA_DeleteOnClose);  // 自动释放内存
    m->centralWidget()->setStyleSheet("background-image: url(:/images/ancientmap.jpg);");
    m->showFullScreen();
}

// #include "chosemap.h"
// #include "ui_chosemap.h"
// #include "game.h"

// chosemap::chosemap(QWidget *parent)
//     : QWidget(parent),
//     ui(new Ui::chosemap)
// {
//     ui->setupUi(this);
//     setStyleSheet("background-image: url(:/images/map_select_bg.jpg);"); // 设置选择界面背景
// }

// void chosemap::on_map_2_clicked() {
//     this->close();
//     auto* game = new MainWindow(nullptr, ":/images/dust.jpg");
//     game->showFullScreen();
// }

// void chosemap::on_map_3_clicked() {
//     this->close();
//     auto* game = new MainWindow(nullptr, ":/images/mirragemap.jpg");
//     game->showFullScreen();
// }

// void chosemap::on_map_4_clicked() {
//     this->close();
//     auto* game = new MainWindow(nullptr, ":/images/ancientmap.jpg");
//     game->showFullScreen();
// }

// chosemap::~chosemap() {
//     delete ui;
// }
