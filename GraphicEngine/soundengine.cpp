#include "soundengine.h"

SoundEngine::SoundEngine(QObject *parent) :
    QObject(parent)
{
    SoundBGM->setMedia(QUrl::fromLocalFile("BulletYellow.wav"));
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
    //SoundBGM->setSource(QUrl::fromLocalFile("BGM1.wav"));
    //SoundBGM->setVolume(50);
    //for(;;)
    if(SoundBGM->state() == QMediaPlayer::StoppedState)
        SoundBGM->play();
}
