#include "picnode.h"
#include "../stdafx.h"

PicNode::PicNode(Point p, QPixmap q): position(p),pixmap(q)
{
    cout<<"picnode   "<<p.x <<"   "<<p.y<<endl;
}
