#ifndef MISSILE_H
#define MISSILE_H

#include "enemy.h"
#include "bullet.h"

class Missile:public Bullet
{
public:
    Missile(Point v,Point p,double angle0,vector<Circle>& hit_point0,Graphic graphic0,int damage0,Enemy* target0);
private:
    Enemy* target;
    int damage;
};

#endif // MISSILE_H
