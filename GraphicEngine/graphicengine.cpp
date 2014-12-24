#include "graphicengine.h"
#include "fighter1graphic.h"
#include "bulletyellowgraphic.h"

GraphicEngine::GraphicEngine()
{
    Fighter1Graphic::InitFighter1();
    BulletYellowGraphic::InitBulletYellow();
}

void GraphicEngine::PaintBackground(double time)
{
//    QImage *img = new QImage("background.png");
//    pics_to_show.push_back();
}
