#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QObject>
#include <QSound>

class SoundEngine : public QObject
{
    Q_OBJECT
public:
    explicit SoundEngine(QObject *parent = 0);
    QSound* SoundBulletYellow = new QSound("Sound/BulletYellow");
signals:

public slots:
    void PlaySoundBulletYellow();
};

#endif // SOUNDENGINE_H
