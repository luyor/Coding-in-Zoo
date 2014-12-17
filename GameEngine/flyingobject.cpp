#include "flyingobject.h"

FlyingObject::FlyingObject(Point v,Point p,double angle0,const HitPoint* hit_point0,Graphic graphics0):
    velocity(v),position(p),angle(angle0),hit_point(hit_point0),my_graphics(graphics0),destroyed(false)
{
    my_graphics.SendSignal(Graphic::Signal::CREATE);
}

void FlyingObject::Move(double time)
{
    position.x+=velocity.x*time;
    position.y+=velocity.y*time;
}

void FlyingObject::SetDestroy()
{
    destroyed=true;
    my_graphics.SendSignal(Graphic::Signal::DESTORY);
    Destroy();
}

bool IsColliding(FlyingObject f1,FlyingObject f2)
{
    double x=f1.position.x-f2.position.x,y=f1.position.y-f2.position.y,
            dis=f1.hit_point->max_distance+f2.hit_point->max_distance;
    if(x*x+y*y>=dis*dis)return false;
    for (vector<Circle>::iterator i=f1.hit_point->points.begin();i!=f1.hit_point->points.end();++i){
        for (vector<Circle>::iterator j=f2.hit_point->points.begin();j!=f2.hit_point->points.end();++j){
            double x=i->x-j->x,y=i->y-j->y,r=i->radius+j->radius;
            if (x*x+y*y<r*r)return true;
        }
    }
    return false;
}
