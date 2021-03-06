#ifndef FIGHTER1GRAPHIC_H
#define FIGHTER1GRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Fighter1Graphic : public Graphic
{
public:
    enum PicStatus{
        EMPTY=0,
        CREATE,
        NORMAL,
        HIT1,
        HIT2,
        DESTROY1,
        DESTROY2,
        DESTROY3,
        DESTROY_FINISH
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY_FINISH + 1];
    static double TIME[DESTROY_FINISH + 1];
    static void InitFighter1();
    Fighter1Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // FIGHTER1GRAPHIC_H
