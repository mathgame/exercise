#include "TicTacToeController.h"
#include "app/Framework.h"

#include "logic/TicTacApp.h"
#include "view/TicTacView.h"

void TicTacToeController::Init(Context &context)
{
    //TODO make controller factory :)

    m_mapping[0] = std::make_shared<Framework>();
    m_mapping.at(0)->id = 0;
    m_mapping.at(0)->logic = std::make_shared<TicTacApp>();
    m_mapping.at(0)->view = std::make_shared<TicTacView>();
    m_mapping.at(0)->view->SetContext(context);
    m_main = m_mapping.at(0);
    m_current = m_mapping.at(0);
 }

