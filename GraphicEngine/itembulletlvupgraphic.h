#ifndef ITEMBULLETLVUPGRAPHIC_H
#define ITEMBULLETLVUPGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class ItemBulletLvupGraphic :public Graphic
{
public:
    enum PicStatus{
        EMPTY,
        CREATE,
        NORMAL1,
        NORMAL2,
        NORMAL3,
        DESTROY
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY + 1];
    static double TIME[DESTROY + 1];
    static void InitItemBulletLvup();
    ItemBulletLvupGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // ITEMBULLETLvupGRAPHIC_H
