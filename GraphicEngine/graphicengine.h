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
    double bk_time;
    Fighter *f1, *f2;
    void MissionStart(double time){}
    void MissionComplete(double time){}
    void PaintBackground(double time);
    void PaintForeground(Fighter* fighter1, Fighter* fighter2);
    bool MissionCompleteFinish(){return false;}
    QPixmap* back_ground,*title;
    vector<PicNode>pics_to_show;
signals:
    void Update();
    void PlayBGM();
    void PlaySoundBulletYellow();
    void PlaySoundBulletBlue();
    void PlaySoundBulletPurple();
};

#endif // GRAPHICENGINE_H
