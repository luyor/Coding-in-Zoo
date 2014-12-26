#ifndef BULLET_H
#define BULLET_H

#include "flyingobject.h"
#include "player.h"
#include "../General/hitpoint.h"

static HitPoint yellow_bullet_hit_point;

class Bullet : public FlyingObject
{
public:
    enum BulletType{
        NORMAL=0,
        LASER
    }bullet_type;

    //constructor of friendly bullet
    Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
           Graphic *graphic0,enum BulletType type,int damage0,Player* belonging0);

    //constructor of enemy bullet
    Bullet(Point v,Point p,double angle0,HitPoint* hit_point0,
           Graphic *graphic0,enum BulletType type,int damage0);

    void ChangeStatus(double time, Game &my_game);
    int Hit();//return damage
    void AddScore(int score0){belonging->AddScore(score0);}
    static void Init();

private:
    int damage;
    Player* belonging;//used to increase score of a player
};

#endif // BULLET_H
