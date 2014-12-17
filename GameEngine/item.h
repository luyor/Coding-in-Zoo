#ifndef ITEM_H
#define ITEM_H

#include "flyingobject.h"

class Item : public FlyingObject
{
public:
    enum ItemType{
    }my_item_type;
    Item(Point v,Point p,double angle0,vector<Circle>& hit_point0,Graphic graphic0,enum ItemType type0);
};

#endif // ITEM_H
