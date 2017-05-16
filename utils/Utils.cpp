#include "Utils.h"

namespace Utils
{
void SDL_Deiniter::operator()(SDL_Window *window) const
{
    SDL_DestroyWindow(window);
}

void SDL_Deiniter::operator()(SDL_Renderer *renderer) const
{
    SDL_DestroyRenderer(renderer);
}

void SDL_Deiniter::operator()(SDL_Texture *texture) const
{
    SDL_DestroyTexture(texture);
}
} // Utils
