#ifndef ENEMY_H
#define ENEMY_H

#include "flyingobject.h"

class Game;

class Enemy:public FlyingObject
{
public:
    Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
          Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    int Hit(int damage);
        //do damge and return score
    virtual void Fire(Game& my_game);
private:
    int health;
    int HIT_SCORE;
    int DESTROY_SCORE;
};

#endif // ENEMY_H
