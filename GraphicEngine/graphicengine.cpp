#include "graphicengine.h"
#include "fighter1graphic.h"
#include "fighter2graphic.h"
#include "bulletyellowgraphic.h"
#include "bombatomicgraphic.h"
#include "missilegraphic.h"
#include "bombdispersegraphic.h"
#include "enemy1graphic.h"
#include "enemybullet1graphic.h"
#include "itembulletlvupgraphic.h"
#include "itemscore1000graphic.h"
#include "bulletbluegraphic.h"
#include "bulletpurplegraphic.h"
#include "enemy2graphic.h"
#include "itemmissile1graphic.h"
#include "itemmissile2graphic.h"
#include "itembombatomicgraphic.h"
#include "itembombdispersegraphic.h"
#include "../GameEngine/fighter.h"

GraphicEngine::GraphicEngine() : door_open(false),door_close(false),title_time(0),door_time(0),bk(0), f1(NULL), f2(NULL), END_PAINT(true)
{
    Fighter1Graphic::InitFighter1();
    Fighter2Graphic::InitFighter2();
    BulletYellowGraphic::InitBulletYellow();
    BombAtomicGraphic::InitBombAtomic();
    MissileGraphic::InitMissile();
    BombDisperseGraphic::InitBombDisperse();
    Enemy1Graphic::InitEnemy1();
    Enemy2Graphic::InitEnemy2();
    EnemyBullet1Graphic::InitEnemyBullet1();
    ItemBulletLvupGraphic::InitItemBulletLvup();
    ItemScore1000Graphic::InitItemScore1000();
    BulletBlueGraphic::InitBulletBlue();
    BulletPurpleGraphic::InitBulletPurple();
    ItemMissile1Graphic::InitItemMissile1();
    ItemMissile2Graphic::InitItemMissile2();
    ItemBombAtomicGraphic::InitItemBombAtomic();
    ItemBombDisperseGraphic::InitItemBombDisperse();
}

void GraphicEngine::MissionStart()
{
    door_open = true;
}

void GraphicEngine::MissionComplete()
{
    door_close = true;
}

void GraphicEngine::PaintDoor(double time)
{
    door_time += time;
}

void GraphicEngine::PaintForeground(Fighter* fighter1, Fighter* fighter2)
{
    f1 = fighter1;
    f2 = fighter2;
}

void GraphicEngine::PaintBackground(double position)
{
    bk=position;
}

void GraphicEngine::PaintTitle(double time)
{
    title_time += time;
    if(time<0)title_time=0;
}

bool GraphicEngine::MissionStartFinish()
{
    if(!door_open)
    door_time = 0;
    return !door_open;
}

bool GraphicEngine::MissionCompleteFinish()
{
    if(!door_close)
    door_time = 0;
    return !door_close;
}
