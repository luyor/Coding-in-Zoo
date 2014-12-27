#ifndef MISSILE_H
#define MISSILE_H

#include "bullet.h"
#include "flyingobject.h"

class Missile:public Bullet
{
public:
    //friendly missile constructor
    Missile(double speed0,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,int damage0,
            Player* belonging0,FlyingObject* target0,double max_turn_angle0,double miss_target_angle0);
    //enemy missile constructor
    Missile(double speed0,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,int damage0,
            FlyingObject* target0,double max_turn_angle0,double miss_target_angle0);
    void ChangeStatus(double time, Game &my_game);


private:
    FlyingObject* target;
    int damage;
    double max_turn_angle;
    double miss_target_angle;
    double speed;
    double turned_angle;
};

#endif // MISSILE_H
