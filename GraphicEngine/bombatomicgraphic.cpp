#include "bombatomicgraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BombAtomicGraphic::pics[] = {NULL};

double BombAtomicGraphic::TIME[] = {0};

BombAtomicGraphic::BombAtomicGraphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void BombAtomicGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = BombAtomicGraphic::CREATE;
    if(sig == Graphic::HIT) status = BombAtomicGraphic::HIT1;
    if(sig == Graphic::DESTROY) status = BombAtomicGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case BombAtomicGraphic::CREATE:
            if(elapsed_time > TIME[BombAtomicGraphic::CREATE])
            {
                elapsed_time = 0;
                status = BombAtomicGraphic::NORMAL;
            }
            break;
        case BombAtomicGraphic::NORMAL:
            if(elapsed_time > TIME[BombAtomicGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = BombAtomicGraphic::NORMAL;
            }
            break;
        case BombAtomicGraphic::HIT1:
            if(elapsed_time > TIME[BombAtomicGraphic::HIT1])
            {
                elapsed_time = 0;
                status = BombAtomicGraphic::HIT2;
            }
            break;
        case BombAtomicGraphic::HIT2:
            if(elapsed_time > TIME[BombAtomicGraphic::HIT2])
            {
                elapsed_time = 0;
                status = BombAtomicGraphic::HIT3;
            }
            break;
        case BombAtomicGraphic::HIT3:
            if(elapsed_time > TIME[BombAtomicGraphic::HIT3])
            {
                elapsed_time = 0;
                status = BombAtomicGraphic::HIT4;
            }
            break;
        case BombAtomicGraphic::HIT4:
            break;
        case BombAtomicGraphic::DESTROY:
            if(elapsed_time > TIME[BombAtomicGraphic::DESTROY])
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

Point BombAtomicGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void BombAtomicGraphic::InitBombAtomic()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/bullet_images/BombAtomic.png");
    pics[HIT1]       = new QImage(":/images/Images/bullet_images/BombAtomicExplode1.png");
    pics[HIT2]       = new QImage(":/images/Images/bullet_images/BombAtomicExplode2.png");
    pics[HIT3]       = new QImage(":/images/Images/bullet_images/BombAtomicExplode3.png");
    pics[HIT4]       = new QImage(":/images/Images/bullet_images/BombAtomicExplode4.png");
    pics[DESTROY] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]       = 0.1;
    TIME[HIT2]       = 0.3;
    TIME[HIT3]       = 0.3;
    TIME[HIT4]       = 0.3;
    TIME[DESTROY] = 0;
}
