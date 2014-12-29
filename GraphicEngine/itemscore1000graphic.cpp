#include "itemscore1000graphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemScore1000Graphic::pics[] = {NULL};

double ItemScore1000Graphic::TIME[] = {0};

ItemScore1000Graphic::ItemScore1000Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point ItemScore1000Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemScore1000Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemScore1000Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = ItemScore1000Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemScore1000Graphic::CREATE:
            if(elapsed_time > TIME[ItemScore1000Graphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemScore1000Graphic::NORMAL;
            }
            break;
        case ItemScore1000Graphic::NORMAL:
            if(elapsed_time > TIME[ItemScore1000Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = ItemScore1000Graphic::NORMAL;
            }
            break;
        case ItemScore1000Graphic::DESTROY:
            if(elapsed_time > TIME[ItemScore1000Graphic::DESTROY])
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

void ItemScore1000Graphic::InitItemScore1000()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage("ItemScore1000.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
