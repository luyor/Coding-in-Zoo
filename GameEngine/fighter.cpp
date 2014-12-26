#include "fighter.h"
#include "game.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double Fighter::SPEED=100;
const double Fighter::BULLET_FREQUENCY=0.5;

Fighter::Fighter(Point v,Point p,HitPoint* hit_point0,
                 Graphic *graphic0,Player* player):
    FlyingObject(v,p,M_PI/2,hit_point0,graphic0),
    elapsed_time(0), bullet_level(4),missile_level(1),
    my_player(player),health(data.MAX_HEALTH),status(FLYING),bullet_time(100),my_bullet_type(YELLOW)
{
}

void Fighter::FighterMove(double time)
{
    Move(time);
    if (status!=FLYING){
        if (position.x<0)position.x=0;
        if (position.y<0)position.y=0;
        if (position.x+my_graphics->Size().x>data.PAINT_AREA_TOP_RIGHT.x)
            position.x=data.PAINT_AREA_TOP_RIGHT.x-my_graphics->Size().x;
        if (position.y+my_graphics->Size().y>data.PAINT_AREA_TOP_RIGHT.y)
            position.y=data.PAINT_AREA_TOP_RIGHT.y-my_graphics->Size().y;
    }
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
    bullet_time+=time;
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
        break;
    case ACTING:
        break;
    }
    if (status==BULLET_PROOF||status==ACTING){
        velocity=Point(0,0);
        //cout<<"in acting"<<endl;

        if (my_player->my_control->LeftPressed)velocity.x-=SPEED;
        if (my_player->my_control->RightPressed)velocity.x+=SPEED;
        if (my_player->my_control->DownPressed)velocity.y-=SPEED;
        if (my_player->my_control->UpPressed)velocity.y+=SPEED;
        if (my_player->my_control->FirePressed){
            if (bullet_time>BULLET_FREQUENCY){
                bullet_time=0;
                //cout<<"fire"<<endl;
                switch(my_bullet_type){
                case YELLOW:
                    FireYellowBullet(M_PI/2,my_game);
                    if (bullet_level>1){
                        FireYellowBullet(M_PI*5/12,my_game);
                        FireYellowBullet(M_PI*7/12,my_game);
                    }
                    if (bullet_level>2){
                        FireYellowBullet(M_PI*4/12,my_game);
                        FireYellowBullet(M_PI*8/12,my_game);
                    }
                    if (bullet_level>3){
                        FireYellowBullet(M_PI*3/12,my_game);
                        FireYellowBullet(M_PI*9/12,my_game);
                    }
                    break;
                }
            }
        }
        if (my_player->my_control->BombValue()){

        }
        //cout<<velocity.x<<" "<<velocity.y<<endl;

    }
}

void Fighter::Init()
{
    Circle tmp(30,30,30);
    fighter_hitpoint.AddCircle(tmp);
}

void Fighter::FireYellowBullet(double angle0,Game &my_game)
{
    BulletYellowGraphic *tmp=new BulletYellowGraphic();
    my_game.FriendlyBulletRegister(
        new Bullet(Point(200*cos(angle0),200*sin(angle0)),
        Point(position.x+(my_graphics->Size().x-tmp->Size().x)/2,position.y+my_graphics->Size().y),
        angle0,
        &yellow_bullet_hit_point,
        tmp,
        Bullet::NORMAL,
        10,
        my_player
        ));
}
