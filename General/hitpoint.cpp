#include "hitpoint.h"

HitPoint::HitPoint():max_distance(0)
{
}

void HitPoint::AddCircle(Circle &circle)
{
    double dis=circle.radius+sqrt(circle.x*circle.x+circle.y*circle.y);
    if (dis>max_distance)max_distance=dis;
    points.push_back(circle);
}

double Distance(Point i,Point j)
{
    int x=i.x-j.x,y=i.y-j.y;
    return sqrt(x*x+y*y);
}
