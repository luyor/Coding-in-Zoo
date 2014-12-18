#include "game.h"

Game::Game(enum GameMode game_mode,int coins0,Control* control0,Control* control1):
    backgrond_position(0),coins(coins0),PAUSED(false),END(false),
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
                design.NewEnemy(*this,backgrond_position);
                AllChangeStatus((double)physics_time.restart()/1000);
                AllCheckCollision();
                if (graphics_time.elapsed()>=1000.0/data.FRAME_PER_SECOND)//flash a frame
                    AllPaint((double)graphics_time.restart()/1000);
                AllClean();
                break;
            case MISSION_END:
                my_graphic_engine.MissionComplete();

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
    for (vector<Bullet>::iterator i=friendly_bullets.begin();i!=friendly_bullets.end();++i){
        for (vector<Enemy>::iterator j=enemies.begin();j!=enemies.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j)){
                i->AddScore(j->Hit(i->Hit()));
                //i->Hit return damage,j->Hit return score
            }
        }
    }

    for (vector<Bullet>::iterator i=enemy_bullets.begin();i!=enemy_bullets.end();++i){
        for (vector<Fighter>::iterator j=fighters.begin();j!=fighters.end();++j){
            if(!i->IsDestroyed()&&!j->IsDestroyed()&&IsColliding(*i,*j)){
                j->Hit(i->Hit());
                //i->Hit return damage,j->Hit return score
            }
        }
    }

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

    for (vector<Fighter>::iterator i=fighters.begin();i!=fighters.end();++i){
        for (vector<Item>::iterator j=items.begin();j!=items.end();++j){
            i->GetItem(j->Hit());
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
