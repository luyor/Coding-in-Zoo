#ifndef ENEMY3_H
#define ENEMY3_H

#include "../GraphicEngine/enemy3graphic.h"
#include "../GameEngine/enemy.h"
#include "../res.h"

class Fighter;

extern HitPoint enemy3_hitpoint;

class Enemy3:public Enemy
{
public:
    Enemy3(Point v, Point p,double angle0,HitPoint* hit_point0,
           int health0,int HIT_SCORE0,int DESTROY_SCORE0):
        Enemy(v,p,angle0,hit_point0,new Enemy3Graphic(),health0,HIT_SCORE0,DESTROY_SCORE0),
        tar(NULL),
        sun(Point(data.PAINT_AREA_TOP_RIGHT.x * 0.75, data.PAINT_AREA_TOP_RIGHT.y))
    {
    }
    void ChangeStatus(double time, Game& my_game);
    void Fire(Game& my_game);
    static void Init();
    void Destroy();
private:
    Fighter* tar;
    Point sun;
};
#endif // ENEMY3_H
