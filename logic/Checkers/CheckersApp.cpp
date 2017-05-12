#include "CheckersApp.h"
#include "../../tools/MsgMgr.h"

namespace
{
    static const int boardSize = 64;
}


void CheckersApp::_initBoard()
{
    CheckerType type = CheckerType::Light;
    for(int i = 0; i < 8; i++)
    {
        Row rowField;
        for(int j = 0; j < 8; j++)
        {
            Field field;
            field.id = i + j;
            field.type = type;

            rowField.push_back( field );
            type = (type == CheckerType::Light) ? CheckerType::Dark : CheckerType::Light;
        }
        type = (type == CheckerType::Light) ? CheckerType::Dark : CheckerType::Light;
        m_board.push_back(rowField);
    }
}

void CheckersApp::Init()
{
    _initBoard();

    Msg msg;
    msg.name = "select_view";
    msg.AddValue("board", m_board);

    MsgMgr::Get().SendViewMsg(msg);
}

void CheckersApp::Deinit()
{
    m_board.clear();
}

void CheckersApp::RecieveMsg(const Msg &msg)
{
    int aa =0;
}

