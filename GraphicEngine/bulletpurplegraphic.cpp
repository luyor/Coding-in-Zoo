#include "bulletpurplegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* BulletPurpleGraphic::pics[] = {NULL};

double BulletPurpleGraphic::TIME[] = {0};

BulletPurpleGraphic::BulletPurpleGraphic(int l):level(l),node(Point(0,0),QPixmap()),status(NORMAL1)
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
                switch(level)
                {
                case 1:status = BulletPurpleGraphic::NORMAL1;break;
                case 2:status = BulletPurpleGraphic::NORMAL2;break;
                case 3:status = BulletPurpleGraphic::NORMAL3;break;
                case 4:status = BulletPurpleGraphic::NORMAL4;break;
                }
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
    pics[NORMAL1]        = new QImage(":/images/Images/bullet_images/bullet_purple.png");
    pics[NORMAL2]        = new QImage(":/images/Images/bullet_images/bullet_purple_lv2.png");
    pics[NORMAL3]        = new QImage(":/images/Images/bullet_images/bullet_purple_lv3.png");
    pics[NORMAL4]        = new QImage(":/images/Images/bullet_images/bullet_purple_lv4.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL1] = 0;
    TIME[NORMAL2] = 0;
    TIME[NORMAL3] = 0;
    TIME[NORMAL4] = 0;
    TIME[DESTROY] = 0;
}
