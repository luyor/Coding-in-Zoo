#include "missile.h"

Missile::Missile(Point v,Point p,double angle0,const HitPoint* hit_point0,
                 Graphic graphic0,int damage0,Player* belonging0,Enemy* target0):
    Bullet(v,p,angle0,hit_point0,graphic0,damage0,
           NORMAL,belonging0),target(target0)
{
}

void Missile::ChangeStatus(double time, Game &my_game)
{
    if (target->IsDestroyed())target=NULL;
    if (target!=NULL){
        int dx=target->GetPosition().x-position.x,dy=target->GetPosition().y-position.y;
        angle=atan2(dy,dx);
        velocity.x=SPEED*cos(angle);
        velocity.y=SPEED*sin(angle);
    }
}
