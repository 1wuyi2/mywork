#ifndef CHOSEMAP_H
#define CHOSEMAP_H
#include"game.h"
#include <QWidget>

namespace Ui {
class chosemap;
}

class chosemap : public QWidget
{
    Q_OBJECT

public:
    explicit chosemap(QWidget *parent = nullptr);
    ~chosemap();

private slots:
    void on_map_2_clicked();

    void on_map_3_clicked();

    void on_map_4_clicked();

private:
    Ui::chosemap *ui;
    MainWindow *m=new MainWindow;
};

#endif // CHOSEMAP_H
