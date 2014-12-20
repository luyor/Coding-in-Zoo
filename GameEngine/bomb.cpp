#include "bomb.h"

static vector<Circle> empty_hit_point;

Bomb::Bomb(Point v,Point p,double angle0,Graphic graphic0,int damage0,Player* belonging0):
    Bullet(v,p,angle0,empty_hit_point,graphic0,LASER,damage0,belonging0),
    status(FLYING),elapsed_time(0)
{
}

void Bomb::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    switch(status){
    case FLYING:
        if (elapsed_time>FLYING_TIME){
            //change hitpoint
            status=EXPLODED;
        }
        break;
    case EXPLODED:
        SetDestroy();
        break;
    }
}
