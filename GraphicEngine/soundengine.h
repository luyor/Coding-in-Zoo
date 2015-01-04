#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QSound>
#include <QSoundEffect>
#include <QMediaPlayer>

class SoundEngine : public QObject
{
    Q_OBJECT
public:
    explicit SoundEngine(QObject *parent = 0);
    //QSoundEffect* SoundBGM = new QSoundEffect(this);
    QMediaPlayer* SoundBGM = new QMediaPlayer;
    QSound* SoundBulletYellow = new QSound("BulletYellow.wav",this);
    QSound* SoundBulletBlue = new QSound("BulletBlue.wav",this);
    QSound* SoundBulletPurple = new QSound("BulletPurple.wav",this);


public slots:
    void PlaySoundBGM();
    void PlaySoundBulletYellow();
    void PlaySoundBulletBlue();
    void PlaySoundBulletPurple();
};

#endif // SOUNDENGINE_H
