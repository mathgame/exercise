#include "TicTacView.h"
#include "app/Context.h"
#include "tools/InputMgr.h"
#include "tools/MsgMgr.h"
#include "utils/Collision.h"
#include "tools/Signals.h"

namespace
{
    // TODO - move in xml
    //const Point ComputerDiffGrouPos = { 250, 25 };
    //const int ComputerDiffSize = 40;

    const Point PlayerChoiceGroupPos = { 75, 25 };
    const int ChoiceSizeW = 100;
    const int ChoiceSizeH = 40;

    const Point TicTacGroupPos = { 75, 250 };
    const int SquareSize = 100;
    const int BorderSize = 5;
}

void TicTacView::DrawChoiceFrame()
{
    int xPos = PlayerChoiceGroupPos.x;
    int yPos = PlayerChoiceGroupPos.y;

    GetContext().renderer.SetColor( Color(100, 100, 0, 0));
    GetContext().renderer.SetTextColor(Color(255,255,255,0));

    auto font = GetContext().resourceMgr.GetFont("Tahoma.ttf", 16);
    GetContext().renderer.SetFont(font);

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            GetContext().renderer.DrawRect({xPos, yPos, ChoiceSizeW, ChoiceSizeH}, true);
            GetContext().renderer.DrawText(xPos, yPos, "Player");
            xPos += ChoiceSizeW + BorderSize;
        }
        xPos = PlayerChoiceGroupPos.x;
        yPos += ChoiceSizeH + BorderSize;
    }
}

void TicTacView::DrawBoard()
{
    int xPos = TicTacGroupPos.x;
    int yPos = TicTacGroupPos.y;

    auto font = GetContext().resourceMgr.GetFont("Tahoma.ttf", 36);
    GetContext().renderer.SetFont(font);
    GetContext().renderer.SetTextColor({0,0,255,0});
    for(size_t i = 0; i < m_board.size(); i++)
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {
            GetContext().renderer.SetColor( Color(255, 255, 0, 0));
            GetContext().renderer.DrawRect({xPos - 30, yPos - 30, SquareSize, SquareSize}, true);
            if( m_board[i][j].markType == MarkType::O)
            {
                GetContext().renderer.DrawText(xPos, yPos, "X");
            }
            else if( m_board[i][j].markType == MarkType::X)
            {
                GetContext().renderer.DrawText(xPos, yPos, "O");
            }
            xPos += (SquareSize + BorderSize);
        }
        xPos = TicTacGroupPos.x;
        yPos += (SquareSize + BorderSize);
    }
}

void TicTacView::OnMousePressed(const Point& pos)
{
    int xPos = TicTacGroupPos.x;
    int yPos = TicTacGroupPos.y;

    for(size_t i = 0; i < m_board.size(); i++)
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {
            Rect rect = {xPos, yPos, SquareSize, SquareSize};
            if( Collision::InRect(pos, rect))
            {
                Msg msg;
                msg.name = "chosen_square";
                msg.AddValue("square_id", static_cast<int>((3 * i)+j));
                MsgMgr::Get().SendLogicMsg(msg);
            }
            xPos += (SquareSize + BorderSize);
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

	Signals::Get().signals.connect("OnMousePressed", this, &TicTacView::OnMousePressed);
}

void TicTacView::Hide()
{
    UpdateScene();

	Signals::Get().signals.disconnect("OnMousePressed", this, &TicTacView::OnMousePressed);
}

void TicTacView::RecieveMsg(const Msg &msg)
{
    if( msg.name == "select_view")
    {
        msg.GetValue("board", m_board);
    }
    if( msg.name == "update_view")
    {
        msg.GetValue("board", m_board);
        UpdateScene();
    }
}
