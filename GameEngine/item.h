#ifndef ITEM_H
#define ITEM_H

#include "flyingobject.h"

class Item : public FlyingObject
{
public:
    enum ItemType{
    }my_item_type;

    Item(Point v,Point p,double angle0,const HitPoint* hit_point0,Graphic graphic0,enum ItemType type0);
    double elapsed_time;

    enum ItemType Hit(){SetDestroy();return my_item_type;}
};

#endif // ITEM_H
