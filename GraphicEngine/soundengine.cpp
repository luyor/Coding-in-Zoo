#include "soundengine.h"

SoundEngine::SoundEngine(QObject *parent) :
    QObject(parent)
{
}

void SoundEngine::PlaySoundBulletYellow()
{
    SoundBulletYellow->play();
}

