#include "game.h"
#include "../res.h"
#include "../GameDesign/enemy1.h"

Point Game::FIGHTER1_INIT_POSITION=Point(200,-50);
Point Game::FIGHTER2_INIT_POSITION=Point(400,-50);
Point Game::FIGHTER_INIT_VELOCITY=Point(0,200);

Game::Game():player0(NULL),player1(NULL),WELCOME(true)
{
    Init();
}

void Game::Init()
{
    Bullet::Init();
    Bomb::Init();
    Enemy::Init();
    Fighter::Init();
    Item::Init();
    Missile::Init();
    Enemy::Init();
}

void Game::Start(enum GameMode game_mode,int coins0)
{   
    if (player0!=NULL)delete player0;
    if (player1!=NULL)delete player1;
    player0=new Player(data.MAX_LIFE,&control);
    player1=new Player(data.MAX_LIFE,&control2);

    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        delete (*it);
    }
    friendly_bullets.clear();
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        delete (*it);
    }
    enemy_bullets.clear();
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        delete (*it);
    }
    fighters.clear();
    for(vector<Enemy*>::iterator it=enemies.begin();it!=enemies.end();++it){
        delete (*it);
    }
    enemies.clear();
    for(vector<Bomb*>::iterator it=bombs.begin();it!=bombs.end();++it){
        delete (*it);
    }
    bombs.clear();
    for(vector<Item*>::iterator it=items.begin();it!=items.end();++it){
        delete (*it);
    }
    items.clear();

    design.Reset();

    Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,&fighter_hitpoint,new Fighter1Graphic(),player0);

    FighterRegister(tmp);
    
    player0->START=true;
    if(game_mode==COOP){
        tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,&fighter_hitpoint,new Fighter1Graphic(),player1);
        player1->START=true;
        FighterRegister(tmp);
    }
    
    background_position=0;
    coins=coins0;
    WELCOME=false;
    PAUSED=false;
    END=false;
    status=MISSION_START;
}

void Game::GameLoop()
{
    while(!END){
        if (WELCOME){
        }
        else if (IsPaused()){
            graphics_time.start();
            physics_time.start();
        }else {
            switch(status){
            case MISSION_START:
                emit graphic_engine.PlaySoundBGM();
                graphic_engine.MissionStart(0);
                status=MISSION_ON;
                graphics_time.start();
                physics_time.start();
                break;
            case MISSION_ON:{
                double time=(double)physics_time.restart()/1000;
                AllChangeStatus(time);
                design.NewEnemy(*this,background_position);
                AllCheckCollision(time);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);

                    //Missile *t=new Missile(50,Point(500,500),AimAt(Point(600,600),SelectRandomFighter()->GetPosition()),
                    //                       &yellow_bullet_hitpoint,new MissileGraphic(),0,M_PI/4,M_PI*500);
                    //EnemyBulletRegister(t);
                }
                AllClean();
                if (design.MissionFinish()&&enemies.empty()&&enemy_bullets.empty()){
                    status=MISSION_END;
                }
                break;
            }
            case MISSION_END:
                graphic_engine.MissionComplete(0);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    double time=(double)graphics_time.restart()/1000;
                    graphic_engine.PaintBackground(time);
                    graphic_engine.MissionComplete(time);
                    if (graphic_engine.MissionCompleteFinish()){
                        design.NextMission();
                        status=MISSION_START;
                    }
                }
                break;
           }
       }
    }
}

void Game::FighterRegister(Fighter* fighter)
{
    fighters.push_back(fighter);
}

void Game::EnemyRegister(Enemy* enemy)
{
    enemies.push_back(enemy);
}

void Game::FriendlyBulletRegister(Bullet* bullet)
{
    friendly_bullets.push_back(bullet);
}

void Game::EnemyBulletRegister(Bullet* bullet)
{
    enemy_bullets.push_back(bullet);
}

void Game::BombRegister(Bomb* bomb)
{
    bombs.push_back(bomb);
}

void Game::ItemRegister(Item* item)
{
    items.push_back(item);
}

void Game::AllChangeStatus(double time)
{
    if (background_position<(1e50)){
        background_position+=time*data.BACKGROUND_SPEED;
    }
    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->Move(time);
        }
    }
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->Move(time);
        }
    }
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->FighterMove(time);
        }
    }
    for(vector<Enemy*>::iterator it=enemies.begin();it!=enemies.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->Move(time);
        }
    }
    for(vector<Bomb*>::iterator it=bombs.begin();it!=bombs.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->Move(time);
        }
    }
    for(vector<Item*>::iterator it=items.begin();it!=items.end();++it){
        if (!(*it)->IsDestroyed()){
            (*it)->ChangeStatus(time,*this);
            (*it)->Move(time);
        }
    }
}

