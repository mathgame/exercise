#ifndef POINT_H
#define POINT_H

class Point
{
public:
    int x;
    int y;

    Point() = default;
    Point( int _x, int _y );
    void SetPoint( int _x, int _y );

};

#endif //POINT_H
