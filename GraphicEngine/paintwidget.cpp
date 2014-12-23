#include "paintwidget.h"
#include"../stdafx.h"

PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent)
{
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    vector<PicNode>::iterator iter = graphic_engine.pics_to_show.begin();
    for(;iter != graphic_engine.pics_to_show.end();iter++)
        painter.drawPixmap(iter->position.x, iter->position.y, iter->pixmap);
}
