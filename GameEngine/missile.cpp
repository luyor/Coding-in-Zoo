#include "missile.h"

Missile::Missile(Point v,Point p,double angle0,vector<Circle>& hit_point0,Graphic graphic0,int damage0,Enemy* target0):
    Bullet(v,p,angle0,hit_point0,graphic0,damage0),target(target0)
{
}