void Game::AllCheckCollision(double time)
{
    //friendly bullet collide enemy
    for (vector<Bullet*>::iterator i=friendly_bullets.begin();i!=friendly_bullets.end();++i){
        for (vector<Enemy*>::iterator j=enemies.begin();j!=enemies.end();++j){
            if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j)){
                (*i)->AddScore((*j)->Hit((*i)->Hit(time)));
                //i->Hit return damage,j->Hit return score
            }
        }
    }

    //enemy bullet collide fighter
    for (vector<Fighter*>::iterator i=fighters.begin();i!=fighters.end();++i){
        if ((*i)->IsActing()){   
            for (vector<Bullet*>::iterator j=enemy_bullets.begin();j!=enemy_bullets.end();++j){
                if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j)){
                    //cout<<"collide"<<endl;
                    (*i)->Hit((*j)->Hit(time));
                    //i->Hit return score,j->Hit return damage
                }
            }
        }
    }

    //enemy bullet collide bomb
    for (vector<Bomb*>::iterator i=bombs.begin();i!=bombs.end();++i){
        if ((*i)->IsExplode()){
            for (vector<Bullet*>::iterator j=enemy_bullets.begin();j!=enemy_bullets.end();++j){
                if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j))
                    (*j)->SetDestroy();
            }
        }
    }

    //fighter collide enemy
    for (vector<Fighter*>::iterator i=fighters.begin();i!=fighters.end();++i){
        if ((*i)->IsActing()){
            for (vector<Enemy*>::iterator j=enemies.begin();j!=enemies.end();++j){
                if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j)){
                    (*i)->AddScore((*j)->Hit((*i)->Crush()));
                    //i->Crush return damage,j->Hit return score
                }
            }
        }
    }

    //fighter collide item
    for (vector<Fighter*>::iterator i=fighters.begin();i!=fighters.end();++i){
        for (vector<Item*>::iterator j=items.begin();j!=items.end();++j){
            if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j))
                (*i)->GetItem((*j)->Hit());
        }
    }

    //Enemy collide bomb
    for (vector<Bomb*>::iterator i=bombs.begin();i!=bombs.end();++i){
        if ((*i)->IsExplode()){
            for (vector<Enemy*>::iterator j=enemies.begin();j!=enemies.end();++j){
                if(!(*i)->IsDestroyed()&&!(*j)->IsDestroyed()&&IsColliding(*i,*j)){
                    (*i)->AddScore((*j)->Hit((*i)->Hit(time)));
                }
            }
        }
    }

}

void Game::AllPaint(double time)
{
    graphic_engine.pics_to_show.clear();
    graphic_engine.PaintBackground(background_position);
    Fighter *tmp0=NULL,*tmp1=NULL;
    for (vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        if(!(*it)->IsDestroyed()){
            if ((*it)->GetPlayer()==player0)tmp0=*it;
            if ((*it)->GetPlayer()==player1)tmp1=*it;
        }
    }
    graphic_engine.PaintForeground(tmp0,tmp1);
    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        (*it)->Paint(time);
    }
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        (*it)->Paint(time);
    }
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        (*it)->Paint(time);
    }
    for(vector<Enemy*>::iterator it=enemies.begin();it!=enemies.end();++it){
        (*it)->Paint(time);
    }
    for(vector<Bomb*>::iterator it=bombs.begin();it!=bombs.end();++it){
        (*it)->Paint(time);
    }
    for(vector<Item*>::iterator it=items.begin();it!=items.end();++it){
        (*it)->Paint(time);
    }
    emit graphic_engine.Update();
}

