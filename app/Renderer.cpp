#include "Renderer.h"
#include <iostream>

void Renderer::Init( SDL_Window *window )
{
    m_renderer = RendererPtr( SDL_CreateRenderer(window, -1, 0) );
}

void Renderer::SetColor(const Color& color)
{
    SDL_SetRenderDrawColor( m_renderer.get(), color.r, color.g, color.b, color.a );
}

void Renderer::SetFont(TTF_Font *font)
{
    m_font = font;
}

void Renderer::SetTextColor(const Color &color)
{
    m_textColor = color;
}

void Renderer::DrawText(int xPos, int yPos, const std::string &text)
{
    if (nullptr == m_font)
    {
        std::cout << "DrawText could not display text: [" << text << "], because font is not set!\n";
        return;
    }

    auto surface = TTF_RenderText_Solid(m_font, text.c_str(), {m_textColor.r, m_textColor.g, m_textColor.b, m_textColor.a});
    auto texture = SDL_CreateTextureFromSurface(m_renderer.get(), surface);

    SDL_Rect destRect = {xPos, yPos, surface->w, surface->h};

    SDL_RenderCopy(m_renderer.get(), texture, NULL, &destRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Renderer::DrawRect(const Rect& rect, bool filled)
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

void Renderer::DrawLine(Point begin, Point end)
{
    SDL_RenderDrawLine( m_renderer.get(), begin.x, begin.y, end.x, end.y );
}

void Renderer::DrawCircle(Point center, int radius)
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
    SetColor( Color(0, 0, 0, 0 ) );
    SDL_RenderPresent(m_renderer.get());
}

