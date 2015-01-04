#include "control.h"

Control::Control()
{
    LeftPressed = 0;
    RightPressed = 0;
    UpPressed = 0;
    DownPressed = 0;
    FirePressed = 0;
    BombClicked = 0;
    PauseClicked = 0;
}

bool Control::BombValue()
{
    bool value = BombClicked;
    BombClicked = 0;
    return value;
}

bool Control::PauseValue()
{
    bool value= PauseClicked;
    PauseClicked = 0;
    return value;
}

void Control::Clean()
{
    LeftPressed=false;
    RightPressed=false;
    UpPressed=false;
    DownPressed=false;
    FirePressed=false;
    BombClicked=false;
    PauseClicked=false;
}
