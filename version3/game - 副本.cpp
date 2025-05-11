#include "game.h"
#include"player.h"
#include<floor.h>
#include"c4.h"
#include "win.h"
#include "lose.h"
#include <QRandomGenerator>//用于生成随机数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);  // 初始化场景和视图
    setCentralWidget(view);
    view->setSceneRect(0, 0, 800, 600);// 设置场景大小

    player = new Player();
    scene->addItem(player);
    player->setPos(-460, 500); //初始化玩家的位置

    Floor* baseFloor = new Floor(
        -500,  // 居中
        685,
        2000,         30.0
        );
    scene->addItem(baseFloor);

    createFloors();
      startC4Scenario();
    gametiming = new QTimer(this);  //初始化游戏循环
    connect(gametiming, &QTimer::timeout, [this]() {
        player->updateMovement();
    });
    gametiming->start(16); //16ms一次
    m_defuseProgressBar = new QProgressBar(view); // 父对象设为 view 确保显示
    m_defuseProgressBar->setGeometry( view->width()/2 - 100, view->height() - 50,  200, 20  );
    m_defuseProgressBar->setRange(0, 100); //进度条的显示范围为0-100
    m_defuseProgressBar->hide();//初始隐藏进度条

}

MainWindow::~MainWindow() {
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
        if(Player *p = dynamic_cast<Player*>(scene->focusItem())) {
            p->setEKeyHeld(true);
        }
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
        if(Player *p = dynamic_cast<Player*>(scene->focusItem())) {
            p->setEKeyHeld(false);
        }
    }
}
void MainWindow::mousePressEvent(QMouseEvent *event) {
    QPointF vpos = event->pos(); // 此时得到的点击鼠标event的坐标为视图坐标
    QPointF spos = view->mapToScene(vpos.x(), vpos.y()); // 需要先将其转换为场景坐标，传到射击函数里才能正确计算子弹的方向
    player->shoot(spos);
}

void MainWindow::startC4Scenario()
{

    QPointF spawnPos;
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
        lose* loseWindow = new lose(); // 创建失败窗口
        loseWindow->show();            // 显示窗口
        this->close();                 // 关闭游戏主窗口（可选）
    });
    // 当炸弹被拆除时，弹出胜利界面
    connect(c4, &C4::defused, this, [this]{
        win* winWindow = new win();   // 创建胜利窗口
        winWindow->show();            // 显示窗口
        this->close();                // 关闭游戏主窗口（可选）
    });

    connect(c4, &C4::updateProgress, this, [this](float progress) {
        // 将 0.0~1.0 的浮点数转为 0~100 的整数值
        int value = static_cast<int>(progress * 100);
        m_defuseProgressBar->setValue(value);

        // 当进度有效时显示（0 < progress < 1）
        m_defuseProgressBar->setVisible(value > 0 && value < 100);
    });
         if (c4) return;
}
// #include "game.h"
// #include"player.h"
// #include<floor.h>
// #include"c4.h"
// #include "win.h"
// #include "lose.h"
// #include <QRandomGenerator>//用于生成随机数
// #include "ui_game.h"

// MainWindow::MainWindow(QWidget *parent, const QString& bgPath) : QMainWindow(parent), ui(new Ui::MainWindow),
//     scene(new QGraphicsScene(this))
// {
//     ui->setupUi(this); // 关键：加载UI布局

//     // 初始化视图
//     view = ui->graphicsView;  // UI文件中需有名为graphicsView的QGraphicsView
//     view->setScene(scene);
//     view->setSceneRect(0, 0, 2560, 1600);
//     if (!bgPath.isEmpty()) initBackground(bgPath);
//     player = new Player();
//     scene->addItem(player);
//     player->setPos(-460, 500); //初始化玩家的位置

//     Floor* baseFloor = new Floor(
//         -500,  // 居中
//         685,
//         2000,         30.0
//         );
//     scene->addItem(baseFloor);

