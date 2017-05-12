#include "Application.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "../tools/MsgMgr.h"
#include "../view/SelectScreenView.h"
#include "../logic/SelectScreen.h"

bool Application::Init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) )
    {
        std::cout << "Error: SDL_Init failed\n";
        return false;
    }

    m_context.window.Init();
    m_context.renderer.Init( m_context.window.GetWindow() );

    m_adapter.Init(m_context);

    return true;
}

void Application::Run()
{
    static bool alive = true;
    while( alive )
    {
        const auto& framework = m_adapter.GetCurrentFramework();
        alive = m_inputMgr.HandleEvent();

        while( m_inputMgr.HasKeyEvent() )
        {
            const auto& actionKeyMap = m_inputMgr.PopActionKeyEvent();
            switch( actionKeyMap.second )
            {
                case KeyState::Pressed:
                {
                    framework.view->OnKeyPressed(actionKeyMap.first);
                }break;
                case KeyState::Released:
                {
                    framework.view->OnKeyReleased(actionKeyMap.first);
                }break;
                default: break;
            }
        }

        while( m_inputMgr.HasMouseEvent() )
        {
            const auto& mouseEvent = m_inputMgr.PopMouseEvent();
            switch ( mouseEvent.second )
            {
                case MouseState::Pressed:
                {
                    framework.view->OnMousePressed( mouseEvent.first );
                }break;
                case MouseState::Released:
                {
                    framework.view->OnMouseReleased( mouseEvent.first );
                }break;
                default: break;
            }
        }

        Msg msg;
        while( MsgMgr::Get().CheckForMsg(msg) )
        {
            if ( msg.type == "view")
            {
                framework.view->RecieveMsg(msg);
            }
            else if( msg.type == "logic")
            {
                framework.logic->RecieveMsg(msg);
            }
        }

        framework.view->Update();
        if( framework.view->GetUpdateScene() )
        {
            framework.view->Draw();
        }

        m_context.renderer.EndFrame();
    }
}

void Application::Deinit()
{
    m_adapter.Deinit();
    SDL_Quit();
}
