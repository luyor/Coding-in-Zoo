#include "mythread.h"
#include "res.h"

MyThread::MyThread():EXIT(false)
{
}

void MyThread::run()
{
    while (!EXIT)
        game.GameLoop();
}

void MyThread::Single()
{
    game.EndGame();
    while (game.LOCK){}
    game.Start(Game::SINGLE,4);
}

void MyThread::COOP()
{
    game.EndGame();
    while (game.LOCK){}
    game.Start(Game::COOP,4);
}

MyThread::~MyThread()
{
}


