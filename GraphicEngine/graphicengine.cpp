#include "graphicengine.h"
#include "fighter1graphic.h"
#include "fighter2graphic.h"
#include "bulletyellowgraphic.h"
#include "bombatomicgraphic.h"
#include "missilegraphic.h"
#include "bombdispersegraphic.h"
#include "enemy1graphic.h"
#include "enemy2graphic.h"
#include "enemybullet1graphic.h"
#include "itembulletlvupgraphic.h"
#include "itemscore1000graphic.h"
#include "bulletbluegraphic.h"
#include "bulletpurplegraphic.h"

#include "../GameEngine/fighter.h"

//*back_ground = QPixmap::fromImage(QImage());
GraphicEngine::GraphicEngine() : bk(0), f1(NULL), f2(NULL) ,END_PAINT(true)
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
