#include "game.h"
#include "../res.h"
#include "enemy.h"

Point Game::FIGHTER1_INIT_POSITION=Point(200,-50);
Point Game::FIGHTER2_INIT_POSITION=Point(400,-50);
Point Game::FIGHTER_INIT_VELOCITY=Point(0,200);

Game::Game():player0(NULL),player1(NULL),WELCOME(true),ALLDEAD(false)
{
    Init();
    graphics_time.start();
    physics_time.start();
}

void Game::Init()
{
    Bullet::Init();
    Bomb::Init();
    Enemy::Init();
    Fighter::Init();
    Item::Init();
    Missile::Init();
}

void Game::Start(enum GameMode game_mode,int coins0)
{
    graphic_engine.PaintForeground(NULL,NULL);
    if (player0!=NULL)delete player0;
    if (player1!=NULL)delete player1;
    player0=new Player(data.MAX_LIFE,&control);
    player1=new Player(data.MAX_LIFE,&control2);

    DeleteAllExceptFighter();
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        delete (*it);
    }
    fighters.clear();
    design.Reset();
    
    coins=coins0;
    WELCOME=false;
    PAUSED=false;
    END=false;
    status=MISSION_START;
    ALLDEAD=false;
    
    FighterRegister(new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,&fighter_hitpoint,new Fighter1Graphic(),player0));
    player0->START=true;
    if (game_mode==COOP){
        FighterRegister(new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,&fighter_hitpoint,new Fighter2Graphic(),player1));
        player1->START=true;
    }
    control.Clean();
    control2.Clean();
    graphic_engine.pics_to_show.clear();
    emit graphic_engine.ResetBGM();
}

void Game::GameLoop()
{
    LOCK=true;
    while(!END){
        if (WELCOME){
            if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                graphic_engine.PaintTitle((double)graphics_time.restart()/1000);
                emit graphic_engine.Update();
            }
        }
        else if (IsPaused()){
            graphics_time.start();
            physics_time.start();
        }else {
            switch(status){
            case MISSION_START:{
                //cout<<"mission start"<<endl;
                background_position=0;
                control.Clean();
                control2.Clean();

                status=MISSION_ON;
                graphic_engine.PaintBackground(0);
                graphics_time.start();
                graphic_engine.MissionStart();
                emit graphic_engine.NextBGM();
                emit graphic_engine.PlaySoundBGM();
                while (!graphic_engine.MissionStartFinish()){
                    if (END)return;
                    if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                        graphic_engine.PaintDoor((double)graphics_time.restart()/1000);
                        emit graphic_engine.Update();
                    }
                }
                physics_time.start();
                graphics_time.start();
                break;
            }
            case MISSION_ON:{
                double time=(double)physics_time.restart()/1000;
                AllChangeStatus(time);
                design.NewEnemy(*this,background_position);
                AllCheckCollision(time);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);
                }
                AllClean();
                if (fighters.size()==0){
                    ALLDEAD=true;
                    all_dead_time+=time;
                    if (coins==0||all_dead_time>10)status=GAME_OVER;
                }else{
                    all_dead_time=0;
                    ALLDEAD=false;
                }              
                if (buffer_enemies.size()==0&&fighters.size()>0&&design.MissionFinish()&&enemies.empty()&&enemy_bullets.empty()){
                    status=MISSION_END;
                }
                break;
            }
            case MISSION_END:
                graphic_engine.MissionComplete();
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    double time=(double)graphics_time.restart()/1000;
                    graphic_engine.PaintBackground(time);
                    while (!graphic_engine.MissionCompleteFinish()){
                        if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                            graphic_engine.PaintDoor((double)graphics_time.restart()/1000);
                            emit graphic_engine.Update();
                        }
                    }
                    if (design.TurnToNextStage()){
                        status=MISSION_START;
                        DeleteAllExceptFighter();
                        graphic_engine.pics_to_show.clear();
                        
                        for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
                            if ((*it)->GetPlayer()==player0)(*it)->Reset(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION);
                            if ((*it)->GetPlayer()==player1)(*it)->Reset(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION);
                        }
                    }else status=WIN_GAME;
                }

                break;
            case GAME_OVER:{
                double time=(double)physics_time.restart()/1000;
                AllChangeStatus(time);
                design.NewEnemy(*this,background_position);
                AllCheckCollision(time);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);
                }
                AllClean();
                //prompt game end
                break;
            }
            case WIN_GAME:
                WELCOME=true;
                break;
           }         
       }
    }
    LOCK=false;
}

void Game::FighterRegister(Fighter* fighter)
{
    fighters.push_back(fighter);
    if (fighter->GetPlayer()==player0){
        for (int i=0;i<3;++i){
            fighter->bomb_list.push_back(Fighter::ATOMIC);
        }
    }else {
        for (int i=0;i<3;++i){
            fighter->bomb_list.push_back(Fighter::DISPERSE);
        }
    }
}

void Game::EnemyRegister(Enemy* enemy)
{
    buffer_enemies.push_back(enemy);
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
    //add enemy from buffer
    for (vector<Enemy*>::iterator it=buffer_enemies.begin();it!=buffer_enemies.end();++it){
        enemies.push_back((*it));
    }
    buffer_enemies.clear();
    
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
    while (graphic_engine.END_PAINT==false)return;
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
            if (p->IsDead()){
                p->START=false;
            }else{
                Fighter *f;
                if (p==player0)        
                    f=new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,&fighter_hitpoint,new Fighter1Graphic(),p);
                else 
                    f=new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,&fighter_hitpoint,new Fighter2Graphic(),p);
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
            if (status!=GAME_OVER&&coins>0){
            Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER1_INIT_POSITION,
                                       &fighter_hitpoint,new Fighter1Graphic(),player0);   
            --coins;
            FighterRegister(tmp);
            player0->START=true;
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
            if (status!=GAME_OVER&&coins>0){
            Fighter *tmp = new Fighter(FIGHTER_INIT_VELOCITY,FIGHTER2_INIT_POSITION,
                                       &fighter_hitpoint,new Fighter2Graphic(),player1);   
            --coins;
            FighterRegister(tmp);
            player1->START=true;
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

void Game::DeleteAllExceptFighter()
{
    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        delete (*it);
    }
    friendly_bullets.clear();
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        delete (*it);
    }
    enemy_bullets.clear();
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

}
