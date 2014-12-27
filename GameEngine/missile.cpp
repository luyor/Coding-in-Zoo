#include "missile.h"
#include "game.h"

Missile::Missile(double speed0,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,double damage0,
                 Player* belonging0,FlyingObject* target0,double max_turn_angle0,double miss_target_angle0):
    Bullet(Point(0,0),p,angle0,hit_point0,graphic0,NORMAL,damage0,belonging0),target(target0),
    max_turn_angle(max_turn_angle0),speed(speed0),miss_target_angle(miss_target_angle0),turned_angle(0)
{
}

Missile::Missile(double speed0,Point p,double angle0,HitPoint* hit_point0,Graphic *graphic0,double damage0,
        FlyingObject* target0,double max_turn_angle0,double miss_target_angle0):
    Bullet(Point(0,0),p,angle0,hit_point0,graphic0,NORMAL,damage0),target(target0),max_turn_angle(max_turn_angle0),
    speed(speed0),miss_target_angle(miss_target_angle0),turned_angle(0)
{
}

void Missile::ChangeStatus(double time, Game &my_game)
{
    if (target==NULL){
        if (turned_angle<miss_target_angle){
            if (belonging==NULL){
                target=my_game.SelectRandomFighter();
            }else{
                target=my_game.SelectRandomEnemy();
            }
        }
    }else{
        if (turned_angle>=miss_target_angle||target->IsDestroyed()){target=NULL;return;}
        double need_angle=AimAt(position,target->GetPosition());
        double turn_angle=angle-need_angle;
        while (turn_angle>M_PI)turn_angle-=M_PI*2;
        while (turn_angle<-M_PI)turn_angle+=M_PI*2;
        if(fabs(turn_angle)<=max_turn_angle*time){
            angle=need_angle;
        }else{
            if (turn_angle>0){
                turn_angle=max_turn_angle*time;
            }else{
                turn_angle=-max_turn_angle*time;
            }
            angle-=turn_angle;
        }

        turned_angle+=fabs(turn_angle);
        velocity.x=speed*cos(angle);
        velocity.y=speed*sin(angle);
    }
}