void Game::AllClean()
{
    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
         if ((*it)->DestroyFinished()||
                 (*it)->GetPosition().x<data.GAME_AREA_BOTTOM_LEFT.x||
                 (*it)->GetPosition().y<data.GAME_AREA_BOTTOM_LEFT.y||
                 (*it)->GetPosition().x>data.GAME_AREA_TOP_RIGHT.x||
                 (*it)->GetPosition().y>data.GAME_AREA_TOP_RIGHT.y){
             delete (*it);
             friendly_bullets.erase(it);
         }
         if(it==friendly_bullets.end())
             break;
    }
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        if ((*it)->DestroyFinished()){
            Player* p=(*it)->GetPlayer();
            delete (*it);
            fighters.erase(it);
            if (!p->IsDead()){
                Fighter *f=new Fighter(Point(0,200),Point(300,-50),&fighter_hitpoint,new Fighter1Graphic(),p);
                FighterRegister(f);
            }
        }
        if(it==fighters.end())
            break;
    }
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        if ((*it)->DestroyFinished()||
                (*it)->GetPosition().x<data.GAME_AREA_BOTTOM_LEFT.x||
                (*it)->GetPosition().y<data.GAME_AREA_BOTTOM_LEFT.y||
                (*it)->GetPosition().x>data.GAME_AREA_TOP_RIGHT.x||
                (*it)->GetPosition().y>data.GAME_AREA_TOP_RIGHT.y){
            delete (*it);
            enemy_bullets.erase(it);
        }
        if(it==enemy_bullets.end())
            break;
    }
    for(vector<Enemy*>::iterator it=enemies.begin();it!=enemies.end();++it){
        if ((*it)->DestroyFinished()||
                (*it)->GetPosition().x<data.GAME_AREA_BOTTOM_LEFT.x||
                (*it)->GetPosition().y<data.GAME_AREA_BOTTOM_LEFT.y||
                (*it)->GetPosition().x>data.GAME_AREA_TOP_RIGHT.x||
                (*it)->GetPosition().y>data.GAME_AREA_TOP_RIGHT.y){
            delete (*it);
            enemies.erase(it);
        }
        if(it==enemies.end())
            break;
    }
    for(vector<Bomb*>::iterator it=bombs.begin();it!=bombs.end();++it){
        if ((*it)->DestroyFinished()){
            delete (*it);
            bombs.erase(it);
        }
        if(it==bombs.end())
            break;
    }
    for(vector<Item*>::iterator it=items.begin();it!=items.end();++it){
        if ((*it)->DestroyFinished()||
                (*it)->GetPosition().x<data.GAME_AREA_BOTTOM_LEFT.x||
                (*it)->GetPosition().y<data.GAME_AREA_BOTTOM_LEFT.y||
                (*it)->GetPosition().x>data.GAME_AREA_TOP_RIGHT.x||
                (*it)->GetPosition().y>data.GAME_AREA_TOP_RIGHT.y){
            delete (*it);
            items.erase(it);
        }
        if(it==items.end())
            break;
    }
}

bool Game::IsPaused()
{
    if (player0!=NULL&&player0->my_control->PauseValue()){
        if (!player0->START){
            Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,
                                       &fighter_hitpoint,new Fighter1Graphic(),player0);   
            FighterRegister(tmp);
            player0->START=true;
        }
        else if(player0->IsDead()){
            if (coins>0){
                --coins;
                Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,
                                           &fighter_hitpoint,new Fighter1Graphic(),player0);   
                FighterRegister(tmp);
                player0->Revive();
            }
        }else{
            control.Clean();
            control2.Clean();
            PAUSED=!PAUSED;
            emit graphic_engine.Update();
        }
    }
    if (player1!=NULL&&player1->my_control->PauseValue()){
        if (!player1->START){
            Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,
                                       &fighter_hitpoint,new Fighter1Graphic(),player1);   
            FighterRegister(tmp);
            player1->START=true;
        }
        else if(player1->IsDead()){
            if (coins>0){
                Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,
                                           &fighter_hitpoint,new Fighter1Graphic(),player1);   
                FighterRegister(tmp);
                --coins;
                player1->Revive();
            }
        }else{
            control.Clean();
            control2.Clean();
            PAUSED=!PAUSED;
            emit graphic_engine.Update();
        }
    }
    return PAUSED;
}

Fighter* Game::SelectNearestFighter(Point p)
{
    if (fighters.empty())return NULL;
    Fighter* t=NULL;
    double dis=10000000;
    for (vector<Fighter*>::iterator i=fighters.begin();i!=fighters.end();++i){
        if (!(*i)->IsDestroyed()){
            int d=Distance(p,(*i)->GetPosition());
            if (d<dis){
                t=*i;dis=d;
            }
        }
    }
    return t;
}

Enemy* Game::SelectNearestEnemy(Point p)
{
    if (enemies.empty())return NULL;
    Enemy* t=NULL;
    double dis=10000000;
    for (vector<Enemy*>::iterator i=enemies.begin();i!=enemies.end();++i){
        if (!(*i)->IsDestroyed()){
            int d=Distance(p,(*i)->GetPosition());
            if (d<dis){
                t=*i;dis=d;
            }
        }
    }
    return t;
}
