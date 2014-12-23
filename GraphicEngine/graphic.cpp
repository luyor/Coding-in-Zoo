#include "graphic.h"

Graphic::Graphic()
{
}

void Graphic::SendSignal(Signal s)
{
    sig = s;
}

bool Graphic::DestroyFinished()
{
    return finish;
}
