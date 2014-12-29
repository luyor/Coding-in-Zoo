#include "paintwidget.h"
#include "../res.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
   graphic_engine.back_ground = new QPixmap("background.png");
   connect(&graphic_engine,SIGNAL(Update()),this,SLOT(PaintFrame()));
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    extern Data data;
    QPainter painter(this);
    //paint background
    if(graphic_engine.back_ground != NULL)
    {
        int bky1,bky2;

        bky1 = (int)(graphic_engine.back_ground->height()-this->height()-graphic_engine.bk_time * data.BACKGROUND_SPEED);
        if(bky1 <= 0) bky1 = 0;

        bky2 = (int)(graphic_engine.back_ground->height()-graphic_engine.bk_time * data.BACKGROUND_SPEED);
        if(bky2 <= this->height()) bky2 = graphic_engine.back_ground->height();

        painter.drawPixmap(0,0,*graphic_engine.back_ground,
                           0,bky1,
                          this->width(),bky2);
    }

    //paint pics_to_show
    vector<PicNode>::iterator iter = graphic_engine.pics_to_show.begin();
    for(;iter != graphic_engine.pics_to_show.end();iter++)
    {
        painter.drawPixmap((int)(iter->position.x-iter->pixmap.width()/2),
                           (int)(this->height() - iter->position.y - iter->pixmap.height()/2), iter->pixmap);
    }
    graphic_engine.pics_to_show.clear();
}

