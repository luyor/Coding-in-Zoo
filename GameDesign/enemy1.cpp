#include "enemy1.h"
#include "../GameEngine/game.h"

const double STAY_RATIO = 0.3;

HitPoint enemy1_hitpoint;

void Enemy1::ChangeStatus(double time, Game &my_game)
{
    double proper_angle;
    fire_time += time;
    if (fabs(velocity.y) > DELTA &&
        position.y < (STAY_RATIO + ((rand() % 11) / 100.0))*data.PAINT_AREA_TOP_RIGHT.y) velocity = Point(0,0);
    // I assume fighters[] started with 0
    if (fabs(velocity.y) < DELTA) {
        if (tar == 0) tar = my_game.SelectRandomFighter();

        proper_angle = AimAt(position, tar->GetPosition());
        if (fabs(proper_angle - angle) < max_turn_angle) angle = proper_angle;
        else {
            if (proper_angle > angle) angle += max_turn_angle;
            else angle -= max_turn_angle;
        }
        if (fabs(proper_angle - angle) < DELTA && fire_time >=0.5) {
            Fire(my_game);
            fire_time = 0;
        }
    }
}

void Enemy1::Fire(Game &my_game)
{
    Point v_b = Point(tar->GetPosition().x - position.x,
                 tar->GetPosition().y - position.y);
    double length = sqrt(v_b.x*v_b.x + v_b.y*v_b.y);
    v_b.x = v_b.x / length * NORMAL_BULLET;
    v_b.y = v_b.y / length * NORMAL_BULLET;
    Bullet *x=new Bullet(v_b, position, angle, &yellow_bullet_hitpoint,new BulletYellowGraphic() , Bullet::NORMAL, 10);
    my_game.EnemyBulletRegister(x);
}

void Enemy1::Init()
{
    Circle tmp(0,0,30);
    enemy1_hitpoint.AddCircle(tmp);
}
