#ifndef BULLETPURPLEGRAPHIC_H
#define BULLETPURPLEGRAPHIC_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class BulletPurpleGraphic : public Graphic
{
public:
    enum PicStatus{
        EMPTY,
        CREATE,
        NORMAL1,
        NORMAL2,
        NORMAL3,
        NORMAL4,
        DESTROY
    };
    enum PicStatus status;
    QImage* image_to_show;
    PicNode node;
    int level;
    static QImage *pics[DESTROY + 1];
    static double TIME[DESTROY + 1];
    static void InitBulletPurple();
    BulletPurpleGraphic(int l);
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};
#endif // BULLETPURPLEGRAPHIC_H
