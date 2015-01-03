#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QSound>
#include"../stdafx.h"
#include "graphicengine.h"
#include "soundengine.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = 0);
    SoundEngine se;
protected:
    void paintEvent(QPaintEvent* event);
public slots:
    void PaintFrame(){update();}
};

#endif // PAINTWIDGET_H
