#include "c4.h"
#include "player.h"
#include <QGraphicsScene>
#include<QAudioOutput>
C4::C4(QPointF pos, QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(":/images/c41.png"));
    setPos(pos);
    setZValue(999);
    m_startSound.setSource(QUrl("qrc:/sounds/CS2C4_converted.WAV"));
    m_explosionSound.setSource(QUrl("qrc:/sounds/boom2.WAV"));
    m_defuseSound.setSource(QUrl("qrc:/sounds/DEFUSE__.WAV"));
    m_startSound.play();
    m_totalTimer = new QTimer(this);//总计时器
    connect(m_totalTimer, &QTimer::timeout, this, &C4::checkTotalTime);
    m_totalTimer->start(1000);//每秒检查一次总时间
    m_checkTimer = new QTimer(this);//确认玩家位置的计时器
    connect(m_checkTimer, &QTimer::timeout, this, &C4::checkPlayerNear);//和函数相连检测角色位置
    m_checkTimer->start(100);//0.1s检测一次
    m_elapsedTimer.start();  //开始计时
}
void C4::checkPlayerNear()
{
    foreach(QGraphicsItem *item, scene()->items())
    {
        if(Player *player = dynamic_cast<Player*>(item))
        {
            if((QLineF(pos(), player->pos()).length() <= 150) &&(player->isDefusing()) && (m_elapsedTimer.elapsed() < 45090))
            {
                startDefusing();
                return;
            }
        }
    }
}
void C4::startDefusing()
{
    m_defuseSound.play();
    m_state = Defusing;
    m_defuseTimer = new QTimer(this);//拆除的计数器
    connect(m_defuseTimer, &QTimer::timeout, [this]
            {
                m_defuseProgress += 100.0f / 95.0f;
                emit updateProgress(m_defuseProgress);//进度更新信号
                if(m_defuseProgress >= 100.0f||m_elapsedTimer.elapsed()>=45090) {
                    m_defuseTimer->stop();
                    m_state = (m_elapsedTimer.elapsed() < 45090) ? Defused : Exploded;
                    emit (m_state==Defused) ? defused():exploded();
                }
            });
    m_defuseTimer->start(100);

}
void C4::triggerExplosion()
{
    m_state = Exploded;
    setPixmap(QPixmap(":/images/c42.png"));
    m_explosionSound.play();
    emit exploded();
}
void C4::checkTotalTime()
{
    if(m_elapsedTimer.elapsed() >= 45090)
    {
        triggerExplosion();
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

