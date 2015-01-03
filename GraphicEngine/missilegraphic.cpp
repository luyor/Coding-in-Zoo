#include "missilegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* MissileGraphic::pics[] = {NULL};

double MissileGraphic::TIME[] = {0};

MissileGraphic::MissileGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{
}

Point MissileGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void MissileGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = MissileGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = MissileGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case MissileGraphic::CREATE:
            if(elapsed_time > TIME[MissileGraphic::CREATE])
            {
                elapsed_time = 0;
                status = MissileGraphic::NORMAL;
            }
            break;
        case MissileGraphic::NORMAL:
            if(elapsed_time > TIME[MissileGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = MissileGraphic::NORMAL;
            }
            break;
        case MissileGraphic::DESTROY:
            if(elapsed_time > TIME[MissileGraphic::DESTROY])
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

void MissileGraphic::InitMissile()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/bullet_images/missile.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
