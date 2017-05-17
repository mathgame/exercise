#include "Point.h"

Point::Point(int _x, int _y)
{
    SetPoint(_x, _y);
}

void Point::SetPoint(int _x, int _y)
{
    x = _x;
    y = _y;
}
