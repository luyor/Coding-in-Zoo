#ifndef BULLETYELLOWGRAPHIC_H
#define BULLETYELLOWGRAPHIC_H

#include "../stdafx.h"
#include "graphic.h"
#include <QImage>


class BulletYellowGraphic : public Graphic
{
public:
    enum PicStatus{
        CREATE = 0,
        NORMAL,
        DESTROY
    };
    enum PicStatus status;
    static const QImage *pics[PicStatus::DESTROY + 1];
    static const double TIME[PicStatus::DESTROY + 1];
    BulletYellowGraphic();
    void Paint(Point position,Point velocity,double angle,double time);
};

#endif // BULLETYELLOWGRAPHIC_H
