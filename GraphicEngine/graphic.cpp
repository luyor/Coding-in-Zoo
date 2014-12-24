#include "graphic.h"

Graphic::Graphic():sig(Graphic::NO_SIGNAL), elapsed_time(0), finish(false)
{
}

void Graphic::GetSignal(Signal s)
{
    sig = s;
}

bool Graphic::DestroyFinished()
{
    return finish;
}
