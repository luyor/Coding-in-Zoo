#ifndef ITEM_H
#define ITEM_H

#include "flyingobject.h"

class Item : public FlyingObject
{
public:
    enum ItemType{
    }my_item_type;

    Item(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,enum ItemType type0);
    double elapsed_time;

    enum ItemType Hit(){SetDestroy();return my_item_type;}
    void ChangeStatus(double time, Game &my_game);
};

#endif // ITEM_H
