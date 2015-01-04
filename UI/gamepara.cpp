#include "gamepara.h"

GamePara::GamePara()
{
    screenMode = 1;
    backGroundSound = 50;
    bombSound = 50;
    KeybordOrJoypad = 0;  //1 is Keyboard and 0 is Joypad
    fire = 'C';
    bomb = 'V';
    start = 'B';
    LasterFire = 1;   //1 means fire is lasted
    up =  'W';
    down = 'S';
    left = 'A';
    right = 'D';
    difficulty = 1;
    rebornTime = 3;
    initialBomb = 1;  //0 means red one while 1 means yellow one
}

