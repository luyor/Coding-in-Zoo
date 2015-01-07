#ifndef BOSS1_H
#define BOSS1_H

#include "../GraphicEngine/boss1graphic.h"
#include "../GraphicEngine/enemy3graphic.h"
#include "../GameEngine/enemy.h"

class Fighter;

extern HitPoint boss1_hitpoint;

class Boss1:public Enemy
{
public:
    Boss1(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Boss1Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0),stay_time(0),status(-1)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
    void Destroy();
private:
    Fighter* tar;
    int status;
    //-1 for coming for fight
    //0 for enemy2-like shooting
    //1 for dashing
    //2 for fast strafe
    double fire_time;
    double stay_time;
};
#endif // BOSS1_H
