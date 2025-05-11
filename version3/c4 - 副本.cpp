// #include "c4.h"
// #include "player.h"
// #include <QGraphicsScene>

// C4::C4(QPointF pos, QObject *parent)
//     : QObject(parent) {
//     // 初始化显示
//     setPixmap(QPixmap(":/images/c4.jpg"));
//     setPos(pos);
//     setZValue(999); // 确保在最上层
//     // 初始化音效
//     // m_beepSound.setSource(QUrl("qrc:/sounds/c4_beep.wav"));
//     // m_explosionSound.setSource(QUrl("qrc:/sounds/boom.wav"));
//     // m_defuseSound.setSource(QUrl("qrc:/sounds/defuse.wav"));
//      // 主计时器
//     m_mainTimer = new QTimer(this);
//     connect(m_mainTimer, &QTimer::timeout, this, [this]{
//         static int elapsed = 0;
//         if(++elapsed == 30) {
//             m_beepSound.play(); // 30秒提示音
//         }
//         else if(elapsed >= 40) {
//             triggerExplosion();
//         }
//     });
//     m_mainTimer->start(1000); // 每秒触发
//     // 玩家检测
//     m_checkTimer = new QTimer(this);
//     connect(m_checkTimer, &QTimer::timeout, this, &C4::checkPlayerNear);
//     m_checkTimer->start(100); // 每100ms检测
// }
// void C4::checkPlayerNear() {
//     if(m_state != Armed) return;
//     // 检测10像素内的玩家
//     foreach(QGraphicsItem *item, scene()->items()) {
//         if(Player *player = dynamic_cast<Player*>(item)) {
//             if(QLineF(pos(), player->pos()).length() < 10) {
//                 if(player->isDefusing()) {
//                     startDefusing();
//                 }
//                 return;
//             }
//         }
//     }
// }
// void C4::startDefusing()
// {
//     if(m_state != Armed)
//     {
//         return;
//     }
//     // m_state = Defusing;
//     // setPixmap(QPixmap(":/images/c4_defusing.png"));
//     m_defuseSound.play();// 拆除计时
//     m_defuseTimer = new QTimer(this);
//     connect(m_defuseTimer, &QTimer::timeout, this, [this]{
//         m_defuseProgress += 1000.0f / 9500.0f; // 9.5秒完成
//         emit updateProgress(m_defuseProgress);
//         if(m_defuseProgress >= 1.0f) {
//             m_state = Defused;
//             emit defused();
//         }
//     });
//     m_defuseTimer->start(100); // 每100ms更新进度
// }
// void C4::triggerExplosion() {
//     m_state = Exploded;
//     // setPixmap(QPixmap(":/images/c4_exploded.png"));
//     m_explosionSound.play();
//     emit exploded();
// }


#include "c4.h"
#include "player.h"
#include <QGraphicsScene>
#include<QAudioOutput>
C4::C4(QPointF pos, QObject *parent) : QObject(parent) {
    setPixmap(QPixmap(":/images/c4.jpg"));
    setPos(pos);
    setZValue(999);
     m_startSound.setSource(QUrl("qrc:/sounds/CS2C4_converted.WAV"));
    m_explosionSound.setSource(QUrl("qrc:/sounds/boom2.WAV"));
      m_startSound.play();
    m_totalTimer = new QTimer(this);
    connect(m_totalTimer, &QTimer::timeout, this, &C4::checkTotalTime);
    m_totalTimer->start(1000);  // 每秒检查一次
    m_checkTimer = new QTimer(this);
    connect(m_checkTimer, &QTimer::timeout, this, &C4::checkPlayerNear);
    m_checkTimer->start(100);
    m_elapsedTimer.start();  // 开始计时
}
void C4::startDefusing() {
    if(m_state != Armed) return;
    m_state = Defusing;
    // m_defuseSound.play();
    // 拆除计时器（9.5秒）
    m_defuseTimer = new QTimer(this);
    connect(m_defuseTimer, &QTimer::timeout, [this]{
        m_defuseProgress += 100.0f / 950.0f;  // 每100ms增加约1.05%
        emit updateProgress(m_defuseProgress);
        if(m_defuseProgress >= 100.0f || m_elapsedTimer.elapsed() >= 45090) {
            m_defuseTimer->stop();
            m_state = (m_elapsedTimer.elapsed() < 45090) ? Defused : Exploded;
            emit (m_state == Defused) ? defused() : exploded();
        }
    });
    m_defuseTimer->start(100);
}
void C4::triggerExplosion() {
    m_state = Exploded;
    setPixmap(QPixmap(":/images/explosion.png"));
    m_explosionSound.play();
    emit exploded();
}
void C4::checkTotalTime() {
    if(m_elapsedTimer.elapsed() >= 45090) {
        triggerExplosion();
    }
}

