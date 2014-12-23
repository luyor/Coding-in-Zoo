#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "../stdafx.h"
#include "../General/point.h"
#include "picnode.h"

class GraphicEngine
{
public:
    GraphicEngine();
    void MissionStart();
    void MissionComplete();
    void PaintBackground(double time);
    Point GetVisibleArea();
    Point GetFighterSize();
    vector<PicNode>pics_to_show;
};

#endif // GRAPHICENGINE_H
