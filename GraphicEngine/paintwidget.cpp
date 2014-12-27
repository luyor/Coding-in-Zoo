#include "paintwidget.h"


PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
   connect(&graphic_engine,SIGNAL(Update()),this,SLOT(PaintFrame()));
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    //cout<<"successful   "<< graphic_engine.pics_to_show.size()<<endl;
    QPainter painter(this);
    vector<PicNode>::iterator iter = graphic_engine.pics_to_show.begin();
    for(;iter != graphic_engine.pics_to_show.end();iter++)
    {
        //cout<<this->height()<<endl;
        //cout<<this->height() - iter->position.y + iter->pixmap.height()<<endl;
        painter.drawPixmap((int)(iter->position.x-iter->pixmap.width()/2),
                           (int)(this->height() - iter->position.y - iter->pixmap.height()/2), iter->pixmap);
    }
    graphic_engine.pics_to_show.clear();
}

