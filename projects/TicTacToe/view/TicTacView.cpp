#include "TicTacView.h"
#include "app/Context.h"
#include "tools/InputMgr.h"
#include "tools/MsgMgr.h"
#include "utils/Collision.h"

namespace
{
    // TODO - move in xml
    //const Point ComputerDiffGrouPos = { 250, 25 };
    //const int ComputerDiffSize = 40;

    const Point PlayerChoiceGroupPos = { 75, 25 };
    const int ChoiceSize = 40;

    const Point TicTacGroupPos = { 75, 250 };
    const int SquareSize = 100;
    const int BorderSize = 5;
}

void TicTacView::DrawChoiceFrame()
{
    int xPos = PlayerChoiceGroupPos.x;
    int yPos = PlayerChoiceGroupPos.y;

    GetContext().renderer.SetColor( Color(255, 0, 0, 0));
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            GetContext().renderer.DrawRect({xPos, yPos, ChoiceSize, ChoiceSize}, true);
            xPos += ChoiceSize + BorderSize;
        }
        xPos = PlayerChoiceGroupPos.x;
        yPos += ChoiceSize + BorderSize;
    }
}

void TicTacView::DrawBoard()
{
    int xPos = TicTacGroupPos.x;
    int yPos = TicTacGroupPos.y;
    for(size_t i = 0; i < m_board.size(); i++)
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {
            GetContext().renderer.SetColor( Color(255, 255, 0, 0));
            GetContext().renderer.DrawRect({xPos, yPos, SquareSize, SquareSize}, true);
            xPos += (SquareSize + BorderSize);
        }
        xPos = TicTacGroupPos.x;
        yPos += (SquareSize + BorderSize);
    }
}

void TicTacView::OnMousePressed(Point mousePos)
{

}

void TicTacView::OnMouseReleased(Point mousePos)
{
    int xPos = TicTacGroupPos.x;
    int yPos = TicTacGroupPos.y;

    for(size_t i = 0; i < m_board.size(); i++)
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {
            if( Collision::InRect(mousePos, {xPos, yPos, SquareSize, SquareSize}) )
            {
                Msg msg;
                msg.name = "chosen_square";
                msg.AddValue("square_id", i+j);
                MsgMgr::Get().SendLogicMsg(msg);
                break;
            }
        }
        xPos = TicTacGroupPos.x;
        yPos += (SquareSize + BorderSize);
    }
}

void TicTacView::Update()
{

}

void TicTacView::Draw()
{
    GetContext().renderer.BeginFrame();

    DrawChoiceFrame();
    DrawBoard();

}

void TicTacView::Show()
{
    UpdateScene();
}

void TicTacView::Hide()
{
    UpdateScene();
}

void TicTacView::RecieveMsg(const Msg &msg)
{
    if( msg.name == "select_view")
    {
        msg.GetValue("board", m_board);
    }
}
