#include "ResourceMgr.h"
#include "../tools/FileSystem.h"
#include <iostream>

void ResourceMgr::Init()
{
    if( TTF_Init() == (-1))
    {
        std::cout << "TTF_Init failed to init!\n";
        return;
    }
}

TTF_Font *ResourceMgr::GetFont(const std::string &fontName, int size)
{
    std::string fontPath = fs::resolve_protocol("app:/resources/fonts/" + fontName).string();
    const auto& mainIter = m_fonts.find(fontName);
    if(mainIter != m_fonts.end())
    {
        const auto& subIter = mainIter->second.find(size);
        if( subIter != mainIter->second.end() )
        {
            return subIter->second;
        }
        else
        {
            TTF_Font* font = TTF_OpenFont(fontPath.c_str(), size);
            m_fonts[fontName] = {{size, font}};
            return font;
        }
    }
    else
    {
        TTF_Font* font = TTF_OpenFont(fontPath.c_str(), size);
        m_fonts[fontName] = {{size, font}};
        return font;
    }
    std::cout << "Could not initalize font, path: " << fontPath << ", ttf name: " << fontName << std::endl;
    return nullptr;
}
