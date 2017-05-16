#include "TicTacApp.h"
#include "tools/MsgMgr.h"
#include <random>

namespace
{
    const int boardSize = 9;
}

void TicTacApp::Init()
{
    m_board = Board(3, Row(3, Square(MarkType::None)));

    Msg msg;
    msg.name = "select_view";
    msg.AddValue("board", m_board);
    MsgMgr::Get().SendViewMsg(msg);
}

void TicTacApp::Update()
{

}

void TicTacApp::Deinit()
{

}

void TicTacApp::RecieveMsg(const Msg &msg)
{
    if( msg.name == "chosen_square" )
    {
        int squareID = -1;
        msg.GetValue("square_id", squareID);
    }
}
