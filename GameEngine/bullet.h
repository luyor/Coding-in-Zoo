#ifndef BULLET_H
#define BULLET_H

#include "flyingobject.h"
#include "player.h"

class Bullet : public FlyingObject
{
public:
    enum BulletType{
        NORMAL=0,
        LASER
    }bullet_type;

    //constructor of friendly bullet
    Bullet(Point v,Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int damage0,enum BulletType type,Player* belonging0);

    //constructor of enemy bullet
    Bullet(Point v,Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,enum BulletType type,int damage0);


    int Hit();//return damage
    void AddScore(int score0){belonging->AddScore(score0);}
private:
    int damage;
    Player* belonging;//used to increase score of a player
};

#endif // BULLET_H
