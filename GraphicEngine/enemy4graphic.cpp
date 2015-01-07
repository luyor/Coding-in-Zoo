#include "enemy4graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Enemy4Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Enemy4Graphic::TIME[] = {0};

Enemy4Graphic::Enemy4Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Enemy4Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Enemy4Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Enemy4Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Enemy4Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Enemy4Graphic::CREATE:
            if(elapsed_time > TIME[Enemy4Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::NORMAL;
            }
            break;
        case Enemy4Graphic::NORMAL:
            if(elapsed_time > TIME[Enemy4Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::NORMAL;
            }
            break;
        case Enemy4Graphic::HIT1:
            if(elapsed_time > TIME[Enemy4Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::HIT2;
            }
            break;
        case Enemy4Graphic::HIT2:
            if(elapsed_time > TIME[Enemy4Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::NORMAL;
            }
            break;
        case Enemy4Graphic::DESTROY1:
            if(elapsed_time > TIME[Enemy4Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::DESTROY2;
            }
            break;
        case Enemy4Graphic::DESTROY2:
            if(elapsed_time > TIME[Enemy4Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Enemy4Graphic::DESTROY_FINISH;
            }
            break;
        case Enemy4Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Enemy4Graphic::DESTROY_FINISH])
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

Point Enemy4Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Enemy4Graphic::InitEnemy4()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/enemy_images/Enemy4.png");
    pics[HIT1]           = new QImage(":/images/images/enemy_images/Enemy4_hit1.png");
    pics[HIT2]           = new QImage(":/images/images/enemy_images/Enemy4_hit2.png");
    pics[DESTROY1]       = new QImage(":/images/images/enemy_images/Enemy4_destroy1.png");
    pics[DESTROY2]       = new QImage(":/images/images/enemy_images/Enemy4_destroy2.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.1;
    TIME[HIT2]           = 0.1;
    TIME[DESTROY1]       = 0.3;
    TIME[DESTROY2]       = 0.3;
    TIME[DESTROY_FINISH] = 0;
}
