#include "CheckersView.h"
#include "app/Context.h"
#include "tools/MsgMgr.h"
#include "utils/Collision.h"
namespace
{
    static const Point BoardGroupPos = { 150, 50 };
    static const int FieldSize = 50;
}

void CheckersView::OnMousePressed(Point mousePos)
{
    int xPos = BoardGroupPos.x;
    int yPos = BoardGroupPos.y;

    for( size_t i = 0; i < m_board.size(); i++ )
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {
            Rect rect = {xPos, yPos, FieldSize, FieldSize};
            xPos += FieldSize;

            if( Collision::InRect(mousePos, rect))
            {
                int id = i + j;
                Msg msg;
                msg.name = "add_coin";
                msg.AddValue("coin_id", id);
                MsgMgr::Get().SendLogicMsg(msg);
                break;
            }
        }
        xPos = BoardGroupPos.x;
        yPos += FieldSize;
    }
}
void CheckersView::OnMouseReleased(Point mousePos) {}

void CheckersView::OnKeyPressed(int keyID){}

void CheckersView::OnKeyReleased(int keyID) {}

void CheckersView::Update() {}

void CheckersView::Draw()
{
    GetContext().renderer.BeginFrame();

    int xPos = BoardGroupPos.x;
    int yPos = BoardGroupPos.y;

    for( size_t i = 0; i < m_board.size(); i++ )
    {
        for(size_t j = 0; j < m_board[i].size(); j++)
        {

            if( m_board[i][j].type == CheckerType::Light )
            {
                GetContext().renderer.SetColor( Color(255,0,0,255) );
            }
            else
            {
                GetContext().renderer.SetColor( Color(0,0,255,255) );
            }

            Rect rect = {xPos, yPos, FieldSize, FieldSize};
            xPos += FieldSize;

            GetContext().renderer.DrawRect( rect, true );
        }
        xPos = BoardGroupPos.x;
        yPos += FieldSize;
    }
}

void CheckersView::Show()
{
    UpdateScene();
}
void CheckersView::Hide()
{
    UpdateScene();
}

void CheckersView::RecieveMsg( const Msg& msg )
{
    if ( msg.name == "select_view" )
    {
        msg.GetValue("board", m_board);
    }

    UpdateScene();
}
