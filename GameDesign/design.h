#ifndef DESIGN_H
#define DESIGN_H
#define N_ENEMY 1000

#include "../General/data.h"
#include "enemy1.h"

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
    void NewEnemy(Game& game, double backgrond_position);

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
    int CurrentEnemyNumber = 0;

    Pointer EnemyLists[N_ENEMY];
};

void Design::NewEnemy(Game &game, double background_position)
{
    if (!EnemyLists[CurrentEnemyNumber]) return;
    while (EnemyLists[CurrentEnemyNumber]->OccurPosition < background_position)
    {
        switch (EnemyLists[CurrentEnemyNumber]->EmemyType) {
            case 0:
                break;
            case 1:
                //Enemy1 x();
                break;
            case 2:
                //Enemy2 x();
                break;
            case 3:
                //Enemy3 x();
                break;
            case 4:
                //Enemy4 x();
                break;
        }
        //game.EnemyRegister(x);
        CurrentEnemyNumber++;
    }
}

#endif // DESIGN_H
