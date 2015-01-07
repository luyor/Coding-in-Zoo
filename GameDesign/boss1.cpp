#include "boss1.h"
#include "boss3.h"
#include "enemy3.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
#include "../GraphicEngine/enemybullet3graphic.h"
#include "../GraphicEngine/enemy3graphic.h"
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double max_turn_angle = M_PI / 72.0;
const double DELTA = 0.0001;
const double GAP = 10;
const double STAY_RATIO = 0.86;
const double SPEED = 40;
const double SLOW_BULLET = 80;
const double NORMAL_BULLET = 100;
const double FAST_BULLET = 190;

HitPoint boss1_hitpoint;

void Boss1::ChangeStatus(double time, Game &my_game)
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
        if (stay_time > 10) {
            int k = rand() % 100;
            if (k < 50) {
                status = 2;
                velocity = Point(0,0);
            }
            else status = 1;
            stay_time = 0;
            fire_time = 0;
        }
        break;
    case 1:
        stay_time += time;
        fire_time += time;
        if (fire_time > 0.5) Fire(my_game);
        if (position.y > (1-STAY_RATIO)*data.PAINT_AREA_TOP_RIGHT.y) {
            if (fabs(velocity.y) < DELTA) velocity = Point(0, 20 - FAST_BULLET);
            else {
                if (velocity.y < -DELTA) {
                    //FAST_BULLET
                }
                else {
                    if (position.y > STAY_RATIO*data.PAINT_AREA_TOP_RIGHT.y) {
                        if (rand() % 100 < 50) velocity = Point(-SPEED,0);
                        else velocity = Point(SPEED,0);
                        status = 0;
                        stay_time = 0;
                        fire_time = 0;
                    }
                }
            }
        }
        else {
            if (velocity.y < -DELTA) {
                stay_time = 0;
                velocity = Point(0,0);
            }
            else {
                if (fabs(velocity.y) < DELTA) {
                    if (stay_time > 1.5) {
                        velocity = Point(0,90);
                    }
                }
            }
        }
        break;
    case 2:
        fire_time += time;
        if (fabs(velocity.x) < DELTA) {
            if (rand() % 100 < 50) velocity = Point(-SPEED*7,0);
            else velocity = Point(SPEED*7,0);
        }
        if (position.x < 0.2*data.PAINT_AREA_TOP_RIGHT.x && velocity.x < -DELTA) {
            velocity = Point(SPEED*7,0);
            stay_time += 1;
        }
        if (position.x > 0.8*data.PAINT_AREA_TOP_RIGHT.x && velocity.x > DELTA) {
            velocity = Point(-SPEED*7,0);
            stay_time += 1;
        }
        if (fire_time > 0.13) Fire(my_game);
        if (stay_time >= 2+DELTA) {
            status = 0;
            stay_time = 0;
            fire_time = 0;
        }
        break;
    }
}

void Boss1::Fire(Game &my_game)
{
    Point v_b(0,0);
    Point p_b(0,0);
    Bullet *x1,*x2,*x3,*x4,*x5,*x6,*x7;
    Enemy *y1,*y2;
    double v_angle;
    position.y -= 30;
    switch (status) {
    case 0:
        v_angle = -M_PI/2.0 - M_PI/4.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x1=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x1);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x2=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x2);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x3=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x3);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x4=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x4);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x5=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x5);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x6=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x6);

        v_angle += M_PI/12.0;
        v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
        x7=new Bullet(v_b, position, v_angle, &enemy_bullet_hitpoint,new EnemyBullet3Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x7);
        break;
    case 1:
        v_b = Point(0,-FAST_BULLET);
        p_b = Point(position.x + GAP, position.y - 5);
        x1=new Bullet(v_b, p_b, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x1);

        p_b = Point(position.x - GAP, position.y - 5);
        x2=new Bullet(v_b, p_b, angle, &enemy_bullet_hitpoint,new EnemyBullet1Graphic() , Bullet::NORMAL, 10);
        my_game.EnemyBulletRegister(x2);
        break;
    case 2:
        v_b = Point(0,-FAST_BULLET);
        p_b = Point(position.x + GAP, position.y - 5);
        x1 = new Bullet(v_b, p_b, angle, &enemy3_hitpoint,new Enemy3Graphic() , Bullet::NORMAL, 1000);
        my_game.EnemyBulletRegister(x1);

        p_b = Point(position.x - GAP, position.y - 5);
        x2 = new Bullet(v_b, p_b, angle, &enemy3_hitpoint,new Enemy3Graphic() , Bullet::NORMAL, 1000);
        my_game.EnemyBulletRegister(x2);
        break;
    }
    position.y += 30;
    fire_time = 0;
}

void Boss1::Destroy()
{
    Enemy *i = new Boss3(Point(0,0), position, M_PI/2, &boss3_hitpoint, 4000, 100, 20000);
    game.EnemyRegister(i);
}

void Boss1::Init()
{
    Circle tmp(0,0,25);
    boss1_hitpoint.AddCircle(tmp);
    double r = 34;
    double a = 48;
    Circle tmp11(-a/2,  25 + a/2 , r);
    boss1_hitpoint.AddCircle(tmp11);
    Circle tmp12(-a/2,-(25 + a/2), r);
    boss1_hitpoint.AddCircle(tmp12);
    r = 25;
    a = 42;
    Circle tmp21(a/2,  25 + a/2 , r);
    boss1_hitpoint.AddCircle(tmp21);
    Circle tmp22(a/2,-(25 + a/2), r);
    boss1_hitpoint.AddCircle(tmp22);
    r = 24;
    Circle tmp31(3*a/2,  25 + a/2 , r);
    boss1_hitpoint.AddCircle(tmp31);
    Circle tmp32(3*a/2,-(25 + a/2), r);
    boss1_hitpoint.AddCircle(tmp32);
}
