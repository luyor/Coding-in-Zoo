#include "enemy4.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/itemscore1000graphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double STAY_RATIO = 0.82;
const double DELTA = 0.0001;
const double SPEED = 180;

HitPoint enemy4_hitpoint;

void Enemy4::ChangeStatus(double time, Game &my_game)
{
    if (fabs(suicideangle) < DELTA) {
        if (fabs(velocity.y) > DELTA &&
            position.y < (STAY_RATIO + ((rand() % 11) / 100.0))*data.PAINT_AREA_TOP_RIGHT.y) velocity = Point(0,0);

        if (fabs(velocity.y) < DELTA) {
            tar = my_game.SelectNearestFighter(position);
            if (tar == NULL || tar->IsDestroyed()) {
                suicideangle = -M_PI/2;
                angle = suicideangle;
                velocity = Point(0,-100);
            }
            else {
                suicideangle = AimAt(position, tar->GetPosition());
                angle = suicideangle;
                Point v(tar->GetPosition().x - position.x, tar->GetPosition().y - position.y);
                double length = sqrt(v.x*v.x + v.y*v.y);
                v.x = v.x / length * SPEED;
                v.y = v.y / length * SPEED;
                velocity = v;
            }
        }
    }
}

void Enemy4::Fire(Game &my_game)
{
}

void Enemy4::Destroy()
{
}

void Enemy4::Init()
{
    //Enemy4 is smaller than enemy1 but bigger than enemy3
    Circle tmp(0,0,20);
    enemy4_hitpoint.AddCircle(tmp);
}
