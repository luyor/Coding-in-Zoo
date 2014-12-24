#include "bullet.h"

Bullet::Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
               Graphic *graphic0,enum BulletType type,int damage0,Player*belonging0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    bullet_type(type),damage(damage0),belonging(belonging0)
{
}

Bullet::Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
               Graphic *graphic0,enum BulletType type,int damage0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),
    bullet_type(type),damage(damage0)
{
}

int Bullet::Hit()
{
    if (bullet_type==LASER)SetDestroy();
    return damage;
}

void Bullet::ChangeStatus(double time, Game &my_game)
{
    //do nothing
}
