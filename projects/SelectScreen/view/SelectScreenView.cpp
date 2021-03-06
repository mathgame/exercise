#include "SelectScreenView.h"
#include "app/Context.h"
#include "tools/InputMgr.h"
#include "tools/MsgMgr.h"
#include "utils/Collision.h"

#include <tools/Signals.h>
#include <functional>
#include <iostream>
#include <vector>

namespace
{
    const Point FrameGroupPos = { 115, 115 };
}

Rect SelectScreenView::CreateRectByOrderCount(int xPos, int yPos, int cellCount)
{
    //TODO - Should be changed easily from xml.
    static const int frameWidth = 100;
    static const int frameHeight = 50;
    static const int maxFrameRow = 4;
    static const int maxFrameCol = 4;
    static const int borderWidth = 10;

    const int maxFrameCount = maxFrameRow + maxFrameCol;

    if( cellCount >= maxFrameCount )
    {
        return {};
    }

    //TODO - make it work with different row and col values.
    int row = cellCount / maxFrameRow;
    int col = cellCount % maxFrameCol;

    yPos += (row * frameHeight) + ((row-1) * borderWidth);
    xPos += (col * frameWidth) + ((col-1) * borderWidth);

    return {xPos, yPos, frameWidth, frameHeight};
}

void SelectScreenView::OnMousePressed(const Point& mousePos)
{
    for( size_t i = 0; i < m_gameInfos.size(); i++)
    {
        Rect rect = CreateRectByOrderCount(FrameGroupPos.x, FrameGroupPos.y, i);
        if( Collision::InRect(mousePos, rect) )
        {
            Msg msg;
            msg.name = "change_controller";
            msg.AddValue("controller_id", i);
            MsgMgr::Get().SendSystemMsg(msg);
            break;
        }
    }
}

void SelectScreenView::Update()
{

}

void SelectScreenView::Draw()
{
    GetContext().renderer.BeginFrame();

    for( size_t i = 0; i < m_gameInfos.size(); i++)
    {
        GetContext().renderer.SetColor( Color(255,0,0,255) );
        Rect rect = CreateRectByOrderCount(FrameGroupPos.x, FrameGroupPos.y, i);
        GetContext().renderer.DrawRect( rect, true );
    }
}

void SelectScreenView::Show()
{
    UpdateScene();

	Signals::Get().signals.connect("OnMousePressed", this, &SelectScreenView::OnMousePressed);
}

void SelectScreenView::Hide()
{
    UpdateScene();

	Signals::Get().signals.disconnect("OnMousePressed", this, &SelectScreenView::OnMousePressed);
}

void SelectScreenView::RecieveMsg(const Msg &msg)
{
    if ( msg.name == "select_view" )
    {
        msg.GetValue("games", m_gameInfos);
    }
    else if( msg.name == "config_view" )
    {
//        int rectCount = 0;
//        std::vector<int> vecNum;
//        std::vector<Tools::Rect> structVec;

//        msg.GetValue("rect_count", rectCount);
//        msg.GetValue("vec_num", vecNum);
//        msg.GetValue("struct_vec", structVec);

//        int debugStop = 0;
    }
}
