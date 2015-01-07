#include "design.h"
#include "../res.h"
#include "enemy1.h"
#include "enemy2.h"
#include "enemy3.h"
#include "enemy4.h"
#include "boss1.h"
#include "boss2.h"
#include "GameEngine/game.h"

struct CheckPoint Design::EnemyLists[N_STAGE][N_ENEMY] ={
    {
        CheckPoint(50,EnemyType2),
        CheckPoint(50,EnemyType2),
        CheckPoint(300,EnemyType3),
        CheckPoint(305,EnemyType3),
        CheckPoint(310,EnemyType3),
        CheckPoint(315,EnemyType3),
        CheckPoint(320,EnemyType3),
        CheckPoint(325,EnemyType3),
        CheckPoint(330,EnemyType3),
        CheckPoint(335,EnemyType3),
        CheckPoint(340,EnemyType3),
        CheckPoint(345,EnemyType3),
        CheckPoint(500,EnemyType1),
        CheckPoint(510,EnemyType1),
        CheckPoint(520,EnemyType1),
        CheckPoint(530,EnemyType1),
        CheckPoint(540,EnemyType1),
        CheckPoint(550,EnemyType1),

        CheckPoint(700,EnemyType1),
        CheckPoint(700,EnemyType1),
        CheckPoint(700,EnemyType1),
        CheckPoint(700,EnemyType1),
        CheckPoint(750,EnemyType2),
        CheckPoint(760,EnemyType2),
        CheckPoint(770,EnemyType2),
        CheckPoint(780,EnemyType2),
        CheckPoint(780,EnemyType4),
        CheckPoint(790,EnemyType4),
        CheckPoint(800,EnemyType4),
        CheckPoint(810,EnemyType4),
        CheckPoint(820,EnemyType4),
        CheckPoint(830,EnemyType4),
        CheckPoint(840,EnemyType4),
        CheckPoint(850,EnemyType4),
        CheckPoint(860,EnemyType4),
        CheckPoint(870,EnemyType4),
        CheckPoint(880,EnemyType4),
        CheckPoint(890,EnemyType4),
        CheckPoint(900,EnemyType4),
        CheckPoint(910,EnemyType1),
        CheckPoint(920,EnemyType1),
        CheckPoint(930,EnemyType1),
        CheckPoint(980,EnemyType1),
        CheckPoint(990,EnemyType1),
        CheckPoint(1000,EnemyType1),
        CheckPoint(1210,EnemyType3),
        CheckPoint(1212,EnemyType3),
        CheckPoint(1214,EnemyType3),
        CheckPoint(1216,EnemyType3),
        CheckPoint(1218,EnemyType3),
        CheckPoint(1220,EnemyType3),
        CheckPoint(1222,EnemyType3),
        CheckPoint(1224,EnemyType3),
        CheckPoint(1226,EnemyType3),
        CheckPoint(1228,EnemyType3),
        CheckPoint(1230,EnemyType3),
        CheckPoint(1232,EnemyType3),
        CheckPoint(1234,EnemyType3),
        CheckPoint(1236,EnemyType3),
        CheckPoint(1238,EnemyType3),
        CheckPoint(1300,EnemyType1),
        CheckPoint(1310,EnemyType1),
        CheckPoint(1320,EnemyType1),
        CheckPoint(1330,EnemyType1),
        CheckPoint(1340,EnemyType1),
        CheckPoint(1350,EnemyType1),
        CheckPoint(1350,EnemyType1),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1450,EnemyType2),
        CheckPoint(1550,EnemyType1),
        CheckPoint(1560,EnemyType1),
        CheckPoint(1570,EnemyType1),
        CheckPoint(1580,EnemyType1),
        CheckPoint(1590,EnemyType1),
        CheckPoint(1600,EnemyType1),
        CheckPoint(1610,EnemyType1),

        CheckPoint(1700,EnemyType4),
        CheckPoint(1715,EnemyType4),
        CheckPoint(1730,EnemyType4),
        CheckPoint(1745,EnemyType4),
        CheckPoint(1750,EnemyType4),
        CheckPoint(1765,EnemyType4),
        CheckPoint(1780,EnemyType4),
        CheckPoint(1815,EnemyType4),
        CheckPoint(1830,EnemyType4),
        CheckPoint(1845,EnemyType4),
        CheckPoint(1860,EnemyType4),
        CheckPoint(1900,EnemyType2),
        CheckPoint(2000,EnemyType2),
        CheckPoint(2100,EnemyType2),
        CheckPoint(2200,EnemyType2),

        CheckPoint(2400,BossType1),
        CheckPoint(1e60,No)
    },
    {
    CheckPoint(50,EnemyType2),
    CheckPoint(50,EnemyType2),
    CheckPoint(200,EnemyType2),
    CheckPoint(200,EnemyType2),
    CheckPoint(350,EnemyType2),
    CheckPoint(350,EnemyType2),
    CheckPoint(500,EnemyType2),
    CheckPoint(500,EnemyType2),
    CheckPoint(800,BossType2),
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
            xx = new Enemy1(Point(0,-160),Point(x,y),-M_PI/2,&enemy1_hitpoint,50,5,100);
            break;
        case EnemyType2:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % 300) + 101;
            xx = new Enemy2(Point(0,-80),Point(x,y),-M_PI/2,&enemy2_hitpoint,300,10,500);
            break;
        case EnemyType3:
            if (enemy3occuring == false) {
                xforenemy3 = rand() % 70 + 150;
                enemy3occuring = true;
            }
            y = data.PAINT_AREA_TOP_RIGHT.y + 10;
            x = xforenemy3;
            xx = new Enemy3(Point(0,0), Point(x,y),-M_PI/2, &enemy3_hitpoint,30,0,90);
            break;
        case EnemyType4:
            enemy3occuring = 0;
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = (rand() % ((int)data.PAINT_AREA_TOP_RIGHT.x - 100)) + 51;
            xx = new Enemy4(Point(0,-40),Point(x,y),-M_PI/2,&enemy4_hitpoint,50,20,100);
            break;
        case BossType1:
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = data.PAINT_AREA_TOP_RIGHT.x / 2;
            xx = new Boss1(Point(0,-80),Point(x,y),-M_PI/2,&boss1_hitpoint,8000,30,10000);
            break;
        case BossType2:
            y = data.PAINT_AREA_TOP_RIGHT.y + 120;
            x = data.PAINT_AREA_TOP_RIGHT.x / 2;
            xx = new Boss2(Point(0,-80),Point(x,y),-M_PI/2,&boss1_hitpoint,10000,30,10000);
            break;
        case BossType3:
            break;
        }
        game.EnemyRegister(xx);
        CurrentEnemyNumber++;
    }
}
