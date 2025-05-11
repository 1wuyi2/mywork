#ifndef C4_H
#define C4_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QSoundEffect>
#include <QElapsedTimer>
#include <QAudioOutput>
#include <QMediaPlayer>
class C4 : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void stopTimers() {
        if (m_checkTimer) m_checkTimer->stop();
        if (m_defuseTimer) m_defuseTimer->stop();
        if (m_totalTimer) m_totalTimer->stop();
        if (m_mainTimer)m_mainTimer->stop();
    }
    explicit C4(QPointF pos, QObject *parent = nullptr);
   virtual ~C4() override;
    void triggerExplosion();
    void startDefusing();
    enum State { Initial,Defusing, Exploded, Defused };
    State m_state = Initial;
    QTimer *m_mainTimer;
    QTimer *m_defuseTimer;
    QTimer *m_checkTimer;
    QTimer *m_totalTimer;
    QSoundEffect m_beepSound;
    QSoundEffect m_startSound;
    QSoundEffect m_explosionSound;
    QSoundEffect m_defuseSound;
    QElapsedTimer m_elapsedTimer;
    QAudioOutput *m_audioOutput;
    QMediaPlayer *m_player;
    float m_defuseProgress = 0.0f;
    bool m_eKeyHeld = false;
signals:
    void exploded();
    void defused();
    void updateProgress(float);
private slots:
    void checkPlayerNear();
    void checkTotalTime();
};
#endif
