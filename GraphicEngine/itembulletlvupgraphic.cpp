#include "itembulletLvupgraphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemBulletLvupGraphic::pics[] = {NULL};

double ItemBulletLvupGraphic::TIME[] = {0};

ItemBulletLvupGraphic::ItemBulletLvupGraphic():node(Point(0,0),QPixmap()),status(NORMAL1),order(0)
{

}

Point ItemBulletLvupGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemBulletLvupGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemBulletLvupGraphic::CREATE;
    if(sig == Graphic::HIT){
        order++;
        if(order >= 3) order = 0;
        switch(order)
        {
        case 0:
            status = ItemBulletLvupGraphic::NORMAL1;break;
        case 1:
            status = ItemBulletLvupGraphic::NORMAL2;break;
        case 2:
            status = ItemBulletLvupGraphic::NORMAL3;break;
        }

    }
    if(sig == Graphic::DESTROY) status = ItemBulletLvupGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemBulletLvupGraphic::CREATE:
            if(elapsed_time > TIME[ItemBulletLvupGraphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemBulletLvupGraphic::NORMAL1;
            }
            break;
        case ItemBulletLvupGraphic::NORMAL1:
            if(elapsed_time > TIME[ItemBulletLvupGraphic::NORMAL1])
            {
                elapsed_time = 0;
                status = ItemBulletLvupGraphic::NORMAL1;
            }
            break;
        case ItemBulletLvupGraphic::NORMAL2:
            if(elapsed_time > TIME[ItemBulletLvupGraphic::NORMAL2])
            {
                elapsed_time = 0;
                status = ItemBulletLvupGraphic::NORMAL2;
            }
            break;
        case ItemBulletLvupGraphic::NORMAL3:
            if(elapsed_time > TIME[ItemBulletLvupGraphic::NORMAL3])
            {
                elapsed_time = 0;
                status = ItemBulletLvupGraphic::NORMAL3;
            }
            break;
        case ItemBulletLvupGraphic::DESTROY:
            if(elapsed_time > TIME[ItemBulletLvupGraphic::DESTROY])
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

void ItemBulletLvupGraphic::InitItemBulletLvup()
{
    pics[CREATE]         = NULL;
    pics[NORMAL1]        = new QImage(":/images/Images/item_image/ItemBulletLvup1.png");
    pics[NORMAL2]        = new QImage(":/images/Images/item_image/ItemBulletLvup2.png");
    pics[NORMAL3]        = new QImage(":/images/Images/item_image/ItemBulletLvup3.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL1] = 0;
    TIME[NORMAL2] = 0;
    TIME[NORMAL3] = 0;
    TIME[DESTROY] = 0;
}
