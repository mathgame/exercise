#include "IController.h"
#include <iostream>

void IController::ChangeFramework(int id)
{
    const auto& iter = m_mapping.find(id);
    if( iter == m_mapping.end())
    {
        std::cout << "This id: " << id << ", doesn't exist in mapping at Adappter!\n";
        return;
    }
    m_current.get()->logic->Deinit();
    m_current.get()->view->Hide();

    m_current = (*iter).second;

    m_current.get()->logic->Init();
    m_current.get()->view->Show();
}

const FrameworkPtr IController::GetMainFramework() const
{
    return m_main;
}

const FrameworkPtr IController::GetCurrentFramework() const
{
    return m_current;
}
