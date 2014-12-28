#ifndef BOMB_H
#define BOMB_H

#include "bullet.h"

//send HIT paint message when explode
class Bomb:public Bullet
{
public:
    //atomic bomb
    Bomb(Point v,Point p,double angle0,Graphic *graphic0,double damage0,Player* belonging0);
    //disperse bomb
    Bomb(Point v,Point p,double angle0,Graphic *graphic0,double damage0,Player* belonging0,double flying_time0);
    //change status if explode then destroy
    void ChangeStatus(double time, Game &my_game);
    static void Init();
    bool IsExplode(){return status==EXPLODE;}
private:
    enum {
        FLYING,
        EXPLODE
    }status;
    double elapsed_time;
    double flying_time;

    static const double ATOMIC_FLYING_TIME;
    static const double EXPLODE_TIME;
};

#endif // BOMB_H
