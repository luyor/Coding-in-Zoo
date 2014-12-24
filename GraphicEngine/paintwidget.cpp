#include "paintwidget.h"


PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
   connect(&graphic_engine,SIGNAL(Update()),this,SLOT(PaintFrame()));
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    cout<<"successful   "<< graphic_engine.pics_to_show.size()<<endl;
    QPainter painter(this);
    vector<PicNode>::iterator iter = graphic_engine.pics_to_show.begin();
    for(;iter != graphic_engine.pics_to_show.end();iter++)
    {
        cout<<"NULL?"<<iter->pixmap.isNull()<<endl;
        painter.drawPixmap((int)iter->position.x, (int)(this->height() - iter->position.y), iter->pixmap);
    }
    graphic_engine.pics_to_show.clear();
}

