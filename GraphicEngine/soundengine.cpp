#include "soundengine.h"

SoundEngine::SoundEngine(QObject *parent) :
    QObject(parent)
{
    PlaySoundBGM();
}

void SoundEngine::PlaySoundBulletYellow()
{
    SoundBulletYellow->play();
}

void SoundEngine::PlaySoundBulletBlue()
{
    SoundBulletBlue->play();
}

void SoundEngine::PlaySoundBulletPurple()
{
    SoundBulletPurple->play();
}

void SoundEngine::PlaySoundBGM()
{
    SoundBGM->setSource(QUrl::fromLocalFile("BGM1.wav"));
    SoundBGM->setVolume(0.5f);
    SoundBGM->setLoopCount(QSoundEffect::Infinite);
    SoundBGM->play();
}
