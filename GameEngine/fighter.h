#ifndef FIGHTER_H
#define FIGHTER_H

#include "../stdafx.h"
#include "flyingobject.h"
#include "item.h"
#include "player.h"
#include "res.h"
#include "../GraphicEngine/fighter1graphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"
#include "../GraphicEngine/bombatomicgraphic.h"
#include "../GraphicEngine/missilegraphic.h"
#include "../GraphicEngine/bombdispersegraphic.h"

extern HitPoint fighter_hitpoint;

class Game;

class Fighter:public FlyingObject
{
public:
    Fighter(Point v,Point p,HitPoint* hit_point0,
            Graphic *graphic0,Player* player);
    void Fire(Game& my_game);
    void Bombard(Game& my_game);
    void GetItem(enum Item::ItemType type);
    //constrain fighter in visible area
    void FighterMove(double time);

    //add score after crush
    void AddScore(int score0){my_player->AddScore(score0);}
    //destroy,return crush damage
    int Crush();
    void Destroy();
    void ChangeStatus(double time, Game &my_game);
    void Hit(double damage);//do damage
    //check if acting when crush enemy
    bool IsActing(){if (status==ACTING)return true;return false;}
    Player* GetPlayer(){return my_player;}

    static void Init();//init hitpoint
private:
    enum{
        FLYING=0,
        BULLET_PROOF,
        ACTING
    }status;
    double elapsed_time;
    double bullet_time;
    double missile_time;

    //private variables
    Player* my_player;

    double health;

    int bullet_level;
    int missile_level;

    enum BulletType{
        YELLOW=0,
        BLUE,
        PURPLE
    }my_bullet_type;
    enum MissileType{
        TRACKING=0,
        STRAIGHT
    }my_missile_type;
    enum BombType{
        ATOMIC=0,
        DISPERSE
    };
    vector<enum BombType> bomb_list;


    //private const
    static const double FLYING_TIME;
    static const double BULLET_PROOF_TIME;
    static const double SPEED;
    static const double BULLET_FREQUENCY;
    static const double MISSILE_FREQUENCY;
    static const double MAX_BULLET_LEVEL;
    static const double MAX_MISSILE_LEVEL;
    static const double MAX_BOMB_NUMBER;
    static const int DISPERSE_BOMB_NUMBER;

    //private function
    void FireYellowBullet(double angle0, Game &my_game);
    void FireAtomicBomb(Game &my_game);
    void FireDisperseBomb(Game &my_game);
    void FireTrackingMissile(Game &my_game,Point p);
    //void FireStraightMissile(Game &my_game,Point p);
};

#endif // FIGHTER_H
