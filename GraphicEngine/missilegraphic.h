#ifndef MISSILEGRAPHIC_H
#define MISSILEGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class MissileGraphic:public Graphic
{
public:
    enum PicStatus{
        EMPTY = 0,
        CREATE,
        NORMAL,
        DESTROY
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY + 1];
    static double TIME[DESTROY + 1];
    static void InitMissile();
    MissileGraphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // MISSILEGRAPHIC_H
