#include "design.h"
#include "../res.h"
#include "enemy1.h"
#include "enemy2.h"
#include "GameEngine/game.h"

struct CheckPoint Design::EnemyLists[N_STAGE][N_ENEMY] ={
    {
        CheckPoint(70,EnemyType1),
        CheckPoint(80,EnemyType1),
        CheckPoint(160,EnemyType1),
        CheckPoint(170,EnemyType1),
        CheckPoint(260,EnemyType3),
        CheckPoint(262,EnemyType3),
        CheckPoint(264,EnemyType3),
        CheckPoint(266,EnemyType3),
        CheckPoint(268,EnemyType3),
        CheckPoint(270,EnemyType3),
        CheckPoint(272,EnemyType3),
        CheckPoint(274,EnemyType3),
        CheckPoint(276,EnemyType3),
        CheckPoint(278,EnemyType3),
        CheckPoint(280,EnemyType2),
        CheckPoint(310,EnemyType1),
        CheckPoint(320,EnemyType1),
        CheckPoint(400,EnemyType4),
        CheckPoint(410,EnemyType4),
        CheckPoint(420,EnemyType4),
        CheckPoint(430,EnemyType4),
        CheckPoint(440,EnemyType4),
        CheckPoint(450,EnemyType3),
        CheckPoint(452,EnemyType3),
        CheckPoint(454,EnemyType3),
        CheckPoint(456,EnemyType3),
        CheckPoint(458,EnemyType3),
        CheckPoint(460,EnemyType3),
        CheckPoint(462,EnemyType3),
        CheckPoint(464,EnemyType3),
        CheckPoint(466,EnemyType3),
        CheckPoint(468,EnemyType3),
        CheckPoint(470,EnemyType3),
        CheckPoint(470,EnemyType2),
        CheckPoint(500,EnemyType2),
        CheckPoint(530,EnemyType2),
        CheckPoint(560,EnemyType2),
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
    double x,y;
    double xforenemy3;
    bool enemy3occuring = 0;
    while (EnemyLists[CurrentStageNumber][CurrentEnemyNumber].OccurPosition < background_position) {
        //cout<<"make"<<endl;
        Enemy *xx;
        switch (EnemyLists[CurrentStageNumber][CurrentEnemyNumber].EnemyType) {    
        case EnemyType1:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % ((int)data.PAINT_AREA_TOP_RIGHT.x - 200)) + 101;
            xx = new Enemy1(Point(0,-100),Point(x,y),-M_PI/2,&enemy1_hitpoint,50,100,100);
            break;
        case EnemyType2:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % 300) + 101;
            xx = new Enemy2(Point(0,-80),Point(x,y),-M_PI/2,&enemy2_hitpoint,200,100,500);
            break;
        case EnemyType3:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % 300) + 101;
            xx = new Enemy2(Point(0,-80),Point(x,y),-M_PI/2,&enemy2_hitpoint,200,100,500);
            break;
        case EnemyType4:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % 300) + 101;
            xx = new Enemy2(Point(0,-80),Point(x,y),-M_PI/2,&enemy2_hitpoint,200,100,500);
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
