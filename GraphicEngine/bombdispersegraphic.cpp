#include "bombdispersegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BombDisperseGraphic::pics[] = {NULL};

double BombDisperseGraphic::TIME[] = {0};

BombDisperseGraphic::BombDisperseGraphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void BombDisperseGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = BombDisperseGraphic::CREATE;
    if(sig == Graphic::HIT) status = BombDisperseGraphic::HIT1;
    if(sig == Graphic::DESTROY) status = BombDisperseGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case BombDisperseGraphic::CREATE:
            if(elapsed_time > TIME[BombDisperseGraphic::CREATE])
            {
                elapsed_time = 0;
                status = BombDisperseGraphic::NORMAL;
            }
            break;
        case BombDisperseGraphic::NORMAL:
            if(elapsed_time > TIME[BombDisperseGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = BombDisperseGraphic::NORMAL;
            }
            break;
        case BombDisperseGraphic::HIT1:
            if(elapsed_time > TIME[BombDisperseGraphic::HIT1])
            {
                elapsed_time = 0;
                status = BombDisperseGraphic::HIT2;
            }
            break;
        case BombDisperseGraphic::HIT2:
            if(elapsed_time > TIME[BombDisperseGraphic::HIT2])
            {
                elapsed_time = 0;
                status = BombDisperseGraphic::HIT3;
            }
            break;
        case BombDisperseGraphic::HIT3:
            if(elapsed_time > TIME[BombDisperseGraphic::HIT3])
            {
                elapsed_time = 0;
                status = BombDisperseGraphic::HIT4;
            }
            break;
        case BombDisperseGraphic::HIT4:
            break;
        case BombDisperseGraphic::DESTROY:
            if(elapsed_time > TIME[BombDisperseGraphic::DESTROY])
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
        matrix.rotate(90 - angle * 180/M_PI);
        *image_to_show = img->transformed(matrix);
        node = PicNode(position, QPixmap::fromImage(*image_to_show));
        graphic_engine.pics_to_show.push_back(node);
    }
    delete image_to_show;
}

Point BombDisperseGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void BombDisperseGraphic::InitBombDisperse()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("BombDisperse.png");
    pics[HIT1]           = new QImage("BombDisperseExplode1.png");
    pics[HIT2]           = new QImage("BombDisperseExplode2.png");
    pics[HIT3]           = new QImage("BombDisperseExplode3.png");
    pics[HIT4]           = new QImage("BombDisperseExplode4.png");
    pics[DESTROY]        = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.1;
    TIME[HIT2]           = 0.3;
    TIME[HIT3]           = 0.3;
    TIME[HIT4]           = 0.3;
    TIME[DESTROY]        = 0;
}
