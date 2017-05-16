#include "Font.h"
#include <iostream>


void Font::Init()
{
    if( TTF_Init() == (-1))
    {
        std::cout << "TTF_Init failed to init!\n";
    }
}

void Font::Deinit()
{
    TTF_CloseFont( m_font );
}

void Font::AddFont(const std::string &fontPath, int size)
{
    m_font = TTF_OpenFont( fontPath.c_str(), size );

    if( nullptr == m_font )
    {
        std::cout << TTF_GetError() << std::endl;
    }
}

const TTF_Font &Font::GetFont()
{
    return *m_font;
}
