#include "boss2.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double max_turn_angle = M_PI / 72.0;
const double DELTA = 0.0001;
const double RADIX = 120;
const double STAY_RATIO = 0.86;
const double SPEED = 100;
const double SLOW_BULLET = 120;
const double NORMAL_BULLET = 140;
const double FAST_BULLET = 190;

HitPoint boss2_hitpoint;

void Boss2::ChangeStatus(double time, Game &my_game)
{
    switch (status) {
    case -1:
        velocity = Point(0,-80);
        angle = -M_PI/2;
        if (position.y < STAY_RATIO*data.PAINT_AREA_TOP_RIGHT.y) {
            status = 0;
            if (rand() % 100 < 50) velocity = Point(-SPEED,0);
            else velocity = Point(SPEED,0);
        }
        break;
    case 0:
        stay_time += time;
        fire_time += time;
        if (position.x < 0.2*data.PAINT_AREA_TOP_RIGHT.x) velocity = Point(SPEED,0);
        if (position.x > 0.8*data.PAINT_AREA_TOP_RIGHT.x) velocity = Point(-SPEED,0);
        if (fire_time > 1) Fire(my_game);
        if (stay_time > 5) {
            if (tar == 0) tar = my_game.SelectNearestFighter(position);
            if (tar != 0 && tar->IsDestroyed()) tar = my_game.SelectNearestFighter(position);
            if (tar != 0 && !(tar->IsDestroyed()) && fabs(tar->GetPosition().x - position.x) < 100) {
                status = 1;
                velocity = Point(SPEED,-SLOW_BULLET);
                stay_time = 0;
                fire_time = 0;
            }
        }
        break;
    case 1:
        stay_time += time;
        fire_time += time;
        if (tar == 0 || tar->IsDestroyed()) {
            status = 2;
            velocity = Point(0,SLOW_BULLET);
            stay_time = 0;
            fire_time = 0;
            break;
        }
        if (fire_time > 0.2) Fire(my_game);
        if ((position.x <= RADIX + 20 + DELTA) || (position.x >= data.PAINT_AREA_TOP_RIGHT.x - (RADIX + 20) - DELTA)) 
            velocity = Point(-velocity.x,velocity.y);
        if (position.y < (1-STAY_RATIO)*data.PAINT_AREA_TOP_RIGHT.y) {
            velocity = Point(0,SLOW_BULLET);
            status = 2;
            stay_time = 0;
            fire_time = 0;
        }
        break;
    case 2:
        stay_time += time;
        fire_time += time;
        if (fire_time > 1) Fire(my_game);
        if (position.y > (STAY_RATIO)*data.PAINT_AREA_TOP_RIGHT.y) {
            if (rand() % 100 < 50) velocity = Point(-SPEED,0);
            else velocity = Point(SPEED,0);
            status = 0;
            stay_time = 0;
            fire_time = 0;
        }
        break;
    }
}

void Boss2::Fire(Game &my_game)
{
    Point v_b(0,0);
    Point p_b(0,0);
    Bullet *x1,*x2,*x3,*x4,*x5,*x6,*x7;
    Enemy *y1,*y2;
    double v_angle;
    switch (status) {
    case 0:
    case 2:
        v_angle = -M_PI/2.0 - M_PI/4.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x1=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x1);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x2=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x2);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x3=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x3);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x4=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x4);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x5=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x5);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x6=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x6);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x7=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x7);
        break;
    case 1:
        v_b = Point(0,-FAST_BULLET);
        p_b = Point(position.x + 5, position.y - 2);
        x1=new Bullet(v_b, p_b, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x1);

        p_b = Point(position.x - 5, position.y - 2);
        x2=new Bullet(v_b, p_b, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x2);
        break;
    }
    fire_time = 0;
}

void Boss2::Destroy()
{
}

void Boss2::Init()
{
    double r = 60;
    double a = 0;
    Circle tmp(0,0,r);
    boss2_hitpoint.AddCircle(tmp);
    a += r;
    r = 23;
    Circle tmp11(20, a,r);
    Circle tmp12(20,-a,r);
    boss2_hitpoint.AddCircle(tmp11);
    boss2_hitpoint.AddCircle(tmp12);
    a += r;
    Circle tmp21(20, a,r);
    Circle tmp22(20,-a,r);
    boss2_hitpoint.AddCircle(tmp21);
    boss2_hitpoint.AddCircle(tmp22);
    r = 36;
    Circle tmp3(30,0,r);
    boss2_hitpoint.AddCircle(tmp3);
}
