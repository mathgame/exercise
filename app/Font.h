#ifndef FONT_H
#define FONT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <map>

class Font
{
    //TODO map for fonts
    TTF_Font* m_font;
public:
    Font() = default;

    void Init();
    void Deinit();
    void AddFont( const std::string& fontPath, int size );
    const TTF_Font& GetFont();
};

#endif //FONT_H
