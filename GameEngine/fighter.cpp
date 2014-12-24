#include "fighter.h"
#include "game.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double Fighter::SPEED=50;
const double Fighter::BULLET_FREQUENCY=0.2;

Fighter::Fighter(Point v,Point p,HitPoint* hit_point0,
                 Graphic *graphic0,Player* player):
    FlyingObject(v,p,M_PI/2,hit_point0,graphic0),
    elapsed_time(0), bullet_level(1),missile_level(1),
    my_player(player),health(data.MAX_HEALTH),status(FLYING),bullet_time(100),my_bullet_type(YELLOW)
{
}

void Fighter::FighterMove(double time)
{
    Move(time);
    if (position.x<0)position.x=0;
    if (position.y<0)position.y=0;
    if (position.x+my_graphics->Size().x>data.PAINT_AREA_TOP_RIGHT.x)
        position.x=data.PAINT_AREA_TOP_RIGHT.x-my_graphics->Size().x;
    if (position.y+my_graphics->Size().y>data.PAINT_AREA_TOP_RIGHT.y)
        position.y=data.PAINT_AREA_TOP_RIGHT.y-my_graphics->Size().y;
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
    case ACTING:
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
                    BulletYellowGraphic *tmp=new BulletYellowGraphic();
                    my_game.FriendlyBulletRegister(
                        new Bullet(Point(0,200),
                        Point(position.x+(my_graphics->Size().x-tmp->Size().x)/2,position.y+my_graphics->Size().y),
                        M_PI/2,
                        &Bullet::yellow_bullet_hit_point,
                        tmp,
                        Bullet::NORMAL,
                        10,
                        my_player
                        ));
                    break;
                }
            }
        }
        if (my_player->my_control->BombValue()){
            //register bomb
        }
        //cout<<velocity.x<<" "<<velocity.y<<endl;
        break;
    }
}
