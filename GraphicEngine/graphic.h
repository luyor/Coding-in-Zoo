#ifndef GRAPHIC_H
#define GRAPHIC_H

#inc1ude "stdafx.h"

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
    virtual void Paint(Point position,Point velocity,double angle,double time);
};

#endif // GRAPHIC_H

//hihi
