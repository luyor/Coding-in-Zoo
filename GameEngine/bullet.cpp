#include "bullet.h"

Bullet::Bullet(Point v,Point p,double angle0,vector<Circle>& hit_point0,
               Graphic graphic0,int damage0,enum BulletType type,Player*belonging0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    damage(damage0),bullet_type(type),belonging(belonging0)
{
}

Bullet::Bullet(Point v,Point p,double angle0,vector<Circle>& hit_point0,
               Graphic graphic0,int damage0,enum BulletType type):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    damage(damage0),bullet_type(type)
{
}

int Bullet::Hit()
{
    if (bullet_type==LASER)SetDestroy();
    return damage;
}
