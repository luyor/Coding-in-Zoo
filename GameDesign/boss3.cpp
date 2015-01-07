#include "boss3.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
//After finishing new bullet type, use new bullet
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double max_turn_angle = M_PI / 72.0;
const double RADIX = 37;
const double DELTA = 0.0001;
const double STAY_RATIO = 0.86;
const double SPEED = 170;
const double SLOW_BULLET = 50;
const double NORMAL_BULLET = 190;
const double FAST_BULLET = 200;

HitPoint boss3_hitpoint;

void Boss3::ChangeStatus(double time, Game &my_game)
{
    switch (status) {
    case -1:
        stay_time += time;
        velocity = Point(0,0);
        angle = -M_PI/2;
        if (stay_time > 1) {
            status = 0;
            double a = (rand() % 315) / 314.0 * M_PI;
            velocity = Point(cos(a) * SPEED, sin(a) * SPEED);
            angle = -M_PI/2;
            stay_time = 0;
            fire_time = 0;
        }
        break;
    case 0:
        stay_time += time;
        fire_time += time;
        if ((position.x <= RADIX + 20 + DELTA) && (velocity.x < -DELTA)) velocity = Point(-velocity.x + DELTA,velocity.y);
        if ((position.x >= data.PAINT_AREA_TOP_RIGHT.x - (RADIX + 20) - DELTA) && (velocity.x > DELTA)) velocity = Point(-velocity.x - DELTA,velocity.y);
        if ((position.y <= RADIX + 20 + DELTA) && (velocity.y < -DELTA)) velocity = Point(velocity.x,-velocity.y + DELTA);
        if ((position.y >= data.PAINT_AREA_TOP_RIGHT.y - (RADIX + 20) - DELTA) && (velocity.y > DELTA)) velocity = Point(velocity.x,-velocity.y - DELTA);
        if (fire_time > 0.08) Fire(my_game);
        break;
    }
}

void Boss3::Fire(Game &my_game)
{
    Point v_b(cos(angle)*NORMAL_BULLET, sin(angle)*NORMAL_BULLET);
    Point p_b(position.x + RADIX*cos(angle), position.y + RADIX*sin(angle));
    Bullet *x1;
    x1=new Bullet(v_b, p_b, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
    my_game.EnemyBulletRegister(x1);
    fire_time = 0;
    angle += 0.2;
    if (angle >= 2*M_PI) angle -= 2*M_PI;
}

void Boss3::Destroy()
{
    //Enemy *i = new Boss3(Point(0,0), position, M_PI/2, &boss2_hitpoint, 1000, 100, 20000);
    //game.EnemyRegister(i);
}

void Boss3::Init()
{
    Circle tmp(0,0,RADIX);
    boss3_hitpoint.AddCircle(tmp);
}
