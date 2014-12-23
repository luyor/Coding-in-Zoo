#ifndef FIGHTER1GRAPHIC_H
#define FIGHTER1GRAPHIC_H

#include "../stdafx.h"
#include "graphic.h"
#include <QImage>

enum PicStatus{
    CREATE = 0,
    NORMAL,
    HIT1,
    HIT2,
    HIT3,
    DESTROY1,
    DESTROY2,
    DESTROY_FINISH
};

class Fighter1Graphic : public Graphic
{
public:
    enum PicStatus status;
    static QImage *pics[PicStatus::DESTORY_FINISH + 1];
    Fighter1Graphic();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // FIGHTER1GRAPHIC_H
