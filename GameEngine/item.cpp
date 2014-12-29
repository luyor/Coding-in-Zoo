#include "item.h"

const double Item::CHANGE_TIME=3;

HitPoint item_hitpoint;

Item::Item(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,enum ItemType type0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),my_item_type(type0),elapsed_time(0)
{
}

void Item::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
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
