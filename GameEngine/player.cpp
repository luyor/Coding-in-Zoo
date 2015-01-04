#include "player.h"

Player::Player(int max_life0,Control* control):max_life(max_life0),
    current_life(max_life0),score(0),my_control(control),START(false)
{
}
