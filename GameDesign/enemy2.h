#ifndef ENEMY2_H
#define ENEMY2_H

#include "../GameEngine/enemy.h"
#include "design.h"

const double DELTA = 0.0001;
const double max_turn_angle = DELTA;

class Enemy1:public Enemy
{
public:
    Enemy1(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
            Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
private:
};
#endif // ENEMY2_H
