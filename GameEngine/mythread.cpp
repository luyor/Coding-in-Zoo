#include "mythread.h"

MyThread::MyThread(enum Game::GameMode game_mode,int coins0,Control* control0,Control* control1)
{
    my_game=new Game(game_mode,coins0,control0,control1);
}

void MyThread::run()
{
    cout<<"run ok"<<endl;
    my_game->GameLoop();
}

MyThread::~MyThread()
{
    delete my_game;
}
