#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QSound>
#include <QSoundEffect>

class SoundEngine : public QObject
{
    Q_OBJECT
public:
    explicit SoundEngine(QObject *parent = 0);
    QSoundEffect* SoundBGM = new QSoundEffect(this);
    QSound* SoundBulletYellow = new QSound("BulletYellow.wav",this);
    QSound* SoundBulletBlue = new QSound("BulletBlue.wav",this);
    QSound* SoundBulletPurple = new QSound("BulletPurple.wav",this);
    void PlaySoundBGM();

public slots:
    void PlaySoundBulletYellow();
    void PlaySoundBulletBlue();
    void PlaySoundBulletPurple();
};

#endif // SOUNDENGINE_H
