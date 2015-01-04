#ifndef MYTREAD_H
#define MYTREAD_H

#include <qthread.h>

class MyThread: public QThread
{
public:
    MyThread();
    ~MyThread();
    void run();
    
    void Single();
    void COOP();
    
    bool EXIT;
};

#endif // MYTREAD_H
