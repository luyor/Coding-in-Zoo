#include "game.h"

#include "../GameDesign/enemy1.h"

Game::Game()
{
    Init();
}

void Game::Init()
{
    Bullet::Init();
    Bomb::Init();
    //Enemy::Init();
    Fighter::Init();
    //Item::Init();
    Missile::Init();
    Enemy1::Init();
}

void Game::Start(enum GameMode game_mode,int coins0,Control* control0,Control* control1)
{
    background_position=0;
    coins=coins0;
    PAUSED=false;
    END=false;
    status=MISSION_START;

    delete player0;
    delete player1;
    player0=new Player(data.MAX_LIFE,control0);
    player1=new Player(data.MAX_LIFE,control1);

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

    Fighter *tmp = new Fighter(Point(0,200),Point(200,-50),&fighter_hitpoint,new Fighter1Graphic(),player0);

    FighterRegister(tmp);
    if(game_mode==COOP){
        //register second fighter
    }

    Enemy1 *t= new Enemy1(Point(0,-100),Point(200,400),-M_PI/2,&enemy1_hitpoint,10000,100,100);
    EnemyRegister(t);

    t= new Enemy1(Point(0,-100),Point(600,400),-M_PI/2,&enemy1_hitpoint,100,100,100);
    EnemyRegister(t);
}

void Game::GameLoop()
{
    while(!END){
        if (!IsPaused()){
            switch(status){
            case MISSION_START:
                my_graphic_engine.MissionStart(0);
                status=MISSION_ON;
                graphics_time.start();
                physics_time.start();
                break;
            case MISSION_ON:{
                double time=(double)physics_time.restart()/1000;
                AllChangeStatus(time);
                //design.NewEnemy(*this,background_position);
                AllCheckCollision(time);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);

                    //Missile *t=new Missile(50,Point(500,500),AimAt(Point(600,600),SelectRandomFighter()->GetPosition()),
                    //                       &yellow_bullet_hitpoint,new MissileGraphic(),0,M_PI/4,M_PI*500);
                    //EnemyBulletRegister(t);
                }
                AllClean();
                /*if (design.MissionFinish()&&enemies.empty()){
                    status=MISSION_END;
                }*/
                break;
            }
            case MISSION_END:
                my_graphic_engine.MissionComplete(0);
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    double time=(double)graphics_time.restart()/1000;
                    my_graphic_engine.PaintBackground(time);
                    my_graphic_engine.MissionComplete(time);
                    if (my_graphic_engine.MissionCompleteFinish()){
                        //design.NextMission();
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
    if (background_position<(1<<60))background_position+=time*data.BACKGROUND_SPEED;
    for(vector<Bullet*>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->Move(time);
    }
    for(vector<Bullet*>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->Move(time);
    }
    for(vector<Fighter*>::iterator it=fighters.begin();it!=fighters.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->FighterMove(time);
    }
    for(vector<Enemy*>::iterator it=enemies.begin();it!=enemies.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->Move(time);
    }
    for(vector<Bomb*>::iterator it=bombs.begin();it!=bombs.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->Move(time);
    }
    for(vector<Item*>::iterator it=items.begin();it!=items.end();++it){
        (*it)->ChangeStatus(time,*this);
        (*it)->Move(time);
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
    my_graphic_engine.PaintBackground(time);
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
    if (player0->my_control->PauseValue()){
        if(player0->IsDead()){
            if (coins>0){
                --coins;
                //register fighter
                player0->Revive();
            }
        }else
            PAUSED=!PAUSED;
    }
    /*if (player1->my_control->PauseValue()){
        if(player1->IsDead()){
            if (coins>0){
                --coins;
                //register fighter
                player1->Revive();
            }
        }else
            PAUSED=!PAUSED;
    }*/
    return PAUSED;
}

Fighter* Game::SelectRandomFighter()
{
    if (fighters.empty())return NULL;
    return fighters[rand()%fighters.size()];
}

Enemy* Game::SelectRandomEnemy()
{
    if (enemies.empty())return NULL;
    return enemies[rand()%enemies.size()];
}

Fighter* Game::SelectNearestFighter(Point p)
{
    if (fighters.empty())return NULL;
    vector<Fighter*>::iterator t=fighters.begin();
    double dis=Distance(p,(*t)->GetPosition());
    for (vector<Fighter*>::iterator i=fighters.begin()+1;i!=fighters.end();++i){
        int d=Distance(p,(*i)->GetPosition());
        if (d<dis){
            t=i;dis=d;
        }
    }
    return (*t);
}

Enemy* Game::SelectNearestEnemy(Point p)
{
    if (enemies.empty())return NULL;
    vector<Enemy*>::iterator t=enemies.begin();
    double dis=Distance(p,(*t)->GetPosition());
    for (vector<Enemy*>::iterator i=enemies.begin()+1;i!=enemies.end();++i){
        int d=Distance(p,(*i)->GetPosition());
        if (d<dis){
            t=i;dis=d;
        }
    }
    return (*t);
}
