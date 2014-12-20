#ifndef ENEMY_H
#define ENEMY_H

#include "flyingobject.h"

class Game;

class Enemy:public FlyingObject
{
public:
    //Point v is velocity
    //Point p is position
    //angle0 is set to be -pi/2 when heading down
    //hit_point0 is used for collision
    //graphic0 ***
    //health0 is the "health" at very first beginning
    //HIT_SCORE0 is the number of score you get when you hit it
    //DESTROY_SCORE0 is the number of score you get when you destory it
    Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
          Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    //do damge and return score
    //enemy was hit, use Hit();
    int Hit(int damage);
//    virtual void Fire(Game& my_game);
private:
    int health;
    int HIT_SCORE;
    int DESTROY_SCORE;
};

#endif // ENEMY_H
