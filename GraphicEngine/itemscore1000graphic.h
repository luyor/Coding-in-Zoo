#ifndef ITEMSCORE1000GRAPHIC_H
#define ITEMSCORE1000GRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class ItemScore1000Graphic :public Graphic
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
    static void InitItemScore1000();
    ItemScore1000Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // ITEMSCORE1000GRAPHIC_H
