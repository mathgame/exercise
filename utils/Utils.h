#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>
namespace Utils
{

struct SDL_Deiniter
{
    void operator()(SDL_Window* window) const;
    void operator()(SDL_Renderer *renderer) const;
    void operator()(SDL_Texture *texture) const;
};

} //Utils

#endif //UTILS_H
