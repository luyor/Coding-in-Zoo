#include "bomb.h"

static vector<Circle> empty_hit_point;

Bomb::Bomb(Point v,Point p,double angle0,Graphic graphic0):
    FlyingObject(v,p,angle0,empty_hit_point,graphic0),
    status(FLYING),elapsed_time(0)
{
}

