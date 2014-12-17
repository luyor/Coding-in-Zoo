#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle:public Point
{
public:
    Circle(double x0,double y0,double r):Point(x0,y0),radius(r){}
    double radius;
};

#endif // CIRCLE_H
