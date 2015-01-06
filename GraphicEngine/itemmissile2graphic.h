#ifndef ITEMMISSILE2GRAPHIC_H
#define ITEMMISSILE2GRAPHIC_H
#include "graphic.h"
#include <QImage>
#include "picnode.h"

class ItemMissile2Graphic :public Graphic
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
    static void InitItemMissile2();
    ItemMissile2Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};
#endif // ITEMMISSILE2GRAPHIC_H
