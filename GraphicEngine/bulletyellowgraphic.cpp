#include "bulletyellowgraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BulletYellowGraphic::pics[] = {NULL};

double BulletYellowGraphic::TIME[] = {0};

BulletYellowGraphic::BulletYellowGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point BulletYellowGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void BulletYellowGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = BulletYellowGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = BulletYellowGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case BulletYellowGraphic::CREATE:
            if(elapsed_time > TIME[BulletYellowGraphic::CREATE])
            {
                elapsed_time = 0;
                status = BulletYellowGraphic::NORMAL;
            }
            break;
        case BulletYellowGraphic::NORMAL:
            if(elapsed_time > TIME[BulletYellowGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = BulletYellowGraphic::NORMAL;
            }
            break;
        case BulletYellowGraphic::DESTROY:
            if(elapsed_time > TIME[BulletYellowGraphic::DESTROY])
            {
                elapsed_time = 0;
                finish = true;
            }
            break;
        }
    }
    sig = Graphic::NO_SIGNAL;
    img = pics[status];
    if(img != NULL)
    {
        matrix.rotate(360 - angle * M_PI/180);
        *image_to_show = img->transformed(matrix);
        node = PicNode(position, QPixmap::fromImage(*image_to_show));
        graphic_engine.pics_to_show.push_back(node);
    }
    delete image_to_show;
}

void BulletYellowGraphic::InitBulletYellow()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("bullet_yellow.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
