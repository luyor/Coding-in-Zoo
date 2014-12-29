#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "../stdafx.h"
#include "../General/point.h"
#include "picnode.h"
#include <qobject.h>

class GraphicEngine :public QObject
{
    Q_OBJECT
public:
    GraphicEngine();
    double bk_time;
    void MissionStart(double time){}
    void MissionComplete(double time){}
    void PaintBackground(double time);
    bool MissionCompleteFinish(){return false;}
    QPixmap* back_ground;
    vector<PicNode>pics_to_show;
    void InitBK();
signals:
    void Update();
};

#endif // GRAPHICENGINE_H
