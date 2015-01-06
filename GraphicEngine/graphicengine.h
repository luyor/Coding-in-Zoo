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
    double title_time;
    double door_time;
    bool door_open,
         door_close;
    Fighter *f1, *f2;
    void MissionStart();
    void MissionComplete();
    void PaintDoor(double time);
    void PaintBackground(double position);
    void PaintForeground(Fighter* fighter1, Fighter* fighter2);
    void PaintTitle(double time);
    bool MissionStartFinish();
    bool MissionCompleteFinish();
    QPixmap *back_ground,
            *title,
            *bk_title,
            *bomb_atomic,
            *bomb_disperse,
            *life1,
            *life2,
            *door1,
            *door2;
    vector<PicNode>pics_to_show;
    bool END_PAINT;
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
