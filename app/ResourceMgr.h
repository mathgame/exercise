#ifndef RESOURCE_MGR_H
#define RESOURCE_MGR_H

#include <SDL2/SDL_ttf.h>
#include <map>

using FontSizeMap = std::map<int, TTF_Font*>;

class ResourceMgr
{
private:
    std::map<std::string, FontSizeMap> m_fonts;
public:
    void Init();
    TTF_Font* GetFont( const std::string& fontName, int size );
};


#endif //RESOURCE_MGR_H
