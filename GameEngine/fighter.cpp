#include "fighter.h"

Fighter::Fighter(Point v,Point p,vector<Circle>& hit_point0,
                 Graphic graphic0,Player* player):
    FlyingObject(v,p,M_PI/2,hit_point0,graphic0),
    elapsed_time(0), bullet_level(1),missile_level(1),
    my_player(player),health(data.MAX_HEALTH)
{
}

void Fighter::FighterMove(double time,Point visible_area,Point fighter_size)
{
    Move(time);
    if (position.x<0)position.x=0;
    if (position.y<0)position.y=0;
    if (position.x+fighter_size.x>visible_area.x)position.x=visible_area.x;
    if (position.y+fighter_size.y>visible_area.y)position.y=visible_area.y;
}

void Fighter::Hit(int damage)
{
    health-=damage;
    if (health<=0){
        my_player->LoseLife();
        SetDestroy();
    }
}

void Fighter::Destroy()
{
    //add score
    if (!my_player->IsDead()){
        //register new fighter
    }
}

int Fighter::Crush()
{
    SetDestroy();
    return data.CRUSH_DAMAGE;
}

void Fighter::GetItem(enum Item::ItemType type){

}
