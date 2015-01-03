#include "design.h"
#include "../res.h"
#include "enemy1.h"
#include "GameEngine/game.h"

struct CheckPoint Design::EnemyLists[N_STAGE][N_ENEMY] ={
    {
        CheckPoint(70,EnemyType1),
        CheckPoint(80,EnemyType1),
        CheckPoint(160,EnemyType1),
        CheckPoint(200,EnemyType1),
        CheckPoint(260,EnemyType1),
        CheckPoint(330,EnemyType1),
        CheckPoint(350,EnemyType1),
        CheckPoint(400,EnemyType1),
        CheckPoint(570,EnemyType1),
        CheckPoint(580,EnemyType1),
        CheckPoint(660,EnemyType1),
        CheckPoint(600,EnemyType1),
        CheckPoint(660,EnemyType1),
        CheckPoint(730,EnemyType1),
        CheckPoint(750,EnemyType1),
        CheckPoint(800,EnemyType1),
        CheckPoint(1070,EnemyType1),
        CheckPoint(1080,EnemyType1),
        CheckPoint(1160,EnemyType1),
        CheckPoint(1200,EnemyType1),
        CheckPoint(1260,EnemyType1),
        CheckPoint(1330,EnemyType1),
        CheckPoint(1350,EnemyType1),
        CheckPoint(1400,EnemyType1),
        CheckPoint(1570,EnemyType1),
        CheckPoint(1580,EnemyType1),
        CheckPoint(1660,EnemyType1),
        CheckPoint(1600,EnemyType1),
        CheckPoint(1660,EnemyType1),
        CheckPoint(1730,EnemyType1),
        CheckPoint(1750,EnemyType1),
        CheckPoint(1800,EnemyType1),
        CheckPoint(1e60,No)
    }
};

void Design::NewEnemy(Game& game, double background_position)
{
    while (EnemyLists[CurrentStageNumber][CurrentEnemyNumber].OccurPosition < background_position) {
        //cout<<"make"<<endl;
        double y = data.PAINT_AREA_TOP_RIGHT.y + 120;
        double x = (rand() % ((int)data.PAINT_AREA_TOP_RIGHT.x - 200)) + 101;
        Enemy1 *xx;
        switch (EnemyLists[CurrentStageNumber][CurrentEnemyNumber].EnemyType) {
        case EnemyType1:
            xx=new Enemy1(Point(0,-100),Point(x,y),-M_PI/2,&enemy1_hitpoint,50,100,100);
            break;
        case EnemyType2:
            //Enemy1 x();
            break;
        case EnemyType3:
            //Enemy2 x();
            break;
        case EnemyType4:
            //Enemy3 x();
            break;
        case BossType1:
            //Boss1 x();
            break;
        case BossType2:
            //
            break;
        case BossType3:
            break;
        }
        game.EnemyRegister(xx);
        CurrentEnemyNumber++;
    }
}
