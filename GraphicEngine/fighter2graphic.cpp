#include "fighter2graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Fighter2Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Fighter2Graphic::TIME[] = {0};

Fighter2Graphic::Fighter2Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Fighter2Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Fighter2Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Fighter2Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Fighter2Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Fighter2Graphic::CREATE:
            if(elapsed_time > TIME[Fighter2Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::NORMAL;
            }
            break;
        case Fighter2Graphic::NORMAL:
            if(elapsed_time > TIME[Fighter2Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::NORMAL;
            }
            break;
        case Fighter2Graphic::HIT1:
            if(elapsed_time > TIME[Fighter2Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::HIT2;
            }
            break;
        case Fighter2Graphic::HIT2:
            if(elapsed_time > TIME[Fighter2Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::NORMAL;
            }
            break;
        case Fighter2Graphic::DESTROY1:
            if(elapsed_time > TIME[Fighter2Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::DESTROY2;
            }
            break;
        case Fighter2Graphic::DESTROY2:
            if(elapsed_time > TIME[Fighter2Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::DESTROY3;
            }
            break;
        case Fighter2Graphic::DESTROY3:
            if(elapsed_time > TIME[Fighter2Graphic::DESTROY3])
            {
                elapsed_time = 0;
                status = Fighter2Graphic::DESTROY_FINISH;
            }
            break;
        case Fighter2Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Fighter2Graphic::DESTROY_FINISH])
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

Point Fighter2Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Fighter2Graphic::InitFighter2()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/player_images/player2.png");
    pics[HIT1]           = new QImage(":/images/Images/player_images/player2_hit1.png");
    pics[HIT2]           = new QImage(":/images/Images/player_images/player2_hit2.png");
    pics[DESTROY1]       = new QImage(":/images/Images/player_images/player_destroy1.png");
    pics[DESTROY2]       = new QImage(":/images/Images/player_images/player_destroy2.png");
    pics[DESTROY3]       = new QImage(":/images/Images/player_images/player_destroy3.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.1;
    TIME[HIT2]           = 0.1;
    TIME[DESTROY1]       = 0.3;
    TIME[DESTROY2]       = 0.3;
    TIME[DESTROY3]       = 0.3;
    TIME[DESTROY_FINISH] = 0;
}
