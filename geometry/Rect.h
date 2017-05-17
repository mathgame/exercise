#ifndef RECT_H
#define RECT_H

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

#endif //RECT_H
