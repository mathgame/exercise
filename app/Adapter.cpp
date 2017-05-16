#include "Adapter.h"
#include <iostream>
#include <memory>
#include "tools/MsgMgr.h"
#include "projects/Checkers/CheckerController.h"
#include "projects/TicTacToe/TicTacToeController.h"
#include "projects/SelectScreen/SelectScreenController.h"

void Adapter::Init(Context& context)
{
    //TODO make factory
    IControllerPtr selectScreenController = std::make_shared<SelectScreenController>();
    selectScreenController->Init(context);
    m_controllerMap[ControllerID::SelectScreen] = selectScreenController;

    IControllerPtr ticTacToeController = std::make_shared<TicTacToeController>();
    ticTacToeController->Init(context);
    m_controllerMap[ControllerID::TicTacToe] = ticTacToeController;

    IControllerPtr checkerController = std::make_shared<CheckerController>();
    checkerController->Init(context);
    m_controllerMap[ControllerID::Checkers] = checkerController;

    m_current = m_controllerMap.at(ControllerID::TicTacToe);
    RequestChangeController(ControllerID::TicTacToe);
}

void Adapter::RequestChangeController(int id)
{
    const auto& iter = m_controllerMap.find(id);
    if( iter == m_controllerMap.end())
    {
        std::cout << "This id: " << (int)id << ", doesn't exist in m_controllerMap at Adappter!\n";
        return;
    }
    m_requestedNext = (*iter).second;
}

const IControllerPtr Adapter::GetCurrentController()
{
    if( nullptr == m_requestedNext )
    {
        return m_current;
    }

    m_current->GetMainFramework()->logic->Deinit();
    m_current->GetMainFramework()->view->Hide();

    m_current = m_requestedNext;
    m_requestedNext = nullptr;

    m_current->GetMainFramework()->logic->Init();
    m_current->GetMainFramework()->view->Show();

    return m_current;
}

void Adapter::RecieveMsg(const Msg &msg)
{
    if( msg.name == "change_controller" )
    {
        int controllerID = 0;
        msg.GetValue("controller_id", controllerID );
        RequestChangeController(controllerID);
    }
}
