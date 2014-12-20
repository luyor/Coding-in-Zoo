#ifndef DESIGN_H
#define DESIGN_H
#define N_ENEMY 1000

#include "../GameEngine/game.h"
#include "../GameEngine/enemy.h"
class Game;

class Enemy;

class Design
{
public:
    Design();
    //NewEnemy is used to register new enemy in game engine, using game.EnemyRegister()
    //background_position started with 0
    void NewEnemy(Game& game, double backgrond_position);
    void Reset();//reset level
private:
    Enemy EnemyType1();//generate a "type 1" enemy
    Enemy EnemyType2();//generate a "type 2" enemy
    Enemy EnemyType3();//generate a "type 3" enemy
    Enemy EnemyType4();//generate a "type 4" enemy
    int CurrentEnemyNumber = 0;
    struct MeetingPoint{
        int EmemyType;
        double OccurPosition;
    };
    struct MeetingPoint EnemyLists[N_ENEMY];
};

void EnemyType1(void)

void Design::NewEnemy(Game &game, double backgrond_position)
{

}

#endif // DESIGN_H
