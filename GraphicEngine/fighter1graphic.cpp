#include "fighter1graphic.h"
#include <QMatrix>

QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::CREATE]         = NULL;
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::NORMAL]         = new QImage("player1.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::HIT1]           = new QImage("player1_hit1.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::HIT2]           = new QImage("player1_hit2.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::HIT3]           = new QImage("player1_hit3.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::DESTROY1]       = new QImage("player1_destroy1.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::DESTROY2]       = new QImage("player1_destroy2.png");
QImage* Fighter1Graphic::pics[Fighter1Graphic::PicStatus::DESTROY_FINISH] = NULL;

const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::CREATE]         = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::NORMAL]         = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::HIT1]           = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::HIT2]           = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::HIT3]           = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::DESTROY1]       = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::DESTROY2]       = 0;
const double Fighter1Graphic::TIME[Fighter1Graphic::PicStatus::DESTROY_FINISH] = 0;

Fighter1Graphic::Fighter1Graphic()
{
    sig = NO_SIGNAL;
    elapsed_time = 0;
    finish = false;
}

void Fighter1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage *img;
    QImage image_to_show;

    elapsed_time += time;
    if(sig == Signal::CREATE)  status = PicStatus::CREATE;
    if(sig == Signal::HIT)     status = PicStatus::HIT1;
    if(sig == Signal::DESTROY) status = PicStatus::DESTROY1;
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
        case PicStatus::HIT1:
            if(elapsed_time > TIME[PicStatus::HIT1])
            {
                elapsed_time = 0;
                status = PicStatus::HIT2;
            }
            break;
        case PicStatus::HIT2:
            if(elapsed_time > TIME[PicStatus::HIT2])
            {
                elapsed_time = 0;
                status = PicStatus::HIT3;
            }
            break;
        case PicStatus::HIT3:
            if(elapsed_time > TIME[PicStatus::HIT3])
            {
                elapsed_time = 0;
                status = PicStatus::NORMAL;
            }
            break;
        case PicStatus::DESTROY1:
            if(elapsed_time > TIME[PicStatus::DESTROY1])
            {
                elapsed_time = 0;
                status = PicStatus::DESTROY2;
            }
            break;
        case PicStatus::DESTROY2:
            if(elapsed_time > TIME[PicStatus::DESTROY2])
            {
                elapsed_time = 0;
                status = PicStatus::DESTROY_FINISH;
            }
            break;
        case PicStatus::DESTROY_FINISH:
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
