#include "TicTacApp.h"
#include "tools/MsgMgr.h"
#include <algorithm>
#include <iostream>

void TicTacApp::HandlePlayerChoice(int squareId)
{
    const auto& player = m_players.GetCurrentPlayer();
    if( false == m_board.MarkSquare(squareId, player.GetMark()) )
    {
        return;
    }

    Msg msg;
    msg.name = "update_view";
    msg.AddValue("board", m_board.GetRawBoard());
    MsgMgr::Get().SendViewMsg(msg);

    auto winner = m_board.GetWinner();
    if( winner != MarkType::None )
    {
        Msg msg;
        msg.AddValue("winner", winner);
        MsgMgr::Get().SendViewMsg(msg);
    }

    m_players.NextPlayer();
}

void TicTacApp::Init()
{
    m_board.Init();
    m_players.Init(2);

    Msg msg;
    msg.name = "select_view";
    msg.AddValue("board", m_board.GetRawBoard());
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
        int squareId = -1;
        if( false == msg.GetValue("square_id", squareId) )
        {
            std::cout << "Warning: TicTacApp::ReciveMsg could not get value square_id << " << squareId << std::endl;
            return;
        }
        HandlePlayerChoice( squareId );
    }
}
