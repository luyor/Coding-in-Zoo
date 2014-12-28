#include "graphicengine.h"
#include "fighter1graphic.h"
#include "bulletyellowgraphic.h"
#include "bombatomicgraphic.h"
#include "missilegraphic.h"
#include "bombdispersegraphic.h"
#include "enemy1graphic.h"

GraphicEngine::GraphicEngine()
{
    Fighter1Graphic::InitFighter1();
    BulletYellowGraphic::InitBulletYellow();
    BombAtomicGraphic::InitBombAtomic();
    MissileGraphic::InitMissile();
    BombDisperseGraphic::InitBombDisperse();
    Enemy1Graphic::InitEnemy1();
}

void GraphicEngine::PaintBackground(double time)
{
//    QImage *img = new QImage("background.png");
//    pics_to_show.push_back();
}
