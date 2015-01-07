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
    int BGM_index;
    //QSoundEffect* SoundBGM = new QSoundEffect(this);
    QMediaPlaylist* BGMList = new QMediaPlaylist;
    QMediaPlayer* SoundBGM = new QMediaPlayer;
    QMediaPlayer* SoundFighterDestroy = new QMediaPlayer;
    QMediaPlayer* SoundBombFall = new QMediaPlayer;
    QMediaPlayer* SoundBombAtomic = new QMediaPlayer;
    QMediaPlayer* SoundBombDisperse = new QMediaPlayer;
    QMediaPlayer* SoundEnemyDestroy = new QMediaPlayer;

    QSoundEffect* SoundBulletYellow = new QSoundEffect(this);
    QSoundEffect* SoundBulletBlue = new QSoundEffect(this);
    QSoundEffect* SoundBulletPurple = new QSoundEffect(this);
    QSoundEffect* SoundEnemyHit = new QSoundEffect(this);
    QSoundEffect* SoundItemGet = new QSoundEffect(this);
    int vbgm,veffect;

public slots:
    void NextBGM();
    void ResetBGM();
    void ChangeVolume();
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
    void PlaySoundItemGet();
};

#endif // SOUNDENGINE_H
