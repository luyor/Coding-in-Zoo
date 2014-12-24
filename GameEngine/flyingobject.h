#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "../stdafx.h"
#include "../General/point.h"
#include "../General/circle.h"
#include "../General/hitpoint.h"
#include "../GraphicEngine/graphic.h"

class Game;

class FlyingObject
{
public:
    FlyingObject(Point v,Point p,double angle0,HitPoint* hit_point0,Graphic *graphics0);
    ~FlyingObject();
    void SetDestroy();//actual destroy
    bool IsDestroyed(){return destroyed;}//used to check collision
    bool IsFinish(){return my_graphics->DestroyFinished();}//used to clean object
    virtual void ChangeStatus(double time,Game& my_game){}//change velocity,position,angle
    void Move(double time);
    Point GetVelocity(){return velocity;}
    Point GetPosition(){return position;}
    double GetAngle(){return angle;}
    void Paint(double time){my_graphics->Paint(position,velocity,angle,time);}
protected:
    bool destroyed;
    Point velocity;
    Point position;
    double angle;
    HitPoint* hit_point;
    Graphic *my_graphics;

    virtual void Destroy(){}//virtual destroy

    friend bool IsColliding(FlyingObject *i,FlyingObject *j);
};

#endif // FLYINGOBJECT_H
