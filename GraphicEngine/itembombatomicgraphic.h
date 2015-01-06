#ifndef ITEMBOMBATOMICGRAPHIC_H
#define ITEMBOMBATOMICGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class ItemBombAtomicGraphic :public Graphic
{
public:
    enum PicStatus{
        EMPTY,
        CREATE,
        NORMAL,
        DESTROY
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY + 1];
    static double TIME[DESTROY + 1];
    static void InitItemBombAtomic();
    ItemBombAtomicGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};
#endif // ITEMBOMBATOMICGRAPHIC_H
