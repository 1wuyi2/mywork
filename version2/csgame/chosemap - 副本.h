#ifndef CHOSEMAP_H
#define CHOSEMAP_H

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

private:
    Ui::chosemap *ui;
};

#endif // CHOSEMAP_H
