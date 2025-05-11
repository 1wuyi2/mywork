#include "chosemap.h"
#include "ui_chosemap.h"

chosemap::chosemap(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chosemap)
{
    ui->setupUi(this);
}

chosemap::~chosemap()
{
    delete ui;
}

