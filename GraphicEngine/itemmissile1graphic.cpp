#include "itemmissile1graphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemMissile1Graphic::pics[] = {NULL};

double ItemMissile1Graphic::TIME[] = {0};

ItemMissile1Graphic::ItemMissile1Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point ItemMissile1Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemMissile1Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemMissile1Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = ItemMissile1Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemMissile1Graphic::CREATE:
            if(elapsed_time > TIME[ItemMissile1Graphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemMissile1Graphic::NORMAL;
            }
            break;
        case ItemMissile1Graphic::NORMAL:
            if(elapsed_time > TIME[ItemMissile1Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = ItemMissile1Graphic::NORMAL;
            }
            break;
        case ItemMissile1Graphic::DESTROY:
            if(elapsed_time > TIME[ItemMissile1Graphic::DESTROY])
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

void ItemMissile1Graphic::InitItemMissile1()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/item_image/ItemMissile1.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
