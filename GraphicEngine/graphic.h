#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "graphicengine.h"

class Graphic
{
public:
    Graphic();
    enum Signal{
        CREATE=0,
        HIT,
        DESTORY
    };
    virtual void SendSignal(enum Signal s);
    bool Finished();
    virtual void Paint(Point position,Point velocity,double angle,double time);
};

#endif // GRAPHIC_H
