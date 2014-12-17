#include "enemy.h"

Enemy::Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
             Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),health(health0),
    HIT_SCORE(HIT_SCORE0),DESTROY_SCORE(DESTROY_SCORE0)
{
}

int Enemy::Hit(int damage)
{
    health-=damage;
    if (health<=0){
        SetDestroy();
        return DESTROY_SCORE;
    }
    return HIT_SCORE*damage;
}
