#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <memory>
#include "utils/Utils.h"
#include "tools/Tools.h"

using RendererPtr = std::unique_ptr<SDL_Renderer, Utils::SDL_Deiniter>;

class Renderer
{
private:
    TTF_Font* m_font;
    Color m_textColor;
    RendererPtr m_renderer;
public:
    Renderer() = default;
    void Init( SDL_Window *window );

    void SetColor( const Color& color );
    void SetFont( TTF_Font* font );
    void SetTextColor( const Color& color );

    void DrawText( int xPos, int yPos, const std::string& text);
    void DrawRect( const Rect& rect, bool filled = false );
    void DrawLine( Point begin, Point end );
    void DrawCircle( Point center, int radius );

    void BeginFrame();
    void EndFrame();

};

#endif //RENDERER_H
