
#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include "player.h"
#include <QRandomGenerator>//用于生成随机数
#include"floor.h"
#include"enemy.h"
#include <QProgressBar>
#include"win.h"
#include"lose.h"
#include <QSoundEffect>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent*event)override;//override指出为重写
    void keyReleaseEvent(QKeyEvent*event)override;//松开
    void mousePressEvent(QMouseEvent*event)override;//点击鼠标
      void startgame();//外部调用的游戏启动方法
    QProgressBar *m_defuseProgressBar;
    void initialize();//初始化函数
      QGraphicsProxyWidget* m_defuseProxy;
    void createFloors ()//对于是否均匀分布还要调整
    {
        int floornumber = QRandomGenerator::global()->bounded(3) + 6;//随机生成6~8个地板
        qreal originx = -450+QRandomGenerator::global()->bounded(1000);
        while(originx-Floor::width/2<=-142||originx+Floor::width>=1254)
        {
            originx = -450+QRandomGenerator::global()->bounded(1000);
        }
        qreal originy = (500 + Player::playerheight)-(QRandomGenerator::global()->bounded(15)+70)+Floor::thickness;
        while(originy-Floor::thickness<=-181||originy>=788)
        {
            qreal originy = (500 + Player::playerheight)-(QRandomGenerator::global()->bounded(15)+70)+Floor::thickness;
        }
        Floor*firstfloor = new Floor(originx, originy);//单独生成第一个地板，坐标设置保证可以跳上
        scene->addItem(firstfloor);
        int enemynumber =5;
        for(int i=1; i<floornumber; i++)
        {
            qreal deltax = QRandomGenerator::global()->bounded(500)-250;
            qreal deltay = QRandomGenerator::global()->bounded(15)+60;
            qreal newx = originx+deltax;
            qreal newy= originy-deltay-Floor::thickness;
            while(newx<=-500||newx+Floor::width>=1240)
            {
                deltax = QRandomGenerator::global()->bounded(500)-250;
                newx = -450+QRandomGenerator::global()->bounded(1000);
            }
            while(newy-Floor::thickness<=-181||newy>=788)
            {
                deltay = QRandomGenerator::global()->bounded(15)+60;
                newy = (500 + Player::playerheight)-(QRandomGenerator::global()->bounded(15)+70)+Floor::thickness;
            }
            qreal realdeltax=newx>originx?(newx-originx):(originx-newx);
            while(realdeltax<(Floor::width+100)||realdeltax>Floor::width*7/4)//处理左右移动的太少的情况或太多的情况
            {
                newx+= QRandomGenerator::global()->bounded(400)-200;//左右调
                realdeltax=newx>originx?(newx-originx):(originx-newx);
            }
            originx=newx;
            originy=newy;//一次之后改变变化的基准了
            Floor*floor=new Floor(newx,newy);
            scene->addItem(floor);
            if (floornumber -i<=enemynumber)//由于地板数量在6到8，敌人数量设置为5，保证能生成完
            {
                enemy*en=new enemy(floor,player);
                scene->addItem(en);
                enemynumber--;
            }
            else if(floornumber-i>enemynumber)//若剩余的地板数量足够，70的概率上面刷新敌人
            {
                if(QRandomGenerator::global()->bounded(100)-70<=0)
                {
                    enemy*en=new enemy(floor,player);
                    scene->addItem(en);
                    enemynumber--;
                }
            }
        }
    }
    void startC4Scenario();
    void gameover(bool iswin) {
         gametiming->stop();
        if (m_c4)
         {
            m_c4->stopTimers();
            disconnect(m_c4, &C4::exploded, this, nullptr);//断开所有关联信号
            disconnect(m_c4, &C4::defused, this, nullptr);
        }
        if(iswin) {
            win* winWindow = new win();
            winWindow->show();
        } else {
            lose* loseWindow = new lose();
            loseWindow->show();
        }
        QTimer::singleShot(100, [this]{
            this->close();
            // 安全清理场景
            scene->clear();
            player = nullptr; // 防止野指针
        });
    }
    QSoundEffect m_ctWinsound;
private slots:
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
    Player *player;
    QTimer *gametiming;//计时器
       C4* m_c4 = nullptr;
    bool isKeyPressed(QKeyEvent *event, Qt::Key key);
};
#endif



