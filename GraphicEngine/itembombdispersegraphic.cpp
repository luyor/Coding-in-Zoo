#include "itembombdispersegraphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemBombDisperseGraphic::pics[] = {NULL};

double ItemBombDisperseGraphic::TIME[] = {0};

ItemBombDisperseGraphic::ItemBombDisperseGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point ItemBombDisperseGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemBombDisperseGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemBombDisperseGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = ItemBombDisperseGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemBombDisperseGraphic::CREATE:
            if(elapsed_time > TIME[ItemBombDisperseGraphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemBombDisperseGraphic::NORMAL;
            }
            break;
        case ItemBombDisperseGraphic::NORMAL:
            if(elapsed_time > TIME[ItemBombDisperseGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = ItemBombDisperseGraphic::NORMAL;
            }
            break;
        case ItemBombDisperseGraphic::DESTROY:
            if(elapsed_time > TIME[ItemBombDisperseGraphic::DESTROY])
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

void ItemBombDisperseGraphic::InitItemBombDisperse()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/item_image/ItemBombDisperse.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
