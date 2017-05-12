#include "Renderer.h"

void Renderer::Init( SDL_Window *window )
{
    m_renderer = RendererPtr( SDL_CreateRenderer(window, -1, 0) );
}

void Renderer::SetColor(const Tools::Color& color)
{
    SDL_SetRenderDrawColor( m_renderer.get(), color.r, color.g, color.b, color.a );
}

void Renderer::DrawRect(const Tools::Rect& rect, bool filled)
{
    SDL_Rect sdl_rect = { rect.x, rect.y, rect.w, rect.h };
    if( filled )
    {
        SDL_RenderFillRect(m_renderer.get(), &sdl_rect );
    }
    else
    {
        SDL_RenderDrawRect( m_renderer.get(), &sdl_rect );
    }

}

void Renderer::DrawLine(Tools::Point begin, Tools::Point end)
{
    SDL_RenderDrawLine( m_renderer.get(), begin.x, begin.y, end.x, end.y );
}

void Renderer::DrawCircle(Tools::Point center, int radius)
{
    for( int w = 0; radius * 2; w++ )
    {
        for(int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if( (dx*dx + dy*dy) <= (radius*radius) )
            {
                SDL_RenderDrawPoint( m_renderer.get(),
                                     center.x + dx,
                                     center.y + dy );
            }
        }
    }
}

void Renderer::BeginFrame()
{
    SDL_RenderClear(m_renderer.get());
}

void Renderer::EndFrame()
{
    SetColor( Tools::Color(0, 0, 0, 0 ) );
    SDL_RenderPresent(m_renderer.get());
}

