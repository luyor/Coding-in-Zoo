#ifndef BOSS3_H
#define BOSS3_H

#include "../GraphicEngine/boss3graphic.h"
//After finish, Enemy1Graphic() should be changed as
//../GraphicEngine/boss3Graphic.h
#include "../GameEngine/enemy.h"

class Fighter;

extern HitPoint boss3_hitpoint;

class Boss3:public Enemy
{
public:
    Boss3(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,
            new Boss3Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),tar(NULL),fire_time(0),stay_time(0),status(-1)
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
    //0 for rolling and fight
    double fire_time;
    double stay_time;
};
#endif // BOSS3_H
