#include "mythread.h"
#include "res.h"

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
