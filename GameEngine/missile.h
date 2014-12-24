#ifndef MISSILE_H
#define MISSILE_H

#include "enemy.h"
#include "bullet.h"

class Missile:public Bullet
{
public:
    Missile(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,int damage0,Player* belonging0,Enemy* target0);
    void ChangeStatus(double time, Game &my_game);
private:
    Enemy* target;
    int damage;

    const int SPEED=10;
};

#endif // MISSILE_H
