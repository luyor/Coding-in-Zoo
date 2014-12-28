#ifndef HITPOINT_H
#define HITPOINT_H

#include "../stdafx.h"
#include "circle.h"

extern double Distance(Point i,Point j);

class HitPoint
{
public:
    HitPoint();
    void AddCircle(Circle& circle);
    vector<Circle> points;
    double max_distance;
};

#endif // HITPOINT_H
