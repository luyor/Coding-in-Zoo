#ifndef FIGHTER2GRAPHIC_H
#define FIGHTER2GRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Fighter2Graphic : public Graphic
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
    static void InitFighter2();
    Fighter2Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // FIGHTER2GRAPHIC_H
