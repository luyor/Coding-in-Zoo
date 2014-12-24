#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "../stdafx.h"
#include "../General/point.h"

class Graphic
{
public:
    Graphic();
    enum Signal{
        CREATE=0,
        HIT,
        DESTROY,
        NO_SIGNAL
    }sig;
    void GetSignal(enum Signal s);
    double elapsed_time;
    bool finish;
    bool DestroyFinished();        //death animation finish
    virtual Point Size(){}
    virtual void Paint(Point position,Point velocity,double angle,double time){cout<<"wrong paint"<<endl;}
};

#endif // GRAPHIC_H

//hihi
