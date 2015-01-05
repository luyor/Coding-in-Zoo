#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "../stdafx.h"
#include "../General/point.h"
#include "picnode.h"
#include <qobject.h>

class Fighter;

class GraphicEngine :public QObject
{
    Q_OBJECT
public:
    GraphicEngine();
    double bk;
    Fighter *f1, *f2;
    void MissionStart(double time){}
    void MissionComplete(double time){}
    void PaintBackground(double position);
    void PaintForeground(Fighter* fighter1, Fighter* fighter2);
    bool MissionCompleteFinish(){return false;}
    QPixmap* back_ground,*title;
    vector<PicNode>pics_to_show;
signals:
    void Update();
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

#endif // GRAPHICENGINE_H
