#ifndef GAME_H
#define GAME_H

#include "../stdafx.h"
#include "bullet.h"
#include "enemy.h"
#include "missile.h"
#include "fighter.h"
#include "item.h"
#include "bomb.h"
#include "player.h"
#include "../GameDesign/design.h"
#include "../GraphicEngine/graphicengine.h"
#include "res.h"

class Game
{
public:
    enum GameMode{
        SINGLE=0,
        COOP
    };

    Game(enum GameMode game_mode,int coins0,Control* control0,Control* control1);
    void GameLoop();

    void FighterRegister(Fighter& fighter);
    void EnemyRegister(Enemy& enemy);
    void FriendlyBulletRegister(Bullet& bullet);
    void EnemyBulletRegister(Bullet& bullet);
    void BombRegister(Bomb& bomb);
    void ItemRegister(Item& item);
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
    int backgrond_position;
    int coins;
    bool PAUSED,END;

    GraphicEngine my_graphic_engine;

    Player player0,player1;

    vector<Bullet> friendly_bullets;
    vector<Bullet> enemy_bullets;
    vector<Fighter> fighters;
    vector<Enemy> enemies;
    vector<Bomb> bombs;
    vector<Item> items;

    //private functions
    void AllChangeStatus(double time);
        //change velocity,auto-destroy,create,move,fire
    void AllCheckCollision();
        //minus life,send hit message,destroy
    void AllPaint(double time);
    void AllClean();
        //clean all objects that finish paint
    bool IsPaused();
        //respond pause/insert coin key,return pause status
};

#endif // GAME_H
