
#ifndef C4_H
#define C4_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSoundEffect>
#include <QElapsedTimer>  // 新增
#include <QAudioOutput>
#include <QMediaPlayer>
class C4 : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    explicit C4(QPointF pos, QObject *parent = nullptr);
   virtual ~C4() override;
    void triggerExplosion();
    void startDefusing();

signals:
    void exploded();
    void defused();
    void updateProgress(float);

private slots:
    void checkPlayerNear();
    void checkTotalTime();  // 新增总时间检查

private:
    enum State { Armed, Defusing, Exploded, Defused };
    State m_state = Armed;
    QTimer *m_mainTimer;
    QTimer *m_defuseTimer;
    QTimer *m_checkTimer;
    QTimer *m_totalTimer;    // 新增总计时器
    QSoundEffect m_beepSound;
     QSoundEffect m_startSound;
    QSoundEffect m_explosionSound;
    QSoundEffect m_defuseSound;
    QElapsedTimer m_elapsedTimer;
    QAudioOutput *m_audioOutput;
     QMediaPlayer *m_player;

    float m_defuseProgress = 0.0f;
    bool m_eKeyHeld = false;
};

#endif // C4_H
