#include "item.h"

const double Item::CHANGE_TIME=3;
const double Item::CHANGE_VELOCITY_TIME=1;
const double Item::SPEED=30;
const double Item::DOWN_SPEED=10;

HitPoint item_hitpoint;

Item::Item(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,enum ItemType type0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),my_item_type(type0),elapsed_time(0),velocity_time(0)
{
    double a=M_PI*(rand()%10000)/5000;
    velocity.x=cos(a)*SPEED;
    velocity.y=sin(a)*SPEED-DOWN_SPEED;
}

void Item::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    velocity_time+=time;
    if (velocity_time>CHANGE_VELOCITY_TIME){
        velocity_time=0;
        double a=M_PI*(rand()%10000)/5000;
        velocity.x=cos(a)*SPEED;
        velocity.y=sin(a)*SPEED-DOWN_SPEED;
    }
    
    switch(my_item_type){
    case YELLOW_BULLET:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=BLUE_BULLET;
            elapsed_time=0;
            my_graphics->GetSignal(Graphic::HIT);
        }
        break;
    case BLUE_BULLET:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=PURPLE_BULLET;
            elapsed_time=0;
            my_graphics->GetSignal(Graphic::HIT);
        }
        break;
    case PURPLE_BULLET:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=YELLOW_BULLET;
            elapsed_time=0;
            my_graphics->GetSignal(Graphic::HIT);
        }
        break;
    case TRACKING_MISSILE:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=STRAIGHT_MISSILE;
            elapsed_time=0;
        }
        break;
    case STRAIGHT_MISSILE:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=TRACKING_MISSILE;
            elapsed_time=0;
        }
        break;
    case ATOMIC_BOMB:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=DISPERSE_BOMB;
            elapsed_time=0;
        }
        break;
    case DISPERSE_BOMB:
        if (elapsed_time>CHANGE_TIME){
            my_item_type=ATOMIC_BOMB;
            elapsed_time=0;
        }
        break;
    case ADD_SCORE_100:
        break;
    case ADD_SCORE_1000:
        break;
    case ADD_LIFE:
        break;
    }
}

void Item::Init()
{
    Circle tmp(0,0,10);
    item_hitpoint.AddCircle(tmp);
}
