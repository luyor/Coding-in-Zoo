#ifndef Enemy2GRAPHIC_H
#define Enemy2GRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class Enemy2Graphic :public Graphic
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
    Enemy2Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // Enemy2GRAPHIC_H
