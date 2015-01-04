#include "fighter.h"
#include "game.h"
#include "res.h"

HitPoint fighter_hitpoint;

const double Fighter::SPEED=100;
const double Fighter::YELLOW_BULLET_FREQUENCY=0.1;
const double Fighter::YELLOW_BULLET_STOP=0.3;
const int Fighter::YELLOW_BULLET_NUMBER=4;
const double Fighter::BLUE_BULLET_FREQUENCY=0.1;
const double Fighter::PURPLE_BULLET_FREQUENCY=0.03;
const double Fighter::MISSILE_FREQUENCY[]={0,1,0.83,0.69,0.57};
const double Fighter::FLYING_TIME=1;
const double Fighter::BULLET_PROOF_TIME=1;
const double Fighter::MAX_BULLET_LEVEL=4;
const double Fighter::MAX_MISSILE_LEVEL=4;
const double Fighter::MAX_BOMB_NUMBER=6;
const int Fighter::DISPERSE_BOMB_NUMBER=50;

Fighter::Fighter(Point v,Point p,HitPoint* hit_point0,
                 Graphic *graphic0,Player* player):
    FlyingObject(v,p,M_PI/2,hit_point0,graphic0),
    elapsed_time(0), bullet_level(1),missile_level(0),
    my_player(player),health(data.MAX_HEALTH),status(FLYING),bullet_time(100),my_bullet_type(PURPLE),
    missile_time(100),my_missile_type(TRACKING),bullet_count(0)
{
    for (int i=0;i<6;++i){
        bomb_list.push_back(DISPERSE);
    }
}

void Fighter::FighterMove(double time)
{
    Move(time);
    if (status!=FLYING){
        if (position.x<my_graphics->Size().x/2)position.x=my_graphics->Size().x/2;
        if (position.y<my_graphics->Size().y/2)position.y=my_graphics->Size().y/2;
        if (position.x>data.PAINT_AREA_TOP_RIGHT.x-my_graphics->Size().x/2)
            position.x=data.PAINT_AREA_TOP_RIGHT.x-my_graphics->Size().x/2;
        if (position.y>data.PAINT_AREA_TOP_RIGHT.y-my_graphics->Size().y/2)
            position.y=data.PAINT_AREA_TOP_RIGHT.y-my_graphics->Size().y/2;
    }
}

void Fighter::Hit(double damage)
{
    my_graphics->GetSignal(Graphic::HIT);
    health-=damage;
    //cout<<health<<endl;
    if (health<=0)
        SetDestroy();
}

void Fighter::Destroy()
{
    my_player->LoseLife();
    //add score
}

int Fighter::Crush()
{
    SetDestroy();
    return data.CRUSH_DAMAGE;
}

void Fighter::GetItem(enum Item::ItemType type)
{
    switch(type){
    case Item::YELLOW_BULLET:
        if (my_bullet_type==YELLOW&&bullet_level<MAX_BULLET_LEVEL){
            ++bullet_level;        
        }else my_bullet_type=YELLOW;
        break;
    case Item::BLUE_BULLET:
        if (my_bullet_type==BLUE&&bullet_level<MAX_BULLET_LEVEL){
            ++bullet_level;
        }else my_bullet_type=BLUE;
        break;
    case Item::PURPLE_BULLET:
        if (my_bullet_type==PURPLE&&bullet_level<MAX_BULLET_LEVEL){
            ++bullet_level;
        }else my_bullet_type=PURPLE;
        break;
    case Item::TRACKING_MISSILE:
        if (my_missile_type==TRACKING&&missile_level<MAX_MISSILE_LEVEL){
            ++missile_level;
        }else my_missile_type=TRACKING;
        break;
    case Item::STRAIGHT_MISSILE:
        if (my_missile_type==STRAIGHT&&missile_level<MAX_MISSILE_LEVEL){
            ++missile_level;
        }else my_missile_type=STRAIGHT;
        break;
    case Item::ATOMIC_BOMB:
        if (bomb_list.size()<MAX_BOMB_NUMBER){
            bomb_list.push_back(ATOMIC);
        }
        break;
    case Item::DISPERSE_BOMB:
        if (bomb_list.size()<MAX_BOMB_NUMBER){
            bomb_list.push_back(DISPERSE);
        }
        break;
    case Item::ADD_SCORE_100:
        AddScore(10);
        break;
    case Item::ADD_SCORE_1000:
        AddScore(100);
        break;
    case Item::ADD_LIFE:
        my_player->IncreaseLife();
        break;
    }
}

