#include "enemy3.h"
#include "../res.h"
#include "GameEngine/game.h"
#include "../GraphicEngine/enemybullet1graphic.h"
#include "../GraphicEngine/itembulletlvupgraphic.h"
#include "../GraphicEngine/itemscore1000graphic.h"
#include "../GraphicEngine/bulletyellowgraphic.h"

const double STAY_RATIO = 0.3;
const double DELTA = 0.0001;
const double LOW_SPEED = 40;
const double MID_SPEED = 60;
const double HIGH_SPEED = 80;

HitPoint enemy3_hitpoint;

void Enemy3::ChangeStatus(double time, Game &my_game)
{
    Point sun_angle(position.x - sun.x, position.y - sun.y);

    Point nextv(-sun_angle.y, sun_angle.x);
    double length = sqrt(nextv.x * nextv.x + nextv.y * nextv.y);
    nextv.x = nextv.x / length * MID_SPEED;
    nextv.y = nextv.y / length * MID_SPEED;
    velocity = nextv;
    angle = AimAt(Point(0,0),nextv);
    //Caution!
    //It's a special judgement just for this case, if you want to generalize it into more cases
    //DO CHANGE THE IF CONDITION
    if ((velocity.y > 0 || velocity.x < 0) && position.x > data.PAINT_AREA_TOP_RIGHT.x+50) {
        position = Point(10000,10000);
    }
}

void Enemy3::Fire(Game &my_game)
{
}

void Enemy3::Destroy()
{
    //Item *i=new Item(Point(0,0),position,M_PI/2,&item_hitpoint,new ItemBulletLvupGraphic(),Item::YELLOW_BULLET);
    //game.ItemRegister(i);
}

void Enemy3::Init()
{
    //Enemy3 is pretty small
    Circle tmp(0,0,10);
    enemy3_hitpoint.AddCircle(tmp);
}
