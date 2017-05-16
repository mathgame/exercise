#include "SelectScreenController.h"
#include "app/Framework.h"

#include "logic/SelectScreen.h"
#include "view/SelectScreenView.h"

void SelectScreenController::Init(Context &context)
{
    //TODO make controller factory :)

    m_mapping[0] = std::make_shared<Framework>();
    m_mapping.at(0)->id = 0;
    m_mapping.at(0)->logic = std::make_shared<SelectScreen>();
    m_mapping.at(0)->view = std::make_shared<SelectScreenView>();
    m_mapping.at(0)->view->SetContext(context);
    m_main = m_mapping.at(0);
    m_current = m_mapping.at(0);
 }

