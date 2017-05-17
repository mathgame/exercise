#include "Tools.h"

Color::Color(int _r, int _g, int _b, int _a)
{
    SetColor(_r,_g,_b,_a);
}

void Color::SetColor(int _r, int _g, int _b, int _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}
