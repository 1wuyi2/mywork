#include "win.h"
#include "ui_win.h"

win::win(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win)
{
    ui->setupUi(this);
      this->show();
}

win::~win()
{
    delete ui;
}
