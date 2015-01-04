#include "soundengine.h"

SoundEngine::SoundEngine(QObject *parent) :
    QObject(parent)
{
    BGMList->addMedia(QUrl::fromLocalFile("BGM1.wav"));
    BGMList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    SoundBGM->setPlaylist(BGMList);
    SoundFighterDestroy->setMedia(QUrl::fromLocalFile("FighterDestroy.wav"));
    SoundBombFall->setMedia(QUrl::fromLocalFile("BombFall.wav"));
    SoundBombAtomic->setMedia(QUrl::fromLocalFile("BombAtomic.wav"));
    SoundBombDisperse->setMedia(QUrl::fromLocalFile("BombDisperse.wav"));
    SoundEnemyDestroy->setMedia(QUrl::fromLocalFile("EnemyDestroy.wav"));
}

void SoundEngine::PlaySoundFighterDestroy()
{
    SoundFighterDestroy->stop();
    SoundFighterDestroy->play();
}

void SoundEngine::PlaySoundBombFall()
{
    SoundBombFall->stop();
    SoundBombFall->play();
}

void SoundEngine::PlaySoundBombAtomic()
{
    SoundBombAtomic->stop();
    SoundBombAtomic->play();
}

void SoundEngine::PlaySoundBombDisperse()
{
    SoundBombDisperse->stop();
    SoundBombDisperse->play();
}

void SoundEngine::PlaySoundEnemyDestroy()
{
    SoundEnemyDestroy->stop();
    SoundEnemyDestroy->play();
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

void SoundEngine::PlaySoundEnemyHit()
{
    SoundEnemyHit->play();
}

void SoundEngine::PlaySoundBGM()
{
    //SoundBGM->setSource(QUrl::fromLocalFile("BGM1.wav"));
    //SoundBGM->setVolume(50);
    SoundBGM->stop();
    SoundBGM->play();
}
