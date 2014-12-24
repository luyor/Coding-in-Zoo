#ifndef MYTREAD_H
#define MYTREAD_H

#include <qthread.h>
#include "game.h"

class MyThread: public QThread
{
public:
    Game *my_game;
    MyThread(enum Game::GameMode game_mode,int coins0,Control* control0,Control* control1);
    ~MyThread();
    void run();
};

#endif // MYTREAD_H
