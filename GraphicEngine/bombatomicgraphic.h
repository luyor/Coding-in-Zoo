#ifndef BOMBATOMICGRAPHIC_H
#define BOMBATOMICGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class BombAtomicGraphic : public Graphic
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
    static void InitBombAtomic();
    BombAtomicGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // BOMBATOMICGRAPHIC_H
