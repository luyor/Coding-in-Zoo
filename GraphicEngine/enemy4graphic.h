#ifndef Enemy4Graphic_H
#define Enemy4Graphic_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Enemy4Graphic :public Graphic
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
    static void InitEnemy2();
    Enemy4Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // Enemy4Graphic_H
