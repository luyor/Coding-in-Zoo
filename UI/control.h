#ifndef CONTROL_H
#define CONTROL_H

class Control
{
public:
    Control();
    bool LeftPressed();
    bool RightPressed();
    bool UpPressed();
    bool DownPressed();
    bool BulletPressed();
    bool BombClicked();
    bool PauseClicked();
};

#endif // CONTROL_H
