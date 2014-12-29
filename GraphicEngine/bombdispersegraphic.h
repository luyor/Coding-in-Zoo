#ifndef BOMBDISPERSEGRAPHIC_H
#define BOMBDISPERSEGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class BombDisperseGraphic : public Graphic
{
public:
    enum PicStatus{
        EMPTY = 0,
        CREATE,
        NORMAL,
        HIT1,
        HIT2,
        HIT3,
        HIT4,
        DESTROY,
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY + 1];
    static double TIME[DESTROY + 1];
    static void InitBombDisperse();
    BombDisperseGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // BOMBDISPERSEGRAPHIC_H
