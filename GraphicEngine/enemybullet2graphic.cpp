#include "enemybullet2graphic.h"
#include "res.h"
#include <QMatrix>

QImage* EnemyBullet2Graphic::pics[] = {NULL};

double EnemyBullet2Graphic::TIME[] = {0};

EnemyBullet2Graphic::EnemyBullet2Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point EnemyBullet2Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void EnemyBullet2Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = EnemyBullet2Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = EnemyBullet2Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case EnemyBullet2Graphic::CREATE:
            if(elapsed_time > TIME[EnemyBullet2Graphic::CREATE])
            {
                elapsed_time = 0;
                status = EnemyBullet2Graphic::NORMAL;
            }
            break;
        case EnemyBullet2Graphic::NORMAL:
            if(elapsed_time > TIME[EnemyBullet2Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = EnemyBullet2Graphic::NORMAL;
            }
            break;
        case EnemyBullet2Graphic::DESTROY:
            if(elapsed_time > TIME[EnemyBullet2Graphic::DESTROY])
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

void EnemyBullet2Graphic::InitEnemyBullet2()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/bullet_images/EnemyBullet2.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
