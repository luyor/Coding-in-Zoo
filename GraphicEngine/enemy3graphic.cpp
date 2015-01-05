#include "enemy3graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Enemy3Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Enemy3Graphic::TIME[] = {0};

Enemy3Graphic::Enemy3Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Enemy3Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Enemy3Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Enemy3Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Enemy3Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Enemy3Graphic::CREATE:
            if(elapsed_time > TIME[Enemy3Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::NORMAL;
            }
            break;
        case Enemy3Graphic::NORMAL:
            if(elapsed_time > TIME[Enemy3Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::NORMAL;
            }
            break;
        case Enemy3Graphic::HIT1:
            if(elapsed_time > TIME[Enemy3Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::HIT2;
            }
            break;
        case Enemy3Graphic::HIT2:
            if(elapsed_time > TIME[Enemy3Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::NORMAL;
            }
            break;
        case Enemy3Graphic::DESTROY1:
            if(elapsed_time > TIME[Enemy3Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::DESTROY2;
            }
            break;
        case Enemy3Graphic::DESTROY2:
            if(elapsed_time > TIME[Enemy3Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Enemy3Graphic::DESTROY_FINISH;
            }
            break;
        case Enemy3Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Enemy3Graphic::DESTROY_FINISH])
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

Point Enemy3Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Enemy3Graphic::InitEnemy2()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/Images/enemy_images/Enemy3.png");
    pics[HIT1]           = new QImage(":/images/Images/enemy_images/Enemy3_hit1.png");
    pics[HIT2]           = new QImage(":/images/Images/enemy_images/Enemy3_hit2.png");
    pics[DESTROY1]       = new QImage(":/images/Images/enemy_images/Enemy3_destroy1.png");
    pics[DESTROY2]       = new QImage(":/images/Images/enemy_images/Enemy3_destroy2.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.1;
    TIME[HIT2]           = 0.1;
    TIME[DESTROY1]       = 0.3;
    TIME[DESTROY2]       = 0.3;
    TIME[DESTROY_FINISH] = 0;
}