void Fighter::ChangeStatus(double time, Game &my_game)
{
    elapsed_time+=time;
    bullet_time+=time;
    missile_time+=time;
    switch (status){
    case FLYING:
        if (elapsed_time>FLYING_TIME){
            status=BULLET_PROOF;
            velocity=Point(0,0);
            elapsed_time=0;
        }
        break;
    case BULLET_PROOF:
        if (elapsed_time>BULLET_PROOF_TIME){
            status=ACTING;
            elapsed_time=0;
        }
        break;
    case ACTING:
        break;
    }

    if (status==BULLET_PROOF||status==ACTING){
        //cout<<"in acting"<<endl;
        velocity=Point(0,0);
        if (my_player->my_control->LeftPressed)velocity.x-=SPEED;
        if (my_player->my_control->RightPressed)velocity.x+=SPEED;
        if (my_player->my_control->DownPressed)velocity.y-=SPEED;
        if (my_player->my_control->UpPressed)velocity.y+=SPEED;
        if (my_player->my_control->FirePressed){
            double bullet_frequency;
            switch(my_bullet_type){
            case YELLOW:
                if (bullet_count==YELLOW_BULLET_NUMBER){
                    bullet_frequency=YELLOW_BULLET_STOP;
                }else {
                    bullet_frequency=YELLOW_BULLET_FREQUENCY;
                }
                break;
            case BLUE:
                bullet_frequency=BLUE_BULLET_FREQUENCY;
                break;
            case PURPLE:
                bullet_frequency=PURPLE_BULLET_FREQUENCY;
                break;
            }
            
            if (bullet_time>bullet_frequency){
                if (bullet_time>YELLOW_BULLET_STOP)
                    bullet_count=1;
                else if (my_bullet_type==YELLOW)    
                    ++bullet_count;
                bullet_time=0;
                switch(my_bullet_type){
                case YELLOW:
                    emit graphic_engine.PlaySoundBulletYellow();
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
                case BLUE:
                    emit graphic_engine.PlaySoundBulletBlue();
                    FireBlueBullet(0,my_game);
                    if (bullet_level>1){
                        FireBlueBullet(1,my_game);
                        FireBlueBullet(-1,my_game);
                    }
                    if (bullet_level>2){
                        FireBlueBullet(2,my_game);
                        FireBlueBullet(-2,my_game);
                    }
                    if (bullet_level>3){
                        FireBlueBullet(3,my_game);
                        FireBlueBullet(-3,my_game);
                    }
                    break;
                 case PURPLE:
                    emit graphic_engine.PlaySoundBulletPurple();
                    FirePurpleBullet(1,my_game);
                    break;
                }
            }
        }
        if (missile_level>0&&missile_time>MISSILE_FREQUENCY[missile_level]){
            switch(my_missile_type){
            case TRACKING:
                FireTrackingMissile(my_game,Point(position.x+my_graphics->Size().x/2,position.y));
                FireTrackingMissile(my_game,Point(position.x-my_graphics->Size().x/2,position.y));
                break;
            case STRAIGHT:
                FireStraightMissile(my_game,Point(position.x+my_graphics->Size().x/2,position.y));
                FireStraightMissile(my_game,Point(position.x-my_graphics->Size().x/2,position.y));
                break;
            }
            missile_time=0;
        }
        if (my_player->my_control->BombValue()){
            if (!bomb_list.empty()){
                vector<BombType>::iterator it=bomb_list.end()-1;
                switch(*it){
                case ATOMIC:
                    FireAtomicBomb(my_game);
                    break;
                case DISPERSE:
                    FireDisperseBomb(my_game);
                    break;
                }
                bomb_list.erase(it);
            }
        }
        //cout<<velocity.x<<" "<<velocity.y<<endl;

    }
}

void Fighter::Init()
{
    Circle tmp(0,0,30);
    fighter_hitpoint.AddCircle(tmp);
}

void Fighter::FireYellowBullet(double angle0,Game &my_game)
{
    BulletYellowGraphic *tmp=new BulletYellowGraphic();
    my_game.FriendlyBulletRegister(
        new Bullet(Point(200*cos(angle0),200*sin(angle0)),
        Point(position.x,position.y+my_graphics->Size().y/2),
        angle0,
        &yellow_bullet_hitpoint,
        tmp,
        Bullet::NORMAL,
        10,
        my_player
        ));
}

void Fighter::FireBlueBullet(int k,Game &my_game)
{
    BulletBlueGraphic *tmp=new BulletBlueGraphic();
    my_game.FriendlyBulletRegister(
        new Bullet(Point(0,300),
        Point(position.x+k*tmp->Size().x,position.y+my_graphics->Size().y/2),
        M_PI/2,
        &blue_bullet_hitpoint,
        tmp,
        Bullet::NORMAL,
        10,
        my_player
        ));
}

void Fighter::FirePurpleBullet(int k,Game &my_game)
{
    BulletPurpleGraphic *tmp=new BulletPurpleGraphic();
    my_game.FriendlyBulletRegister(
        new Missile(500,
        Point(0,500),
        Point(position.x,position.y+my_graphics->Size().y/2),
        M_PI/2,
        &blue_bullet_hitpoint,
        tmp,
        1,
        my_player,
        M_PI*4,
        1000
        ));
}

void Fighter::FireAtomicBomb(Game &my_game)
{
    BombAtomicGraphic *tmp=new BombAtomicGraphic();
    my_game.BombRegister(
        new Bomb(Point(0,150),
        Point(position.x,position.y+my_graphics->Size().y/2),
        M_PI/2,
        tmp,
        100,
        my_player
        ));
}

void Fighter::FireTrackingMissile(Game &my_game,Point p)
{
    MissileGraphic *tmp=new MissileGraphic();
    my_game.FriendlyBulletRegister(
        new Missile(200,
        p,
        M_PI/2,
        &yellow_bullet_hitpoint,
        tmp,
        10,
        my_player,
        M_PI*4,
        1000
        ));
}

void Fighter::FireStraightMissile(Game &my_game,Point p)
{
    MissileGraphic *tmp=new MissileGraphic();
    my_game.FriendlyBulletRegister(
        new Bullet(Point(0,200),
        p,
        M_PI/2,
        &blue_bullet_hitpoint,
        tmp,
        Bullet::NORMAL,
        10,
        my_player
        ));
}

void Fighter::FireDisperseBomb(Game &my_game)
{
    for (int i=0;i<DISPERSE_BOMB_NUMBER;++i){
        double a=2*M_PI*i/DISPERSE_BOMB_NUMBER;
        BombDisperseGraphic *tmp=new BombDisperseGraphic();
        my_game.BombRegister(
            new Bomb(Point(150*cos(a),150*sin(a)),
            Point(position.x+cos(a)*my_graphics->Size().x/2,position.y+sin(a)*my_graphics->Size().y/2),
            a,
            tmp,
            10,
            my_player,
            (rand()%800+200.0)/1000
            ));
    }
}
