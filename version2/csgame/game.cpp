#include "game.h"
#include"player.h"
#include<floor.h>
#include"c4.h"
#include "win.h"
#include "lose.h"
#include <QRandomGenerator>//用于生成随机数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initialize();

}
void MainWindow::initialize()
{
     m_ctWinsound.setSource(QUrl("qrc:/sounds/ctwin_.WAV"));
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);  // 初始化场景和视图
    setCentralWidget(view);
    view->setSceneRect(0, 0, 800, 600);// 设置场景大小
    player = new Player();
    scene->addItem(player);
    player->setPos(-460, 500); //初始化玩家的位置
    Floor* baseFloor = new Floor(-500,685,2000,30.0);
    scene->addItem(baseFloor);
    createFloors();
    gametiming = new QTimer(this);  //初始化游戏循环
    connect(gametiming, &QTimer::timeout, [this]() {
        player->updateDefusingState();
        player->updateMovement();  // 先更新物理状态
        player->updateAnimation(); // 再更新动画
        scene->update();           // 最后刷新场景
    });
    connect(player, &Player::playerDied, this, [this]{
        gameover(false);  // false表示玩家失败
        gametiming->stop();    // 停止游戏循环
    });
    gametiming->start(16); //16ms一次
    m_defuseProgressBar = new QProgressBar();
    m_defuseProgressBar->setRange(0, 100);
    m_defuseProgressBar->setFixedSize(200, 20);
    m_defuseProxy = scene->addWidget(m_defuseProgressBar);
    m_defuseProxy->setZValue(1000);  // 高于C4的999
    m_defuseProxy->setPos(-100, -25); // 初始位置

}
void MainWindow::startgame()
{
    startC4Scenario();
}
MainWindow::~MainWindow()
{
    delete scene;
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        player->presskey(0, true); //A左移
    } else if (event->key() == Qt::Key_D) {
        player->presskey(1, true); //D右移
    }
    if (event->key() == Qt::Key_Space) {
        player->presskey(2,true)    ;  // 空格触发跳跃
    }
    if (event->key() == Qt::Key_Control) {
        player->presskey(3, true);
    }
    if(event->key() == Qt::Key_E) {
        player->setEKeyHeld(true);
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A) {
        player->presskey(0, false);
    } else if (event->key() == Qt::Key_D) {
        player->presskey(1, false);
    }if (event->key() == Qt::Key_Space) {
        player->presskey(2, false); // 释放空格键
    }
    if (event->key() == Qt::Key_Control) {
        player->presskey(3, false);
    }
    if(event->key() == Qt::Key_E) {
        player->setEKeyHeld(false);
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    QPointF vpos = event->pos(); // 此时得到的点击鼠标event的坐标为视图坐标
    QPointF spos = view->mapToScene(vpos.x(), vpos.y()); // 需要先将其转换为场景坐标，传到射击函数里才能正确计算子弹的方向
    player->shoot(spos);
}
void MainWindow::startC4Scenario()
{
    QPointF spawnPos(0,500);
    foreach(QGraphicsItem *item, scene->items())
    {
        if(Floor *floor = dynamic_cast<Floor*>(item)) {
            if(floor->getscenetopy() < spawnPos.y()) {
                spawnPos = QPointF(floor->getx() + Floor::width - 50,floor->gettopy());
            }
        }
    }// 寻找最上方地板
    C4 *c4 = new C4(spawnPos);
    scene->addItem(c4);
    connect(c4, &C4::exploded, this, [this]{
        gameover(false);
    });//爆炸信号
    connect(c4, &C4::defused, this, [this]{
        gameover(true);
    });//拆除信号
    connect(c4, &C4::updateProgress, this, [this](float progress) {
        m_defuseProgressBar->setValue(static_cast<int>(progress));
        if(progress > 0 && progress < 100) {
            m_defuseProxy->show();
            QMetaObject::invokeMethod(this, "adjustProgressBarPosition",
                                      Qt::QueuedConnection);
        } else {
            m_defuseProxy->hide();
        }
    });
    if (c4) return;
}

