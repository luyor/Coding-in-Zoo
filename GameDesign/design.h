#ifndef DESIGN_H
#define DESIGN_H
const int N_ENEMY = 10000;
const int N_STAGE = 1;

class Game;

enum Enemies{
    No=0,
    EnemyType1,
    EnemyType2,
    EnemyType3,
    EnemyType4,
    BossType1,
    BossType2,
    BossType3
};

struct CheckPoint{
    Enemies EnemyType;
    //Be careful! OccurPosition is not the position where the enemy would be born
    //Instead, when the "background_position">"occurposition", this enemy should appear now
    //the position where the enemy would born is DEFAULT_GAME_AREA_TOP_RIGHT
    double OccurPosition;
    CheckPoint(){}
    CheckPoint(double y,enum Enemies x):OccurPosition(y),EnemyType(x)
    {
    }
};

class Design
{
public:
    Design():CurrentEnemyNumber(0), CurrentStageNumber(0)
    {
    }

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
    int CurrentEnemyNumber;
    int CurrentStageNumber;
    static struct CheckPoint EnemyLists[N_STAGE][N_ENEMY];
};


#endif // DESIGN_H
