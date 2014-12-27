#ifndef BOMB_H
#define BOMB_H

#include "bullet.h"

//send HIT paint message when explode
class Bomb:public Bullet
{
public:
    Bomb(Point v,Point p,double angle0,Graphic *graphic0,int damage0,Player* belonging0);
    //change status if explode then destroy
    void ChangeStatus(double time, Game &my_game);
    static void Init();
private:
    enum {
        FLYING,
        EXPLODE,
        EXPLODED
    }status;
    int elapsed_time;

    static const double FLYING_TIME;
    static const double EXPLODE_TIME;
};

#endif // BOMB_H
