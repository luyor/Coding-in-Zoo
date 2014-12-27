#ifndef BULLET_H
#define BULLET_H

#include "flyingobject.h"
#include "player.h"
#include "../General/hitpoint.h"

extern HitPoint yellow_bullet_hitpoint;

class Bullet : public FlyingObject
{
public:
    enum BulletType{
        NORMAL=0,
        LASER
    }bullet_type;

    //constructor of friendly bullet
    Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
           Graphic *graphic0,enum BulletType type,double damage0,Player* belonging0);

    //constructor of enemy bullet
    Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
           Graphic *graphic0,enum BulletType type,double damage0);

    void ChangeStatus(double time, Game &my_game);
    double Hit(double time);//return damage
    void AddScore(int score0){belonging->AddScore(score0);}
    static void Init();

protected:
    double damage;
    Player* belonging;//used to increase score of a player,NULL if is enemy bullet
};

#endif // BULLET_H
