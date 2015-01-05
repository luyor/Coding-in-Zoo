#include "bullet.h"

HitPoint yellow_bullet_hitpoint;
HitPoint blue_bullet_hitpoint;
HitPoint enemy_bullet_hitpoint;

Bullet::Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
               Graphic *graphic0,enum BulletType type,double damage0,Player*belonging0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    bullet_type(type),damage(damage0),belonging(belonging0)
{
}

Bullet::Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
               Graphic *graphic0,enum BulletType type,double damage0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    bullet_type(type),damage(damage0),belonging(NULL)
{
}

double Bullet::Hit(double time)
{
    switch(bullet_type){
    case NORMAL:
        SetDestroy();
        return damage;
        break;
    case LASER:
        return damage*time;
        break;
    }
}

void Bullet::ChangeStatus(double time, Game &my_game)
{
    //do nothing
}

void Bullet::Init()
{
    Circle tmp(7,0,3);
    yellow_bullet_hitpoint.AddCircle(tmp);
    tmp=Circle(7,0,3);
    blue_bullet_hitpoint.AddCircle(tmp);
    tmp=Circle(0,0,2.5);
    enemy_bullet_hitpoint.AddCircle(tmp);
}
