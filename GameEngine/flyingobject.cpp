#include "flyingobject.h"

FlyingObject::FlyingObject(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphics0):
    velocity(v),position(p),angle(angle0),hit_point(hit_point0),my_graphics(graphics0),destroyed(false)
{
    my_graphics->GetSignal(Graphic::CREATE);
}

FlyingObject::~FlyingObject()
{
    delete my_graphics;
}

void FlyingObject::Move(double time)
{
    position.x+=velocity.x*time;
    position.y+=velocity.y*time;
}

void FlyingObject::SetDestroy()
{
    destroyed=true;
    my_graphics->GetSignal(Graphic::DESTROY);
    Destroy();
}

bool IsColliding(FlyingObject *f1,FlyingObject *f2)
{
    double x=f1->position.x-f2->position.x,y=f1->position.y-f2->position.y,
            dis=f1->hit_point->max_distance+f2->hit_point->max_distance;
    if(x*x+y*y>=dis*dis)return false;
    for (vector<Circle>::iterator i=f1->hit_point->points.begin();i!=f1->hit_point->points.end();++i){
        Point tmp1(f1->position.x+i->x*cos(f1->angle)-i->y*sin(f1->angle),
                   f1->position.y+i->y*cos(f1->angle)+i->x*sin(f1->angle));
        for (vector<Circle>::iterator j=f2->hit_point->points.begin();j!=f2->hit_point->points.end();++j){
            Point tmp2(f2->position.x+j->x*cos(f2->angle)-j->y*sin(f2->angle),
                       f2->position.y+j->y*cos(f2->angle)+j->x*sin(f2->angle));
            double x=tmp1.x-tmp2.x,y=tmp1.y-tmp2.y,
                    dis=i->radius+j->radius;
            if(x*x+y*y<dis*dis)
                return true;
        }
    }
    return false;
}
