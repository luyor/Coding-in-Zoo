#ifndef DATA_H
#define DATA_H

#include "point.h"

class Data
{
public:
    Data();
    Point GAME_AREA_BOTTOM_LEFT,GAME_AREA_TOP_RIGHT;//valid area of game
    Point PAINT_AREA_TOP_RIGHT;//valid area of paint
    int FRAME_PER_SECOND;
    int MAX_LIFE;
    int MAX_HEALTH;
    int CRUSH_DAMAGE;
    static const double BACKGROUND_SPEED;
    static const double TITLE_SPEED;
    static const double DOOR_SPEED;
private:
    static const Point DEFAULT_GAME_AREA_BOTTOM_LEFT;
    static const Point DEFAULT_GAME_AREA_TOP_RIGHT;
    static const Point DEFAULT_PAINT_AREA_TOP_RIGHT;
    static const int DEFAULT_FRAME_PER_SECOND;
    static const int DEFAULT_MAX_LIFE;
    static const int DEFAULT_MAX_HEALTH;
    static const int DEFAULT_CRUSH_DAMAGE;
};

#endif // DATA_H
