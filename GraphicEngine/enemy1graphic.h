#ifndef ENEMY1GRAPHIC_H
#define ENEMY1GRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Enemy1Graphic :public Graphic
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
        DESTROY_FINISH
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY_FINISH + 1];
    static double TIME[DESTROY_FINISH + 1];
    static void InitEnemy1();
    Enemy1Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // ENEMY1GRAPHIC_H
