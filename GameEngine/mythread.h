#ifndef MYTREAD_H
#define MYTREAD_H

#include <qthread.h>
#include "game.h"

class MyThread: public QThread
{
public:
    MyThread();
    ~MyThread();
    void run();
};

#endif // MYTREAD_H
