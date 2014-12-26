#include "fighter1graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Fighter1Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Fighter1Graphic::TIME[] = {0};

Fighter1Graphic::Fighter1Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Fighter1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Fighter1Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Fighter1Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Fighter1Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Fighter1Graphic::CREATE:
            if(elapsed_time > TIME[Fighter1Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::NORMAL;
            }
            break;
        case Fighter1Graphic::NORMAL:
            if(elapsed_time > TIME[Fighter1Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::NORMAL;
            }
            break;
        case Fighter1Graphic::HIT1:
            if(elapsed_time > TIME[Fighter1Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::HIT2;
            }
            break;
        case Fighter1Graphic::HIT2:
            if(elapsed_time > TIME[Fighter1Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::HIT3;
            }
            break;
        case Fighter1Graphic::HIT3:
            if(elapsed_time > TIME[Fighter1Graphic::HIT3])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::NORMAL;
            }
            break;
        case Fighter1Graphic::DESTROY1:
            if(elapsed_time > TIME[Fighter1Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::DESTROY2;
            }
            break;
        case Fighter1Graphic::DESTROY2:
            if(elapsed_time > TIME[Fighter1Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Fighter1Graphic::DESTROY_FINISH;
            }
            break;
        case Fighter1Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Fighter1Graphic::DESTROY_FINISH])
            {
                elapsed_time = 0;
                finish = true;
            }
            break;
        }
    }
    sig = Graphic::NO_SIGNAL;
    //cout<<status<<endl;
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

Point Fighter1Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Fighter1Graphic::InitFighter1()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("player1.png");
    pics[HIT1]           = new QImage("player1_hit1.png");
    pics[HIT2]           = new QImage("player1_hit2.png");
    pics[HIT3]           = new QImage("player1_hit3.png");
    pics[DESTROY1]       = new QImage("player1_destroy1.png");
    pics[DESTROY2]       = new QImage("player1_destroy2.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 1;
    TIME[HIT2]           = 1;
    TIME[HIT3]           = 1;
    TIME[DESTROY1]       = 1;
    TIME[DESTROY2]       = 1;
    TIME[DESTROY_FINISH] = 0;
}
