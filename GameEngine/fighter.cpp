#include "fighter.h"

Fighter::Fighter(Point v,Point p,HitPoint* hit_point0,
                 Graphic *graphic0,Player* player):
    FlyingObject(v,p,M_PI/2,hit_point0,graphic0),
    elapsed_time(0), bullet_level(1),missile_level(1),
    my_player(player),health(data.MAX_HEALTH)
{
}

void Fighter::FighterMove(double time,Point visible_area,Point fighter_size)
{
    //cout<<position.x<<"++"<<position.y<<endl;
    Move(time);
    if (position.x<0)position.x=0;
    if (position.y<0)position.y=0;
    if (position.x+fighter_size.x>visible_area.x)position.x=visible_area.x-fighter_size.x;
    if (position.y+fighter_size.y>visible_area.y)position.y=visible_area.y-fighter_size.y;
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

void Fighter::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    switch (status){
    case FLYING:
        if (elapsed_time>1){
            status=BULLET_PROOF;
            velocity=Point(0,0);
            elapsed_time=0;
        }
        break;
    case BULLET_PROOF:
        if (elapsed_time>1){
            status=ACTING;
            elapsed_time=0;
        }
    case ACTING:
        velocity=Point(0,0);
        /*
        if (my_player->my_control->LeftPressed())velocity.x-=SPEED;
        if (my_player->my_control->RightPressed())velocity.x+=SPEED;
        if (my_player->my_control->DownPressed())velocity.y-=SPEED;
        if (my_player->my_control->UpPressed())velocity.x+=SPEED;
        if (my_player->my_control->BulletPressed()){
            //register bullet
        }
        if (my_player->my_control->BombClicked()){
            //register bomb
        }*/
        break;
    }
}
