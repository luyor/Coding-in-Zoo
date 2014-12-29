#include "graphicengine.h"
#include "fighter1graphic.h"
#include "bulletyellowgraphic.h"
#include "bombatomicgraphic.h"
#include "missilegraphic.h"
#include "bombdispersegraphic.h"
#include "enemy1graphic.h"
#include "enemybullet1graphic.h"
#include "itembulletlvupgraphic.h"
#include "itemscore1000graphic.h"


//*back_ground = QPixmap::fromImage(QImage());
GraphicEngine::GraphicEngine() : bk_time(0)
{
    Fighter1Graphic::InitFighter1();
    BulletYellowGraphic::InitBulletYellow();
    BombAtomicGraphic::InitBombAtomic();
    MissileGraphic::InitMissile();
    BombDisperseGraphic::InitBombDisperse();
    Enemy1Graphic::InitEnemy1();
    EnemyBullet1Graphic::InitEnemyBullet1();
    ItemBulletLvupGraphic::InitItemBulletLvup();
    ItemScore1000Graphic::InitItemScore1000();
}

void GraphicEngine::PaintBackground(double time)
{
    bk_time += time;
}
