#ifndef ENEMY_H
#define ENEMY_H

#include "flyingobject.h"

class Game;

class Enemy:public FlyingObject
{
public:
    //point v is the velocity
    //point p is the position
    //angle0 is -pi/2 for heading down
    //vector<Circle>& hit_point0 is for collision
    //Graphic grphic0 is for displaying
    //health0 is the health when it was born
    //HIT_SCORE0 is the score you get when you hit this enemy
    //DESTROY_SCORE is the score you get when this enemy get destroyed
    Enemy(Point v,Point p,double angle0,HitPoint* hit_point0,
          Graphic *graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    //do damge and return score
    int Hit(int damage);
    virtual void Fire(Game& my_game){}
private:
    int health;
    int HIT_SCORE;
    int DESTROY_SCORE;
};

#endif // ENEMY_H
