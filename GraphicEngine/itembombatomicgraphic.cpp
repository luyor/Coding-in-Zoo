#include "itembombatomicgraphic.h"
#include "res.h"
#include <QMatrix>

QImage* ItemBombAtomicGraphic::pics[] = {NULL};

double ItemBombAtomicGraphic::TIME[] = {0};

ItemBombAtomicGraphic::ItemBombAtomicGraphic():node(Point(0,0),QPixmap()),status(NORMAL)
{

}

Point ItemBombAtomicGraphic::Size()
{
    if(pics[status] == NULL) return Point(0,0);
    return Point(pics[status]->width(),pics[status]->height());
}

void ItemBombAtomicGraphic::Paint(Point position,Point velocity,double angle,double time)
{
    QMatrix matrix;
    QImage* img;
    image_to_show = new QImage;
    elapsed_time += time;
    if(sig == Graphic::CREATE)  status = ItemBombAtomicGraphic::CREATE;
    if(sig == Graphic::DESTROY) status = ItemBombAtomicGraphic::DESTROY;
    if(sig == Graphic::NO_SIGNAL)
    {
        switch(status)
        {
        case ItemBombAtomicGraphic::CREATE:
            if(elapsed_time > TIME[ItemBombAtomicGraphic::CREATE])
            {
                elapsed_time = 0;
                status = ItemBombAtomicGraphic::NORMAL;
            }
            break;
        case ItemBombAtomicGraphic::NORMAL:
            if(elapsed_time > TIME[ItemBombAtomicGraphic::NORMAL])
            {
                elapsed_time = 0;
                status = ItemBombAtomicGraphic::NORMAL;
            }
            break;
        case ItemBombAtomicGraphic::DESTROY:
            if(elapsed_time > TIME[ItemBombAtomicGraphic::DESTROY])
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

void ItemBombAtomicGraphic::InitItemBombAtomic()
{
    pics[CREATE]         = NULL;
    pics[NORMAL]         = new QImage(":/images/images/item_image/ItemBombAtomic.png");
    pics[DESTROY]        = NULL;

    TIME[CREATE]  = 0;
    TIME[NORMAL]  = 0;
    TIME[DESTROY] = 0;
}
