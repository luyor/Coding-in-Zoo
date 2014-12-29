#include "enemybullet1graphic.h"
#include "res.h"
#include <QMatrix>

QImage* EnemyBullet1Graphic::pics[] = {NULL};

double EnemyBullet1Graphic::TIME[] = {0};

EnemyBullet1Graphic::EnemyBullet1Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point EnemyBullet1Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void EnemyBullet1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = EnemyBullet1Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = EnemyBullet1Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case EnemyBullet1Graphic::CREATE:
            if(elapsed_time > TIME[EnemyBullet1Graphic::CREATE])
            {
                elapsed_time = 0;
                status = EnemyBullet1Graphic::NORMAL;
            }
            break;
        case EnemyBullet1Graphic::NORMAL:
            if(elapsed_time > TIME[EnemyBullet1Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = EnemyBullet1Graphic::NORMAL;
            }
            break;
        case EnemyBullet1Graphic::DESTROY:
            if(elapsed_time > TIME[EnemyBullet1Graphic::DESTROY])
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

void EnemyBullet1Graphic::InitEnemyBullet1()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("EnemyBullet1.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
