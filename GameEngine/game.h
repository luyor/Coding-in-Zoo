#ifndef GAME_H
#define GAME_H

#include "../stdafx.h"
#include "bullet.h"
#include "fighter.h"
#include "missile.h"
#include "item.h"
#include "bomb.h"
#include "player.h"
class Enemy;

class Game
{
public:
    enum GameMode{
        SINGLE=0,
        COOP
    };

    Game();
    //clear all vector,set all to default
    void Start(enum GameMode game_mode,int coins0,Control* control0,Control* control1);
    void Init();
    void GameLoop();
    void EndGame(){END=true;}

    void FighterRegister(Fighter* fighter);
    void EnemyRegister(Enemy* enemy);
    void FriendlyBulletRegister(Bullet* bullet);
    void EnemyBulletRegister(Bullet* bullet);
    void BombRegister(Bomb* bomb);
    void ItemRegister(Item* item);

    Fighter* SelectNearestFighter(Point p);
    Enemy* SelectNearestEnemy(Point p);
    
    Player *player0,*player1;
private:
    //private variables
    QTime physics_time;
    QTime graphics_time;

    enum{
        MISSION_START=0,
        MISSION_ON,
        MISSION_END
    }status;

    QTime my_time;
    double background_position;
    int coins;
    bool PAUSED,END;

    vector<Bullet*> friendly_bullets;
    vector<Bullet*> enemy_bullets;
    vector<Fighter*> fighters;
    vector<Enemy*> enemies;
    vector<Bomb*> bombs;
    vector<Item*> items;

    //private functions
    //change velocity,auto-destroy,create,move,fire
    void AllChangeStatus(double time);
    //minus life,send hit message,destroy
    void AllCheckCollision(double time);
    //clean all objects that finish paint
    void AllPaint(double time);
    void AllClean();
    //respond pause/insert coin key,return pause status
    bool IsPaused();

};

#endif // GAME_H
