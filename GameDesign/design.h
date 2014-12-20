#ifndef DESIGN_H
#define DESIGN_H
#define N_ENEMY 1000

#include "../GameEngine/game.h"
#include "../GameEngine/enemy.h"
class Game;

class Enemy;

struct MeetingPoint{
    int EmemyType;
    //Be careful! OccurPosition is not the position where the enemy would be born
    //Instead, when the "background_position">"occurposition", this enemy should appear now
    //the position where the enemy would born is DEFAULT_GAME_AREA_TOP_RIGHT
    double OccurPosition;
};

typedef struct MeetingPoint *Pointer;

class Design
{
public:
    Design();
    //NewEnemy is used to register new enemy in game engine, using game.EnemyRegister()
    //background_position started with 0
    void NewEnemy(Game& game, double backgrond_position)
    {
        if (!EnemyLists[CurrentEnemyNumber]) return;
        while (EnemyLists[CurrentEnemyNumber]->OccurPosition})
    }

    void Reset()//reset level
    {
        CurrentEnemyNumber = 0;
    }

    bool MissionFinish()
    {
        if (!EnemyLists[CurrentEnemyNumber]) return true;
        else return false;
    }

private:
    Enemy EnemyType1();//generate a "type 1" enemy
    Enemy EnemyType2();//generate a "type 2" enemy
    Enemy EnemyType3();//generate a "type 3" enemy
    Enemy EnemyType4();//generate a "type 4" enemy
    int CurrentEnemyNumber = 0;

    Pointer EnemyLists[N_ENEMY];
};


void Design::NewEnemy(Game &game, double backgrond_position)
{

}

#endif // DESIGN_H
