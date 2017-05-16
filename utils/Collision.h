#ifndef COLLISION_H
#define COLLISION_H

#include "tools/Tools.h"

class Collision
{
private:
public:
    static bool InRect(const Point& point, const Rect& rect);
    //static bool InCircle(const Point& point, const Circle& circle);
    //static bool ABBA(const Rect& left, const Rect& right);
};

#endif //COLLISION_H