//     createFloors();
//     gametiming = new QTimer(this);  //初始化游戏循环
//     connect(gametiming, &QTimer::timeout, [this]() {
//         player->updateMovement();
//     });
//     gametiming->start(16); //16ms一次
//     m_defuseProgressBar = ui->defuseProgressBar;  // UI文件中需有progressBar控件
//     m_defuseProgressBar->setRange(0, 100);
//     m_defuseProgressBar->hide();
//     startC4Scenario();
// }
// void MainWindow::initBackground(const QString& imagePath) {
//     // 清理旧背景
//     if (backgroundItem) {
//         scene->removeItem(backgroundItem);
//         delete backgroundItem;
//     }

//     // 加载并设置新背景
//     QPixmap bg(imagePath);
//     if (!bg.isNull()) {
//         backgroundItem = new QGraphicsPixmapItem(bg.scaled(view->size(), Qt::KeepAspectRatioByExpanding));
//         backgroundItem->setZValue(-100);  // 确保在底层
//         scene->addItem(backgroundItem);
//     }
// }
// MainWindow::~MainWindow() {
//     delete scene;
// }
// void MainWindow::keyPressEvent(QKeyEvent *event) {
//     if (event->key() == Qt::Key_A) {
//         player->presskey(0, true); //A左移
//     } else if (event->key() == Qt::Key_D) {
//         player->presskey(1, true); //D右移
//     }
//     if (event->key() == Qt::Key_Space) {
//         player->presskey(2,true)    ;  // 空格触发跳跃
//     }
//     if (event->key() == Qt::Key_Control) {
//         player->presskey(3, true);
//     }
//     if(event->key() == Qt::Key_E) {
//         if(Player *p = dynamic_cast<Player*>(scene->focusItem())) {
//             p->setEKeyHeld(true);
//         }
//     }
// }
// void MainWindow::keyReleaseEvent(QKeyEvent *event) {
//     if (event->key() == Qt::Key_A) {
//         player->presskey(0, false);
//     } else if (event->key() == Qt::Key_D) {
//         player->presskey(1, false);
//     }if (event->key() == Qt::Key_Space) {
//         player->presskey(2, false); // 释放空格键
//     }
//     if (event->key() == Qt::Key_Control) {
//         player->presskey(3, false);
//     }
//     if(event->key() == Qt::Key_E) {
//         if(Player *p = dynamic_cast<Player*>(scene->focusItem())) {
//             p->setEKeyHeld(false);
//         }
//     }
// }
// void MainWindow::mousePressEvent(QMouseEvent *event) {
//     QPointF vpos = event->pos(); // 此时得到的点击鼠标event的坐标为视图坐标
//     QPointF spos = view->mapToScene(vpos.x(), vpos.y()); // 需要先将其转换为场景坐标，传到射击函数里才能正确计算子弹的方向
//     player->shoot(spos);
// }

// void MainWindow::startC4Scenario()
// {
//     QPointF spawnPos;
//     foreach(QGraphicsItem *item, scene->items())
//     {
//         if(Floor *floor = dynamic_cast<Floor*>(item)) {
//             if(floor->getscenetopy() < spawnPos.y()) {
//                 spawnPos = QPointF(floor->getx() + Floor::width - 50,floor->gettopy());
//             }
//         }
//     }// 寻找最上方地板
//     C4 *c4 = new C4(spawnPos);
//     scene->addItem(c4);

//     connect(c4, &C4::exploded, this, [this]{
//         lose* loseWindow = new lose(); // 创建失败窗口
//         loseWindow->show();            // 显示窗口
//         this->close();                 // 关闭游戏主窗口（可选）
//     });
//     // 当炸弹被拆除时，弹出胜利界面
//     connect(c4, &C4::defused, this, [this]{
//         win* winWindow = new win();   // 创建胜利窗口
//         winWindow->show();            // 显示窗口
//         this->close();                // 关闭游戏主窗口（可选）
//     });

//     connect(c4, &C4::updateProgress, this, [this](float progress) {
//         // 将 0.0~1.0 的浮点数转为 0~100 的整数值
//         int value = static_cast<int>(progress * 100);
//         m_defuseProgressBar->setValue(value);

//         // 当进度有效时显示（0 < progress < 1）
//         m_defuseProgressBar->setVisible(value > 0 && value < 100);
//     });
// }
