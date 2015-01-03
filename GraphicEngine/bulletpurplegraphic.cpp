#include "bulletpurplegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BulletPurpleGraphic::pics[] = {NULL};

double BulletPurpleGraphic::TIME[] = {0};

BulletPurpleGraphic::BulletPurpleGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point BulletPurpleGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void BulletPurpleGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = BulletPurpleGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = BulletPurpleGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case BulletPurpleGraphic::CREATE:
            if(elapsed_time > TIME[BulletPurpleGraphic::CREATE])
            {
                elapsed_time = 0;
                status = BulletPurpleGraphic::NORMAL;
            }
            break;
        case BulletPurpleGraphic::NORMAL:
            if(elapsed_time > TIME[BulletPurpleGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = BulletPurpleGraphic::NORMAL;
            }
            break;
        case BulletPurpleGraphic::DESTROY:
            if(elapsed_time > TIME[BulletPurpleGraphic::DESTROY])
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

void BulletPurpleGraphic::InitBulletPurple()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/bullet_images/bullet_purple.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
