#ifndef BOSS2_H
#define BOSS2_H

#include "../GraphicEngine/boss2graphic.h"
#include "../GameEngine/enemy.h"

class Fighter;

extern HitPoint boss2_hitpoint;

class Boss2:public Enemy
{
public:
    Boss2(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Boss2Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0),stay_time(0),status(-1)
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
#endif // BOSS2_H
