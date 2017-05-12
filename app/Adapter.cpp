#include "Adapter.h"
#include <iostream>

#include "../logic/SelectScreen.h"
#include "../logic/Checkers/CheckersApp.h"

#include "../view/SelectScreenView.h"
#include "../view/Checkers/CheckersView.h"


void Adapter::Init(Context& context)
{
    Framework _selectScreen;
    _selectScreen.id = 0;
    _selectScreen.logic = new SelectScreen;
    _selectScreen.view = new SelectScreenView;
    _selectScreen.view->SetContext(context);
    m_mapping[_selectScreen.id] = _selectScreen;

    Framework _checkersApp;
    _checkersApp.id = 1;
    _checkersApp.logic = new CheckersApp;
    _checkersApp.view = new CheckersView;
    _checkersApp.view->SetContext(context);
    m_mapping[_checkersApp.id] = _checkersApp;

    m_current = _checkersApp;
    ChangeFramework(_checkersApp.id);
    //m_current = _selectScreen;
    //ChangeFramework(_selectScreen.id);
}

void Adapter::Deinit()
{
    for( auto& iter : m_mapping )
    {
        delete iter.second.view;
        delete iter.second.logic;
    }
}

void Adapter::ChangeFramework(int id)
{
    const auto& iter = m_mapping.find(id);
    if( iter == m_mapping.end())
    {
        std::cout << "This id: " << id << ", doesn't exist in mapping at Adappter!\n";
        return;
    }
    m_current.logic->Deinit();
    m_current.view->Hide();

    m_current = (*iter).second;

    m_current.logic->Init();
    m_current.view->Show();
}

const Framework &Adapter::GetCurrentFramework() const
{
    return m_current;
}
