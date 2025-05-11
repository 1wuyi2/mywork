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
    static int x,y;

private slots:
    void on_map_2_clicked();

    void on_map_3_clicked();

    void on_map_4_clicked();

    void on_Wbutton1_clicked();

    void on_Wbutton2_clicked();

    void on_Wbutton3_clicked();

    void on_Wbutton4_clicked();

    void on_Wbutton5_clicked();

    void on_Wbutton6_clicked();

    void on_Wbutton7_clicked();

    void on_Wbutton8_clicked();

    void on_Wbutton9_clicked();

    void on_Wbutton10_clicked();

private:
    Ui::chosemap *ui;
    MainWindow *m=new MainWindow;
};

#endif // CHOSEMAP_H
