#include "boss1graphic.h"
#include "res.h"
#include <QMatrix>

QImage* Boss1Graphic::pics[] = {
    NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL
};

double Boss1Graphic::TIME[] = {0};

Boss1Graphic::Boss1Graphic():node(Point(0,0),QPixmap()),status(EMPTY)
{

}

void Boss1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    //cout<< sig << "  " << elapsed_time << "    " << time <<endl;
    if(sig == Graphic::CREATE)  status = Boss1Graphic::CREATE;
    if(sig == Graphic::HIT)     status = Boss1Graphic::HIT1;
    if(sig == Graphic::DESTROY) status = Boss1Graphic::DESTROY1;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case Boss1Graphic::CREATE:
            if(elapsed_time > TIME[Boss1Graphic::CREATE])
            {
                elapsed_time = 0;
                status = Boss1Graphic::NORMAL;
            }
            break;
        case Boss1Graphic::NORMAL:
            if(elapsed_time > TIME[Boss1Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = Boss1Graphic::NORMAL;
            }
            break;
        case Boss1Graphic::HIT1:
            if(elapsed_time > TIME[Boss1Graphic::HIT1])
            {
                elapsed_time = 0;
                status = Boss1Graphic::HIT2;
            }
            break;
        case Boss1Graphic::HIT2:
            if(elapsed_time > TIME[Boss1Graphic::HIT2])
            {
                elapsed_time = 0;
                status = Boss1Graphic::NORMAL;
            }
            break;
        case Boss1Graphic::DESTROY1:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY1])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY2;
            }
            break;
        case Boss1Graphic::DESTROY2:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY2])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY3;
            }
            break;
        case Boss1Graphic::DESTROY3:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY3])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY4;
            }
            break;
        case Boss1Graphic::DESTROY4:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY4])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY5;
            }
            break;
        case Boss1Graphic::DESTROY5:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY5])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY6;
            }
            break;
        case Boss1Graphic::DESTROY6:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY6])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY7;
            }
            break;
        case Boss1Graphic::DESTROY7:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY7])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY8;
            }
            break;
        case Boss1Graphic::DESTROY8:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY8])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY9;
            }
            break;
        case Boss1Graphic::DESTROY9:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY9])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY10;
            }
            break;
        case Boss1Graphic::DESTROY10:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY10])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY11;
            }
            break;
        case Boss1Graphic::DESTROY11:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY11])
            {
                elapsed_time = 0;
                status = Boss1Graphic::DESTROY_FINISH;
            }
            break;
            
            
        case Boss1Graphic::DESTROY_FINISH:
            if(elapsed_time > TIME[Boss1Graphic::DESTROY_FINISH])
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

Point Boss1Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void Boss1Graphic::InitBoss1()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/enemy_images/Boss1.png");
    pics[HIT1]           = new QImage(":/images/images/enemy_images/Boss1_hit1.png");
    pics[HIT2]           = new QImage(":/images/images/enemy_images/Boss1_hit2.png");
    pics[DESTROY1]       = new QImage(":/images/images/enemy_images/Boss_destroy1.png");
    pics[DESTROY2]       = new QImage(":/images/images/enemy_images/Boss_destroy2.png");
    pics[DESTROY3]       = new QImage(":/images/images/enemy_images/Boss_destroy3.png");
    pics[DESTROY4]       = new QImage(":/images/images/enemy_images/Boss_destroy4.png");
    pics[DESTROY5]       = new QImage(":/images/images/enemy_images/Boss_destroy5.png");
    pics[DESTROY6]       = new QImage(":/images/images/enemy_images/Boss_destroy6.png");
    pics[DESTROY7]       = new QImage(":/images/images/enemy_images/Boss_destroy7.png");
    pics[DESTROY8]       = new QImage(":/images/images/enemy_images/Boss_destroy8.png");
    pics[DESTROY9]       = new QImage(":/images/images/enemy_images/Boss_destroy9.png");
    pics[DESTROY10]       = new QImage(":/images/images/enemy_images/Boss_destroy10.png");
    pics[DESTROY11]       = new QImage(":/images/images/enemy_images/Boss_destroy11.png");
    pics[DESTROY_FINISH] = NULL;
    TIME[CREATE]         = 0;
    TIME[NORMAL]         = 0;
    TIME[HIT1]           = 0.1;
    TIME[HIT2]           = 0.1;
    TIME[DESTROY1]       = 0.1;
    TIME[DESTROY2]       = 0.1;
    TIME[DESTROY3]       = 0.1;
    TIME[DESTROY4]       = 0.1;
    TIME[DESTROY5]       = 0.1;
    TIME[DESTROY6]       = 0.1;
    TIME[DESTROY7]       = 0.1;
    TIME[DESTROY8]       = 0.1;
    TIME[DESTROY9]       = 0.1;
    TIME[DESTROY10]       = 0.1;
    TIME[DESTROY11]       = 0.1;
    TIME[DESTROY_FINISH] = 0;
}
