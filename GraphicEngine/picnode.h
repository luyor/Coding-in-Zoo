#ifndef PICNODE_H
#define PICNODE_H

#include "../General/point.h"
#include <QPixmap>

class PicNode
{
public:
    PicNode(Point p, QPixmap q);
    Point position;
    QPixmap pixmap;
};

#endif // PICNODE_H
