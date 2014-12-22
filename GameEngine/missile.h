#ifndef MISSILE_H
#define MISSILE_H

#include "enemy.h"
#include "bullet.h"

class Missile:public Bullet
{
public:
    Missile(Point v,Point p,double angle0,const HitPoint* hit_point0,Graphic graphic0,int damage0,Player* belonging0,Enemy* target0);
private:
    Enemy* target;
    int damage;

    const int SPEED;
};

#endif // MISSILE_H
