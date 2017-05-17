#include "Rect.h"

Rect::Rect(int _x, int _y, int _w, int _h)
{
    SetRect(_x,_y,_w,_h);
}

void Rect::SetRect(int _x, int _y, int _w, int _h)
{
   x = _x;
   y = _y;
   w = _w;
   h = _h;
}
