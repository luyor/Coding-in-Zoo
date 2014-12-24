#ifndef BULLETYELLOWGRAPHIC_H
#define BULLETYELLOWGRAPHIC_H

#include "../stdafx.h"
#include "graphic.h"
#include <QImage>
#include "picnode.h"

class BulletYellowGraphic : public Graphic
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
    static void InitBulletYellow();
    BulletYellowGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // BULLETYELLOWGRAPHIC_H
