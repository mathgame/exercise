#include "InputMgr.h"
#include <SDL2/SDL.h>
#include "tools/MsgMgr.h"

bool InputMgr::HandleEvent()
{
    SDL_Event event;
    while( SDL_PollEvent(&event) )
    {
        if( event.type == SDL_QUIT )
        {
            return false;
        }

        int keyID = event.key.keysym.sym;
        if( event.type == SDL_KEYDOWN )
        {
            m_keyEventMap.push_back( {keyID, KeyState::Pressed} );
        }
        else if( event.type == SDL_KEYUP )
        {
            m_keyEventMap.push_back( {keyID, KeyState::Released} );
        }
        else if( event.type == SDL_MOUSEBUTTONDOWN )
        {
            m_mouseEvent = {{event.button.x, event.button.y}, MouseState::Pressed};
        }
        else if( event.type == SDL_MOUSEBUTTONUP )
        {
            m_mouseEvent = {{event.button.x, event.button.y}, MouseState::Released};
        }
    }

    return true;
}

bool InputMgr::HasKeyEvent()
{
    if( m_keyEventMap.empty() )
    {
        return false;
    }
    return true;
}

ActionKeyPair InputMgr::PopActionKeyEvent()
{
    const auto& keyEvent = m_keyEventMap.front();
    m_keyEventMap.pop_front();
    return keyEvent;
}

bool InputMgr::HasMouseEvent()
{
    return (m_mouseEvent.second != MouseState::Default);
}

ActionMousePair InputMgr::PopMouseEvent()
{
    ActionMousePair mousePair = m_mouseEvent;
    m_mouseEvent = { {0,0}, MouseState::Default };
    return mousePair;
}

