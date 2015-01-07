#ifndef EnemyBullet3Graphic_H
#define EnemyBullet3Graphic_H

#include "graphic.h"
#include <QImage>
#include "picnode.h"

class EnemyBullet3Graphic :public Graphic
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
    static void InitEnemyBullet3();
    EnemyBullet3Graphic();
    Point Size();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // EnemyBullet3Graphic_H
