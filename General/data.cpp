#include "data.h"

const Point Data::DEFAULT_GAME_AREA_BOTTOM_LEFT=Point(-250,-250);
const Point Data::DEFAULT_GAME_AREA_TOP_RIGHT=Point(750,750);
const int Data::DEFAULT_FRAME_PER_SECOND=30;
const int Data::DEFAULT_MAX_LIFE=3;
const int Data::DEFAULT_MAX_HEALTH=100;
const int Data::DEFAULT_CRUSH_DAMAGE=100;
const Point Data::DEFAULT_PAINT_AREA_TOP_RIGHT=Point(500,500);
const double Data::BACKGROUND_SPEED=20;
const double Data::TITLE_SPEED=20;
const double Data::DOOR_SPEED=250;

Data::Data():
    GAME_AREA_BOTTOM_LEFT(DEFAULT_GAME_AREA_BOTTOM_LEFT),
    GAME_AREA_TOP_RIGHT(DEFAULT_GAME_AREA_TOP_RIGHT),
    FRAME_PER_SECOND(DEFAULT_FRAME_PER_SECOND),
    MAX_LIFE(DEFAULT_MAX_LIFE),
    MAX_HEALTH(DEFAULT_MAX_HEALTH),
    PAINT_AREA_TOP_RIGHT(DEFAULT_PAINT_AREA_TOP_RIGHT)
{
}
