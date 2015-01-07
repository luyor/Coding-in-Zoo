#ifndef Boss3Graphic_H
#define Boss3Graphic_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Boss3Graphic :public Graphic
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
        DESTROY4,
        DESTROY5,
        DESTROY6,
        DESTROY7,
        DESTROY8,
        DESTROY9,
        DESTROY10,
        DESTROY11,
        DESTROY_FINISH
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    static QImage *pics[DESTROY_FINISH + 1];
    static double TIME[DESTROY_FINISH + 1];
    static void InitBoss3();
    Boss3Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // Boss3Graphic_H
