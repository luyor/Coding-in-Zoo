#include "soundengine.h"
#include "../res.h"

SoundEngine::SoundEngine(QObject *parent) :
    QObject(parent),vbgm(100),veffect(50),BGM_index(0)
{

    SoundBulletYellow->setSource(QUrl::fromLocalFile("BulletYellow.wav"));
    SoundBulletYellow->setVolume((double)veffect/100);
    SoundBulletBlue->setSource(QUrl::fromLocalFile("BulletBlue.wav"));
    SoundBulletBlue->setVolume((double)veffect/100);
    SoundBulletPurple->setSource(QUrl::fromLocalFile("BulletPurple.wav"));
    SoundBulletPurple->setVolume((double)veffect/100);
    SoundEnemyHit->setSource(QUrl::fromLocalFile("EnemyHit.wav"));
    SoundEnemyHit->setVolume((double)veffect/100);
    SoundItemGet->setSource(QUrl::fromLocalFile("ItemGet.wav"));
    SoundItemGet->setVolume((double)veffect/100);

    BGMList->addMedia(QUrl::fromLocalFile("BGM_Title.wav"));
    BGMList->addMedia(QUrl::fromLocalFile("BGM1.wav"));
    BGMList->addMedia(QUrl::fromLocalFile("BGM2.wav"));
    BGMList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    BGMList->setCurrentIndex(BGM_index);
    SoundBGM->setPlaylist(BGMList);
    SoundBGM->setVolume(vbgm);
    SoundFighterDestroy->setMedia(QUrl::fromLocalFile("FighterDestroy.wav"));
    SoundBombFall->setMedia(QUrl::fromLocalFile("BombFall.wav"));
    SoundBombAtomic->setMedia(QUrl::fromLocalFile("BombAtomic.wav"));
    SoundBombDisperse->setMedia(QUrl::fromLocalFile("BombDisperse.wav"));
    SoundEnemyDestroy->setMedia(QUrl::fromLocalFile("EnemyDestroy.wav"));
    SoundFighterDestroy->setVolume(vbgm);
    SoundBombFall->setVolume(vbgm);
    SoundBombAtomic->setVolume(vbgm);
    SoundBombDisperse->setVolume(vbgm);
    SoundEnemyDestroy->setVolume(vbgm);
}

void SoundEngine::NextBGM()
{
    if(++BGM_index > 2) BGM_index = 0;
    BGMList->setCurrentIndex(BGM_index);
}

void SoundEngine::ResetBGM()
{
    BGM_index = 0;
    BGMList->setCurrentIndex(BGM_index);
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
    SoundBGM->stop();
    SoundBGM->play();
}

void SoundEngine::PlaySoundItemGet()
{
    SoundItemGet->play();
}

void SoundEngine::ChangeVolume()
{
    vbgm = gamepara.backGroundSound;
    veffect = gamepara.bombSound;

    //SoundBulletYellow->setVolume((double)veffect/100);
    //SoundBulletBlue->setVolume((double)veffect/100);
    //SoundBulletPurple->setVolume((double)veffect/100);
    //SoundEnemyHit->setVolume((double)veffect/100);
    //SoundItemGet->setVolume((double)veffect/100);


    SoundFighterDestroy->setVolume(vbgm);
    SoundBombFall->setVolume(vbgm);
    SoundBombAtomic->setVolume(vbgm);
    SoundBombDisperse->setVolume(vbgm);
    SoundEnemyDestroy->setVolume(vbgm);
    
    SoundBGM->setVolume(vbgm);
}
