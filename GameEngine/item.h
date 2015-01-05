#ifndef ITEM_H
#define ITEM_H

#include "flyingobject.h"

extern HitPoint item_hitpoint;

class Item : public FlyingObject
{
public:
    enum ItemType{
        YELLOW_BULLET,
        BLUE_BULLET,
        PURPLE_BULLET,
        TRACKING_MISSILE,
        STRAIGHT_MISSILE,
        ATOMIC_BOMB,
        DISPERSE_BOMB,
        ADD_SCORE_100,
        ADD_SCORE_1000,
        ADD_LIFE
    }my_item_type;

    Item(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,enum ItemType type0);
    double elapsed_time,velocity_time;

    enum ItemType Hit(){SetDestroy();return my_item_type;}
    void ChangeStatus(double time, Game &my_game);
    static void Init();
private:
    static const double CHANGE_TIME;
    static const double SPEED;
    static const double DOWN_SPEED;
    static const double CHANGE_VELOCITY_TIME;
};

#endif // ITEM_H
