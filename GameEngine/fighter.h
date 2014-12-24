#ifndef FIGHTER_H
#define FIGHTER_H

#include "../stdafx.h"
#include "flyingobject.h"
#include "item.h"
#include "player.h"
#include "res.h"

#include "../GraphicEngine/fighter1graphic.h"

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
    void FighterMove(double time,Point visible_area,Point fighter_size);

    //add score after crush
    void AddScore(int score0){my_player->AddScore(score0);}
    //destroy,return crush damage
    int Crush();
    void Destroy();
    void ChangeStatus(double time, Game &my_game);
    void Hit(int damage);//do damage
    //check if acting when crush enemy
    bool IsActing(){if (status==ACTING)return true;return false;}
private:
    enum{
        FLYING=0,
        BULLET_PROOF,
        ACTING
    }status;
    double elapsed_time;

    //private variables
    Player* my_player;

    int health;

    int bullet_level;
    int missile_level;

    enum BulletType{
    }my_bullet_type;
    enum MissileType{
    }my_missile_type;
    enum BombType{
    }my_bomb_type;
    vector<BombType> bomb_list;


    //private const
    static const int max_bullet_level;
    static const int max_missile_level;
    static const int FLYING_TIME;
    static const int BULLET_PROOF_TIME;
    static const int SPEED;
};

#endif // FIGHTER_H
