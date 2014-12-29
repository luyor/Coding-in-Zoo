#include "enemy1graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Enemy1Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Enemy1Graphic::TIME[] = {0};

Enemy1Graphic::Enemy1Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Enemy1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Enemy1Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Enemy1Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Enemy1Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Enemy1Graphic::CREATE:
            if(elapsed_time > TIME[Enemy1Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::NORMAL;
            }
            break;
        case Enemy1Graphic::NORMAL:
            if(elapsed_time > TIME[Enemy1Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::NORMAL;
            }
            break;
        case Enemy1Graphic::HIT1:
            if(elapsed_time > TIME[Enemy1Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::HIT2;
            }
            break;
        case Enemy1Graphic::HIT2:
            if(elapsed_time > TIME[Enemy1Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::NORMAL;
            }
            break;
        case Enemy1Graphic::DESTROY1:
            if(elapsed_time > TIME[Enemy1Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::DESTROY2;
            }
            break;
        case Enemy1Graphic::DESTROY2:
            if(elapsed_time > TIME[Enemy1Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Enemy1Graphic::DESTROY_FINISH;
            }
            break;
        case Enemy1Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Enemy1Graphic::DESTROY_FINISH])
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

Point Enemy1Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Enemy1Graphic::InitEnemy1()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("Enemy1.png");
    pics[HIT1]           = new QImage("Enemy1_hit1.png");
    pics[HIT2]           = new QImage("Enemy1_hit2.png");
    pics[DESTROY1]       = new QImage("Enemy1_destroy1.png");
    pics[DESTROY2]       = new QImage("Enemy1_destroy2.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.5;
    TIME[HIT2]           = 0.5;
    TIME[DESTROY1]       = 0.3;
    TIME[DESTROY2]       = 0.3;
    TIME[DESTROY_FINISH] = 0;
}
