#ifndef TOOLS_H
#define TOOLS_H

#include <SDL2/SDL.h>

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

#endif //TOOLS_H
