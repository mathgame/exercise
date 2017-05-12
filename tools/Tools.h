#ifndef TOOLS_H
#define TOOLS_H

#include <SDL2/SDL.h>

namespace Tools
{

class Color
{
public:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color() = default;
    Color( int _r, int _g, int _b, int _a );
    void SetColor( int _r, int _g, int _b, int _a );
};

class Rect
{
public:
    int x;
    int y;
    int w;
    int h;

    Rect() = default;
    Rect( int _x, int _y, int _w, int _h );
    void SetRect(int _x, int _y, int _w, int _h);
};

class Point
{
public:
    int x;
    int y;

    Point() = default;
    Point( int _x, int _y );
    void SetPoint( int _x, int _y );

};
} // Tools

#endif //TOOLS_H