void C4::checkPlayerNear() {
    if(m_state != Armed) return;
    foreach(QGraphicsItem *item, scene()->items())
    {
        if(Player *player = dynamic_cast<Player*>(item))
        {
            if(QLineF(pos(), player->pos()).length() < 10 &&
                player->isDefusing() &&
                m_elapsedTimer.elapsed() < 45090) {
                startDefusing();
                return;
            }
        }
    }
    // 玩家离开时重置拆除状态
    if(m_state == Defusing) {
        m_defuseTimer->stop();
        m_state = Armed;
        m_defuseProgress = 0;
        emit updateProgress(0);
    }

}
C4::~C4() {
    if(m_mainTimer && m_mainTimer->isActive())
    {
        m_mainTimer->stop();
        delete m_mainTimer;
    }
    if(m_defuseTimer && m_defuseTimer->isActive())
    {
        m_defuseTimer->stop();
        delete m_defuseTimer;
    }
    if(m_checkTimer && m_checkTimer->isActive())
    {
        m_checkTimer->stop();
        delete m_checkTimer;
    }
}

// #include "c4.h"
// #include "player.h"
// #include <QGraphicsScene>
// #include<QAudioOutput>

// C4::C4(QPointF pos, QObject *parent) : QObject(parent) {
//     setPixmap(QPixmap(":/images/c4.jpg"));
//     setPos(pos);
//     setZValue(999);
//     m_player->setAudioOutput(m_audioOutput);
//     m_player->setSource(QUrl("qrc:/sounds/CS2C4.WAV"));
//     m_player->play();


//     // 总计时器
//     m_totalTimer = new QTimer(this);
//     connect(m_totalTimer, &QTimer::timeout, this, &C4::checkTotalTime);
//     m_totalTimer->start(1000);  // 每秒检查一次
//     // 玩家检测（每100ms）
//     m_checkTimer = new QTimer(this);
//     connect(m_checkTimer, &QTimer::timeout, this, &C4::checkPlayerNear);
//     m_checkTimer->start(100);
//     m_elapsedTimer.start();  // 开始计时
// }
// void C4::startDefusing() {
//     if(m_state != Armed) return;
//     m_state = Defusing;
//     m_defuseSound.play();
//     // 拆除计时器（9.5秒）
//     m_defuseTimer = new QTimer(this);
//     connect(m_defuseTimer, &QTimer::timeout, [this]{
//         m_defuseProgress += 100.0f / 950.0f;  // 每100ms增加约1.05%
//         emit updateProgress(m_defuseProgress);
//         if(m_defuseProgress >= 100.0f || m_elapsedTimer.elapsed() >= 45090) {
//             m_defuseTimer->stop();
//             m_state = (m_elapsedTimer.elapsed() < 45090) ? Defused : Exploded;
//             emit (m_state == Defused) ? defused() : exploded();
//         }
//     });
//     m_defuseTimer->start(100);
// }
// void C4::triggerExplosion() {
//     m_state = Exploded;
//     setPixmap(QPixmap(":/images/explosion.png"));
//     m_explosionSound.play();
//     emit exploded();
// }
// void C4::checkTotalTime() {
//     if(m_elapsedTimer.elapsed() >= 45090) {
//         triggerExplosion();
//     }
// }

// void C4::checkPlayerNear() {
//     if(m_state != Armed) return;
//     foreach(QGraphicsItem *item, scene()->items())
//     {
//         if(Player *player = dynamic_cast<Player*>(item))
//         {
//             if(QLineF(pos(), player->pos()).length() < 10 &&
//                 player->isDefusing() &&
//                 m_elapsedTimer.elapsed() < 45090) {
//                 startDefusing();
//                 return;
//             }
//         }
//     }
//     // 玩家离开时重置拆除状态
//     if(m_state == Defusing) {
//         m_defuseTimer->stop();
//         m_state = Armed;
//         m_defuseProgress = 0;
//         emit updateProgress(0);
//     }

// }
// C4::~C4() {
//     if(m_mainTimer && m_mainTimer->isActive())
//     {
//         m_mainTimer->stop();
//         delete m_mainTimer;
//     }
//     if(m_defuseTimer && m_defuseTimer->isActive())
//     {
//         m_defuseTimer->stop();
//         delete m_defuseTimer;
//     }
//     if(m_checkTimer && m_checkTimer->isActive())
//     {
//         m_checkTimer->stop();
//         delete m_checkTimer;
//     }
// }
