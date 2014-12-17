#ifndef DATA_H
#define DATA_H

#include "point.h"

class Data
{
public:
    Data();
    Point GAME_AREA_BOTTOM_LEFT,GAME_AREA_TOP_RIGHT;//valid area of game
    int FRAME_PER_SECOND;
    int MAX_LIFE;
    int MAX_HEALTH;
private:
    static const Point DEFAULT_GAME_AREA_BOTTOM_LEFT;
    static const Point DEFAULT_GAME_AREA_TOP_RIGHT;
    static const int DEFAULT_FRAME_PER_SECOND;
    static const int DEFAULT_MAX_LIFE;
    static const int DEFAULT_MAX_HEALTH;
};

#endif // DATA_H
