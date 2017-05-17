#include "Collision.h"
#include "geometry/Rect.h"
#include "geometry/Point.h"

bool Collision::InRect(const Point &point, const Rect &rect)
{
    bool inHorizontal = (point.x > rect.x) && point.x < (rect.x + rect.w);
    bool inVertical = (point.y > rect.y) && point.y < (rect.y + rect.h);
    return inHorizontal & inVertical;
}
