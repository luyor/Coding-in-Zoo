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
private:
    enum {
        FLYING,
        EXPLODED
    }status;
    int elapsed_time;

};

#endif // BOMB_H
