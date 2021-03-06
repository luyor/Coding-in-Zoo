#ifndef ENEMY1_H
#define ENEMY1_H

#include "../GraphicEngine/enemy1graphic.h"
#include "../GameEngine/enemy.h"

class Fighter;

extern HitPoint enemy1_hitpoint;

class Enemy1:public Enemy
{
public:
    Enemy1(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Enemy1Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0),stay_time(0)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
    void Destroy();
private:
    Fighter* tar;
    double fire_time;
    int stay_time;
};
#endif // ENEMY1_H
