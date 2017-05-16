#ifndef CONTEXT_H
#define CONTEXT_H

#include "Window.h"
#include "Renderer.h"
#include "Font.h"

//#include <memory>
//using WindowPtr = std::shared_ptr<SDL_Window>;
//using RendererPtr = std::shared_ptr<SDL_Renderer>;

class Context
{
public:
    Context() = default;

    Window window;
    Renderer renderer;
    Font font;
};

#endif //CONTEXT_H
