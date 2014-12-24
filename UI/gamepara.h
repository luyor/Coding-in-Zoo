#ifndef GAMEPARA_H
#define GAMEPARA_H

class GamePara
{
public:
    GamePara();
    int screenMode;
    int backGroundSound;
    int bombSound;
    int KeybordOrJoypad;
    char fire;
    char bomb;
    char start;
    int LasterFire;
    char up;
    char down;
    char left;
    char right;
    int difficulty;
    int rebornTime;
    int initialBomb;
};

#endif // GAMEPARA_H
