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
    void MissionStart(double time){}
    void MissionComplete(double time){}
    void PaintBackground(double time);
    bool MissionCompleteFinish(){return false;}
    Point GetFighterSize(){return Point(60,60);}
    vector<PicNode>pics_to_show;
signals:
    void Update();
};

#endif // GRAPHICENGINE_H
