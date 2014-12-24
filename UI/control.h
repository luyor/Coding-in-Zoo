#ifndef CONTROL_H
#define CONTROL_H

class Control
{
public:
    Control();
    bool LeftPressed;
    bool RightPressed;
    bool UpPressed;
    bool DownPressed;
    bool FirePressed;
    bool BombClicked;
    bool PauseClicked;

    bool BombValue();
    bool PauseValue();



};

#endif // CONTROL_H
