#include "enemy2.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
#include "../GraphicEngine/enemybullet2graphic.h"
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/itemscore1000graphic.h"
#include "../GraphicEngine/itemmissile1graphic.h"
#include "../GraphicEngine/itembombatomicgraphic.h"
#include "../GraphicEngine/itemscore1000graphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double STAY_RATIO = 0.30;

HitPoint enemy2_hitpoint;

void Enemy2::ChangeStatus(double time, Game &my_game)
{
    //Enemy2 should be initially with velocity(0,y)
    if (fabs(velocity.y) > DELTA &&
        (data.PAINT_AREA_TOP_RIGHT.y - position.y) > (STAY_RATIO - ((rand() % 11) / 100.0))*data.PAINT_AREA_TOP_RIGHT.y) {
        if (rand() % 100 < 50) velocity = Point(-SPEED,0);
        else velocity = Point(SPEED,0);
    }
    if (fabs(velocity.y) < DELTA) {
        if (position.x < 0.2*data.PAINT_AREA_TOP_RIGHT.x) velocity = Point(SPEED,0);
        if (position.x > 0.8*data.PAINT_AREA_TOP_RIGHT.x) velocity = Point(-SPEED,0);
        fire_time += time;
        if (fire_time >= 2.6) {
            Fire(my_game);
            fire_time = 0;
        }
    }
}

void Enemy2::Fire(Game &my_game)
{
    double v_angle = angle - M_PI/6.0;
    Point v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
    Bullet *x1=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet2Graphic() , Bullet::NORMAL, 50);
    my_game.EnemyBulletRegister(x1);

    v_angle += M_PI/12.0;
    v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
    Bullet *x2=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet2Graphic() , Bullet::NORMAL, 50);
    my_game.EnemyBulletRegister(x2);

    v_angle += M_PI/12.0;
    v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
    Bullet *x3=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet2Graphic() , Bullet::NORMAL, 50);
    my_game.EnemyBulletRegister(x3);

    v_angle += M_PI/12.0;
    v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
    Bullet *x4=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet2Graphic() , Bullet::NORMAL, 50);
    my_game.EnemyBulletRegister(x4);

    v_angle += M_PI/12.0;
    v_b = Point(cos(v_angle)*SLOW_BULLET, sin(v_angle)*SLOW_BULLET);
    Bullet *x5=new Bullet(v_b, position, angle, &enemy_bullet_hitpoint,new EnemyBullet2Graphic() , Bullet::NORMAL, 50);
    my_game.EnemyBulletRegister(x5);
}

void Enemy2::Destroy()
{
    int p = rand() % 100;
    if (p < 50) {
        Item *i=new Item(Point(0,0),position,M_PI/2,&item_hitpoint,new ItemBulletLvupGraphic(),Item::YELLOW_BULLET);
        game.ItemRegister(i);
    }
    else {
        if (p < 60) {
            Item *i=new Item(Point(0,0),position,M_PI/2,&item_hitpoint,new ItemMissile1Graphic(),Item::TRACKING_MISSILE);
            game.ItemRegister(i);
        }
        else {
            if (p < 70) {
                Item *i=new Item(Point(0,0),position,M_PI/2,&item_hitpoint,new ItemBombAtomicGraphic(),Item::ATOMIC_BOMB);
                game.ItemRegister(i);
            }
            else {
                if (p < 85) {
                    Item *i=new Item(Point(0,0),position,M_PI/2,&item_hitpoint,new ItemScore1000Graphic(),Item::ADD_SCORE_1000);
                    game.ItemRegister(i);
                }
            }
        }
    }
}

void Enemy2::Init()
{
    //Caution, enemy2 is bigger than enemy1
    Circle tmp(0,0,30);
    enemy2_hitpoint.AddCircle(tmp);
    double r = 10;
    double po = sqrt(120*r);
    Circle tmp2(r-30,po,r);
    enemy2_hitpoint.AddCircle(tmp2);
    Circle tmp3(r-30,-po,r);
    enemy2_hitpoint.AddCircle(tmp3);
}
