#ifndef EnemyBullet2Graphic_H
#define EnemyBullet2Graphic_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class EnemyBullet2Graphic :public Graphic
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
    static void InitEnemyBullet2();
    EnemyBullet2Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // EnemyBullet2Graphic_H
