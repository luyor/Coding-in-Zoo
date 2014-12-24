#ifndef ENEMYTYPE_H
#define ENEMYTYPE_H

class Enemy;

class Enemy1:public Enemy
{
public:
    Enemy1(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
        : Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
                Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    void ChangeStatus(double time, Game& my_game);
};

class Enemy2:public Enemy
{
public:
    Enemy2(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
        : Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
                Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    void ChangeStatus(double time, Game& my_game);
};

class Enemy3:public Enemy
{
public:
    Enemy3(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
        : Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
                Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    void ChangeStatus(double time, Game& my_game);
};

class Enemy4:public Enemy
{
public:
    Enemy4(Point v, Point p,double angle0,vector<Circle>& hit_point0,
           Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0)
        : Enemy(Point v,Point p,double angle0,vector<Circle>& hit_point0,
                Graphic graphic0,int health0,int HIT_SCORE0,int DESTROY_SCORE0);
    void ChangeStatus(double time, Game& my_game);
};

#endif // ENEMYTYPE_H
