#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>

#include <memory>
#include "utils/Utils.h"
#include "tools/Tools.h"

using RendererPtr = std::unique_ptr<SDL_Renderer, Utils::SDL_Deiniter>;

class Renderer
{
private:
    RendererPtr m_renderer;
public:
    Renderer() = default;
    void Init( SDL_Window *window );

    void SetColor( const Color& color );

    void DrawRect( const Rect& rect, bool filled = false );
    void DrawLine( Point begin, Point end );
    void DrawCircle( Point center, int radius );

    void BeginFrame();
    void EndFrame();

};

#endif //RENDERER_H
