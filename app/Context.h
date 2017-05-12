#ifndef CONTEXT_H
#define CONTEXT_H

#include "Window.h"
#include "Renderer.h"

//#include <memory>
//using WindowPtr = std::shared_ptr<SDL_Window>;
//using RendererPtr = std::shared_ptr<SDL_Renderer>;

class Context
{
public:
    Context() = default;

    Window window;
    Renderer renderer;
};

#endif //CONTEXT_H
