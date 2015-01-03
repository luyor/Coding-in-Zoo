#include "bulletbluegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BulletBlueGraphic::pics[] = {NULL};

double BulletBlueGraphic::TIME[] = {0};

BulletBlueGraphic::BulletBlueGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point BulletBlueGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void BulletBlueGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = BulletBlueGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = BulletBlueGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case BulletBlueGraphic::CREATE:
            if(elapsed_time > TIME[BulletBlueGraphic::CREATE])
            {
                elapsed_time = 0;
                status = BulletBlueGraphic::NORMAL;
            }
            break;
        case BulletBlueGraphic::NORMAL:
            if(elapsed_time > TIME[BulletBlueGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = BulletBlueGraphic::NORMAL;
            }
            break;
        case BulletBlueGraphic::DESTROY:
            if(elapsed_time > TIME[BulletBlueGraphic::DESTROY])
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

void BulletBlueGraphic::InitBulletBlue()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/bullet_images/bullet_blue.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
