#ifndef ENEMY4_H
#define ENEMY4_H

#include "../GraphicEngine/enemy4graphic.h"
#include "../GameEngine/enemy.h"

class Fighter;

extern HitPoint enemy4_hitpoint;

class Enemy4:public Enemy
{
public:
    Enemy4(Point v, Point p,double angle0,HitPoint* hit_point0,int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,new Enemy4Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),
        tar(NULL),suicideangle(0)
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
    void Destroy();
private:
    Fighter* tar;
    double suicideangle;
};
#endif // ENEMY4_H
