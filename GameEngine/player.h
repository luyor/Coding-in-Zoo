#ifndef PLAYER_H
#define PLAYER_H

#include "../UI/control.h"

class Player
{
public:
    Player(int max_life0,Control* control0);
    bool IsDead(){return current_life==0;}
    void LoseLife(){--current_life;}
    void IncreaseLife(){++current_life;}
    void AddScore(int score0){score+=score0;}
    void Revive(){current_life=max_life;}

    Control* my_control;
private:
    int max_life;
    int current_life;
    int score;
};

#endif // PLAYER_H
