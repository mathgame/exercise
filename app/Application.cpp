#include "Application.h"
#include <iostream>
#include <algorithm>
#include <SDL2/SDL.h>
#include "tools/MsgMgr.h"
#include <chrono>
#include <thread>
#include "tools/FileSystem.h"
#include "tools/Signals.h"

#define DEBUG(x) std::cout << x << std::endl;

bool Application::Init()
{
    if( SDL_Init( SDL_INIT_VIDEO ) )
    {
        std::cout << "Error: SDL_Init failed\n";
        return false;
    }

    m_context.window.Init();
    m_context.renderer.Init( m_context.window.GetWindow() );
    m_context.resourceMgr.Init();

    m_adapter.Init(m_context);

    return true;
}

void Application::Run()
{
    static bool alive = true;
    while( alive )
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(25));

        const auto& controller = m_adapter.GetCurrentController();
        const auto& framework = controller->GetCurrentFramework();

        alive = m_inputMgr.HandleEvent();

        while( m_inputMgr.HasKeyEvent() )
        {
            const auto& actionKeyMap = m_inputMgr.PopActionKeyEvent();
            switch( actionKeyMap.second )
            {
                case KeyState::Pressed:
                {
                    DEBUG("KeyState::Pressed");
                }break;
                case KeyState::Released:
                {
                    if( actionKeyMap.first == SDLK_ESCAPE )
                    {
                        m_adapter.RequestChangeController( ControllerID::SelectScreen );
                    }
                    DEBUG("KeyState::Released");
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
					Signals::Get().signals.emit("OnMousePressed", mouseEvent.first);
                    DEBUG("MouseState::Pressed");
                }break;
                case MouseState::Released:
                {
					Signals::Get().signals.emit("OnMouseReleased", mouseEvent.first);
                    DEBUG("MouseState::Released");
                }break;
                default: break;
            }
        }

        Msg msg;
        while( MsgMgr::Get().CheckForMsg(msg) )
        {
            if ( msg.type == "view")
            {
                framework->view->RecieveMsg(msg);
                DEBUG("msg.type == view");
            }
            else if( msg.type == "logic")
            {
                framework->logic->RecieveMsg(msg);
                DEBUG("msg.type == logic");
            }
            else if( msg.type == "system" )
            {
                m_adapter.RecieveMsg(msg);
            }
        }

        framework->view->Update();
        if( framework->view->GetUpdateScene() )
        {

            framework->view->Draw();
            DEBUG("framework->view->Draw()");
        }

        m_context.renderer.EndFrame();
    }
}

void Application::Deinit()
{
    SDL_Quit();
}
