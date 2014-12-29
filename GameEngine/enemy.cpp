#include "enemy.h"
//#include "../GameDesign/enemy1.h"

HitPoint enemy_bullet_hitpoint;

Enemy::Enemy(Point v,Point p,double angle0,HitPoint* hit_point0,
             Graphic *graphic0,double health0,int HIT_SCORE0,int DESTROY_SCORE0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),health(health0),
    HIT_SCORE(HIT_SCORE0),DESTROY_SCORE(DESTROY_SCORE0)
{
}

int Enemy::Hit(double damage)
{
    my_graphics->GetSignal(Graphic::HIT);
    health-=damage;
    if (health<=0){
        SetDestroy();
        return DESTROY_SCORE;
    }
    //cout<<HIT_SCORE*damage<<endl;
    return HIT_SCORE*damage;
}

void Enemy::Init()
{

}
