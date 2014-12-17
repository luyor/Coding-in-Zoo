#ifndef BOMB_H
#define BOMB_H

#include "bullet.h"

//send HIT paint message when explode
class Bomb:public Bullet
{
public:
    Bomb(Point v,Point p,double angle0,Graphic graphic0);
};

#endif // BOMB_H
