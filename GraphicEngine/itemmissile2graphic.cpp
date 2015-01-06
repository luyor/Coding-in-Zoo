#include "itemmissile2graphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemMissile2Graphic::pics[] = {NULL};

double ItemMissile2Graphic::TIME[] = {0};

ItemMissile2Graphic::ItemMissile2Graphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point ItemMissile2Graphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemMissile2Graphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemMissile2Graphic::CREATE;
    if(sig == Graphic::DESTROY) status = ItemMissile2Graphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemMissile2Graphic::CREATE:
            if(elapsed_time > TIME[ItemMissile2Graphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemMissile2Graphic::NORMAL;
            }
            break;
        case ItemMissile2Graphic::NORMAL:
            if(elapsed_time > TIME[ItemMissile2Graphic::NORMAL])
            {
                elapsed_time = 0;
                status = ItemMissile2Graphic::NORMAL;
            }
            break;
        case ItemMissile2Graphic::DESTROY:
            if(elapsed_time > TIME[ItemMissile2Graphic::DESTROY])
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

void ItemMissile2Graphic::InitItemMissile2()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/item_image/ItemMissile2.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
