#ifndef ENEMY1_H
#define ENEMY1_H

#include "../GameEngine/enemy.h"
#include "../GameEngine/fighter.h"
#include "../GraphicEngine/enemy1graphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double max_turn_angle = M_PI / 72.0;
const double DELTA = 0.0001;

const double SLOW_BULLET = 50;
const double NORMAL_BULLET = 100;
const double FAST_BULLET = 150;

extern HitPoint enemy1_hitpoint;

class Enemy1:public Enemy
{
public:
    Enemy1(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Enemy1Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
private:
    Fighter* tar;
    double fire_time;
};
#endif // ENEMY1_H
