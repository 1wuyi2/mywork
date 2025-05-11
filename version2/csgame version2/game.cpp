#include "game.h"
#include"player.h"
#include<floor.h>
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // 初始化场景和视图
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    setCentralWidget(view);
    view->setSceneRect(0, 0, 800, 600); // 设置场景大小
    Floor *floor[5];
    for(int i=0, j=600,k=-450;i<5,j>0;i++,j-=90,k+=90)
    {
        floor[i] = new Floor(k,j);
    scene->addItem(floor[i]);
    }
    // 创建玩家
    player = new Player();
    scene->addItem(player);
    player->setPos(-450, 500); // 初始位置

    // 初始化游戏循环
    gametiming = new QTimer(this);
    connect(gametiming, &QTimer::timeout, [this]() {
        player->updateMovement();
    });
    gametiming->start(16); //16ms一次
}

MainWindow::~MainWindow() {
    delete scene;
}

// MainWindow 的 keyPressEvent
// mainwindow.cpp
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        player->presskey(0, true); // A
    } else if (event->key() == Qt::Key_D) {
        player->presskey(1, true); // D
    } else if (event->key() == Qt::Key_Space) {
        player->startJump();       // 空格触发跳跃
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        player->presskey(0, false);
    } else if (event->key() == Qt::Key_D) {
        player->presskey(1, false);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    QPointF vpos = event->pos(); // 此时得到的点击鼠标event的坐标为视图坐标
    QPointF spos = view->mapToScene(vpos.x(), vpos.y()); // 需要先将其转换为场景坐标，传到射击函数里才能正确计算子弹的方向
    player->shoot(spos);
}
