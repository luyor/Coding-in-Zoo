#ifndef ENEMY2_H
#define ENEMY2_H

#include "../GraphicEngine/enemy2graphic.h"
#include "../GameEngine/enemy.h"

const double max_turn_angle = M_PI / 72.0;
const double DELTA = 0.0001;

const double SPEED = 25;
const double SLOW_BULLET = 105;
const double NORMAL_BULLET = 120;
const double FAST_BULLET = 150;

class Fighter;

extern HitPoint enemy2_hitpoint;

class Enemy2:public Enemy
{
public:
    Enemy2(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Enemy2Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
    void Destroy();
private:
    Fighter* tar;
    double fire_time;
};
#endif // ENEMY2_H
