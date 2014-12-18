#include "item.h"

Item::Item(Point v,Point p,double angle0,vector<Circle>& hit_point0,Graphic graphic0,enum ItemType type0):
    FlyingObject(v,p,angle0,hit_point0,graphic0),my_item_type(type0),elapsed_time(0)
{
}
