#include "enemybullet3graphic.h"
#include "res.h"
#include <QMatrix>

QImage* EnemyBullet3Graphic::pics[] = {NULL};

double EnemyBullet3Graphic::TIME[] = {0};

EnemyBullet3Graphic::EnemyBullet3Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point EnemyBullet3Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void EnemyBullet3Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = EnemyBullet3Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = EnemyBullet3Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case EnemyBullet3Graphic::CREATE:
            if(elapsed_time > TIME[EnemyBullet3Graphic::CREATE])
            {
                elapsed_time = 0;
                status = EnemyBullet3Graphic::NORMAL;
            }
            break;
        case EnemyBullet3Graphic::NORMAL:
            if(elapsed_time > TIME[EnemyBullet3Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = EnemyBullet3Graphic::NORMAL;
            }
            break;
        case EnemyBullet3Graphic::DESTROY:
            if(elapsed_time > TIME[EnemyBullet3Graphic::DESTROY])
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

void EnemyBullet3Graphic::InitEnemyBullet3()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/bullet_images/EnemyBullet3.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
