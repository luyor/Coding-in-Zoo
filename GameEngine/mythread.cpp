#include "mythread.h"

MyThread::MyThread()
{
}

void MyThread::run()
{
    game.Start(Game::SINGLE,4,&control,NULL);
    game.GameLoop();
}

MyThread::~MyThread()
{
}
