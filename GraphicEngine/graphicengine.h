#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "../General/point.h"

class GraphicEngine
{
public:
    GraphicEngine();
    void MissionStart();
    void MissionComplete();
    void PaintBackground(double time);
    Point GetVisibleArea();
    Point GetFighterSize();
};

#endif // GRAPHICENGINE_H
