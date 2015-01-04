#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QMediaPlaylist>
class SoundEngine : public QObject
{
    Q_OBJECT
public:
    explicit SoundEngine(QObject *parent = 0);
    //QSoundEffect* SoundBGM = new QSoundEffect(this);
    QMediaPlaylist* BGMList = new QMediaPlaylist;
    QMediaPlayer* SoundBGM = new QMediaPlayer;
    QMediaPlayer* SoundFighterDestroy = new QMediaPlayer;
    QMediaPlayer* SoundBombFall = new QMediaPlayer;
    QMediaPlayer* SoundBombAtomic = new QMediaPlayer;
    QMediaPlayer* SoundBombDisperse = new QMediaPlayer;
    QMediaPlayer* SoundEnemyDestroy = new QMediaPlayer;
    QSound* SoundBulletYellow = new QSound("BulletYellow.wav",this);
    QSound* SoundBulletBlue = new QSound("BulletBlue.wav",this);
    QSound* SoundBulletPurple = new QSound("BulletPurple.wav",this);
    QSound* SoundEnemyHit = new QSound("EnemyHit.wav",this);


public slots:
    void PlaySoundBGM();
    void PlaySoundFighterDestroy();
    void PlaySoundBombFall();
    void PlaySoundBombAtomic();
    void PlaySoundBombDisperse();
    void PlaySoundEnemyDestroy();
    void PlaySoundBulletYellow();
    void PlaySoundBulletBlue();
    void PlaySoundBulletPurple();
    void PlaySoundEnemyHit();
};

#endif // SOUNDENGINE_H
