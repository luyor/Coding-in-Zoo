#ifndef ENEMYTYPE_H
#define ENEMYTYPE_H

class Enemy;

class Enemy1:public Enemy
{
public:
    Enemy1(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
        : Enemy(Point v, Point p,
};

#endif // ENEMYTYPE_H
