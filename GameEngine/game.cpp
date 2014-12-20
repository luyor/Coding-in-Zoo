#include "game.h"

Game::Game(enum GameMode game_mode,int coins0,Control* control0,Control* control1):
    background_position(0),coins(coins0),PAUSED(false),END(false),
    player0(data.MAX_LIFE,control0),player1(data.MAX_LIFE,control1)
{
    design.Reset();
    //register fighter
    if(game_mode==COOP){
        //register second fighter
    }
}

void Game::GameLoop()
{
    while(!END){
        if (!IsPaused()){
            switch(status){
            case MISSION_START:
                my_graphic_engine.MissionStart();
                status=MISSION_ON;
                graphics_time.start();
                physics_time.start();
                break;
            case MISSION_ON:
                AllChangeStatus((double)physics_time.restart()/1000);
                design.NewEnemy(*this,background_position);
                AllCheckCollision();
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND)//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);
                AllClean();
                if (design.MissionFinish()&&enemies.empty()){
                    status=MISSION_END;
                }
                break;
            case MISSION_END:
                my_graphic_engine.MissionComplete();
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND){//flash a frame
                    my_graphic_engine.PaintBackground(time);
                    my_graphic_engine.PaintEnd((double)graphics_time.restart()/1000);
                    if (my_graphic_engine.PaintEndFinish()&&design.HaveNextMission()){
                        design.NextMission();
                        status=MISSION_START;
                    }
                }
                break;
           }
       }
    }
}

void Game::FighterRegister(Fighter& fighter)
{
    fighters.push_back(fighter);
}

void Game::EnemyRegister(Enemy& enemy)
{
    enemies.push_back(enemy);
}

void Game::FriendlyBulletRegister(Bullet& bullet)
{
    friendly_bullets.push_back(bullet);
}

void Game::EnemyBulletRegister(Bullet& bullet)
{
    enemy_bullets.push_back(bullet);
}

void Game::BombRegister(Bomb& bomb)
{
    bombs.push_back(bomb);
}

void Game::ItemRegister(Item& item)
{
    items.push_back(item);
}

void Game::AllChangeStatus(double time)
{
    if (background_position<(1<<60))background_position+=time*data.BACKGROUND_SPEED;
    for(vector<Bullet>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        it->ChangeStatus(time,*this);
        it->Move(time);
    }
    for(vector<Bullet>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        it->ChangeStatus(time,*this);
        it->Move(time);
    }
    for(vector<Fighter>::iterator it=fighters.begin();it!=fighters.end();++it){
        it->ChangeStatus(time,*this);
        it->FighterMove(time,my_graphic_engine.GetVisibleArea(),my_graphic_engine.GetFighterSize());
    }
    for(vector<Enemy>::iterator it=enemies.begin();it!=enemies.end();++it){
        it->ChangeStatus(time,*this);
        it->Move(time);
    }
    for(vector<Bomb>::iterator it=bombs.begin();it!=bombs.end();++it){
        it->ChangeStatus(time,*this);
        it->Move(time);
    }
    for(vector<Item>::iterator it=items.begin();it!=items.end();++it){
        it->ChangeStatus(time,*this);
        it->Move(time);
    }
}

void Game::AllCheckCollision()
{
    //friendly bullet collide enemy
    for (vector<Bullet>::iterator i=friendly_bullets.begin();i!=friendly_bullets.end();++i){
        for (vector<Enemy>::iterator j=enemies.begin();j!=enemies.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j)){
                i->AddScore(j->Hit(i->Hit()));
                //i->Hit return damage,j->Hit return score
            }
        }
    }

    //enemy bullet collide fighter
    for (vector<Bullet>::iterator i=enemy_bullets.begin();i!=enemy_bullets.end();++i){
        for (vector<Fighter>::iterator j=fighters.begin();j!=fighters.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j)){
                j->Hit(i->Hit());
                //i->Hit return damage,j->Hit return score
            }
        }
    }

    //fighter collide enemy
    for (vector<Fighter>::iterator i=fighters.begin();i!=fighters.end();++i){
        if (i->IsActing()){
            for (vector<Enemy>::iterator j=enemies.begin();j!=enemies.end();++j){
                if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j)){
                    i->AddScore(j->Hit(i->Crush()));
                    //i->Crush return damage,j->Hit return score
                }
            }
        }
    }

    //fighter collide item
    for (vector<Fighter>::iterator i=fighters.begin();i!=fighters.end();++i){
        for (vector<Item>::iterator j=items.begin();j!=items.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j))
                i->GetItem(j->Hit());
        }
    }

    //Enemy collide bomb
    for (vector<Bomb>::iterator i=bombs.begin();i!=bombs.end();++i){
        for (vector<Enemy>::iterator j=enemies.begin();j!=enemies.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j))
                i->AddScore(j->Hit(i->Hit()));
        }
    }

}

void Game::AllPaint(double time)
{
    my_graphic_engine.PaintBackground(time);
    for(vector<Bullet>::iterator it=friendly_bullets.begin();it!=friendly_bullets.end();++it){
        it->Paint(time);
    }
    for(vector<Bullet>::iterator it=enemy_bullets.begin();it!=enemy_bullets.end();++it){
        it->Paint(time);
    }
    for(vector<Fighter>::iterator it=fighters.begin();it!=fighters.end();++it){
        it->Paint(time);
    }
    for(vector<Enemy>::iterator it=enemies.begin();it!=enemies.end();++it){
        it->Paint(time);
    }
    for(vector<Bomb>::iterator it=bombs.begin();it!=bombs.end();++it){
        it->Paint(time);
    }
    for(vector<Item>::iterator it=items.begin();it!=items.end();++it){
        it->Paint(time);
    }
}

bool Game::IsPaused()
{
    if (player0.my_control->PauseClicked()){
        if(player0.IsDead()){
            if (coins>0){
                --coins;
                //register fighter
                player0.Revive();
            }
        }else
            PAUSED=!PAUSED;
    }
    if (player1.my_control->PauseClicked()){
        if(player1.IsDead()){
            if (coins>0){
                --coins;
                //register fighter
                player1.Revive();
            }
        }else
            PAUSED=!PAUSED;
    }
    return PAUSED;
}
