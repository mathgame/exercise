#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <memory>
#include "../tools/Utils.h"
#include "../tools/Tools.h"

using RendererPtr = std::unique_ptr<SDL_Renderer, Utils::SDL_Deiniter>;

class Renderer
{
private:
    RendererPtr m_renderer;
public:
    Renderer() = default;
    void Init( SDL_Window *window );

    void SetColor( const Tools::Color& color );
    void DrawRect( const Tools::Rect& rect, bool filled = false );
    void DrawLine( Tools::Point begin, Tools::Point end );
    void DrawCircle( Tools::Point center, int radius );

    void BeginFrame();
    void EndFrame();

};

#endif //RENDERER_H
