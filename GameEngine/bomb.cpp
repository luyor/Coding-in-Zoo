#include "bomb.h"

const double Bomb::ATOMIC_FLYING_TIME=1;
const double Bomb::EXPLODE_TIME=1;

static HitPoint empty_hitpoint;
static HitPoint atomic_explode_hitpoint;
static HitPoint disperse_explode_hitpoint;

Bomb::Bomb(Point v,Point p,double angle0,Graphic *graphic0,double damage0,Player* belonging0):
    Bullet(v,p,angle0,&empty_hitpoint,graphic0,LASER,damage0,belonging0),
    status(FLYING),elapsed_time(0),flying_time(ATOMIC_FLYING_TIME)
{
}

Bomb::Bomb(Point v,Point p,double angle0,Graphic *graphic0,double damage0,Player* belonging0,double flying_time0):
    Bullet(v,p,angle0,&empty_hitpoint,graphic0,LASER,damage0,belonging0),
    status(FLYING),elapsed_time(0),flying_time(flying_time0)
{
}

void Bomb::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    switch(status){
    case FLYING:
        if (elapsed_time>flying_time){
            if (flying_time==ATOMIC_FLYING_TIME)
                hit_point=&atomic_explode_hitpoint;
            else
                hit_point=&disperse_explode_hitpoint;
            status=EXPLODE;
            elapsed_time=0;
            velocity=Point(0,0);
            my_graphics->GetSignal(Graphic::HIT);
        }
        break;
    case EXPLODE:
        if (elapsed_time>EXPLODE_TIME){
            SetDestroy();
        }
        break;
    }
}

void Bomb::Init()
{
    Circle tmp(0,0,125);
    atomic_explode_hitpoint.AddCircle(tmp);
    tmp=Circle(0,0,20);
    disperse_explode_hitpoint.AddCircle(tmp);
}
