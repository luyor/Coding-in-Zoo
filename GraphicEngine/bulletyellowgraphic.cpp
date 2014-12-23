#include "bulletyellowgraphic.h"
#include <QMatrix>

QImage* BulletYellowGraphic::pics[BulletYellowGraphic::PicStatus::CREATE]         = NULL;
QImage* BulletYellowGraphic::pics[BulletYellowGraphic::PicStatus::NORMAL]         = new QImage("bullet_yellow.png");
QImage* BulletYellowGraphic::pics[BulletYellowGraphic::PicStatus::DESTROY]        = NULL;

const double BulletYellowGraphic::TIME[BulletYellowGraphic::PicStatus::CREATE]  = 0;
const double BulletYellowGraphic::TIME[BulletYellowGraphic::PicStatus::NORMAL]  = 0;
const double BulletYellowGraphic::TIME[BulletYellowGraphic::PicStatus::DESTROY] = 0;


BulletYellowGraphic::BulletYellowGraphic()
{
    sig = NO_SIGNAL;
    elapsed_time = 0;
    finish = false;
}

void BulletYellowGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage *img;
    QImage image_to_show;

    elapsed_time += time;
    if(sig == Signal::CREATE)  status = PicStatus::CREATE;
    if(sig == Signal::DESTROY) status = PicStatus::DESTROY;
    if(sig == Signal::NO_SIGNAL)
    {
        switch(status)
        {
        case PicStatus::CREATE:
            if(elapsed_time > TIME[PicStatus::CREATE])
            {
                elapsed_time = 0;
                status = PicStatus::NORMAL;
            }
            break;
        case PicStatus::NORMAL:
            if(elapsed_time > TIME[PicStatus::NORMAL])
            {
                elapsed_time = 0;
                status = PicStatus::NORMAL;
            }
            break;
        case PicStatus::DESTROY:
            if(elapsed_time > TIME[PicStatus::DESTROY_FINISH])
            {
                elapsed_time = 0;
                finish = true;
            }
            break;
        }
    }
    sig = Signal::NO_SIGNAL;
    img = pics[status];
    if(img != NULL)
    {
        matrix.rotate(360 - angle);
        image_to_show = img->transformed(matrix);
        graphic_engine.pics_to_show.push_back(PicNode(position, QPixmap::fromImage(image_to_show)));
    }
}
