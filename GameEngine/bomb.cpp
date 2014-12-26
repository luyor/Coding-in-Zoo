#include "bomb.h"

const int Bomb::FLYING_TIME=1;

static HitPoint empty_hitpoint;
static HitPoint explode_hitpoint;

Bomb::Bomb(Point v,Point p,double angle0,Graphic *graphic0,int damage0,Player* belonging0):
    Bullet(v,p,angle0,&empty_hitpoint,graphic0,LASER,damage0,belonging0),
    status(FLYING),elapsed_time(0)
{
}

void Bomb::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    switch(status){
    case FLYING:
        if (elapsed_time>FLYING_TIME){
            hit_point=&explode_hitpoint;
            status=EXPLODED;
        }
        break;
    case EXPLODE:
        status=EXPLODED;
        break;
    case EXPLODED:
        SetDestroy();
        break;
    }
}

void Bomb::Init()
{
    Circle tmp(50,50,50);
    explode_hitpoint.AddCircle(tmp);
}
