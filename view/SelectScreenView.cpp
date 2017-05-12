#include "SelectScreenView.h"
#include "../app/Context.h"
#include "../app/InputMgr.h"
#include "../tools/Msg.h"
#include "../tools/Collision.h"
#include <iostream>
#include <vector>

namespace
{
    static const Point FrameGroupPos = { 115, 115 };
}

Rect SelectScreenView::CalculateFrameRect(int xPos, int yPos, int orderCount)
{
    //TODO - Should be changed easily from xml.
    static const int frameWidth = 100;
    static const int frameHeight = 50;
    static const int maxFrameRow = 4;
    static const int maxFrameCol = 4;
    static const int borderWidth = 10;

    const int maxFrameCount = maxFrameRow * maxFrameCol;

    if( orderCount >= maxFrameCount )
    {
        return {};
    }

    //TODO - make it work with different row and col values.
    int row = orderCount / maxFrameRow;
    int col = orderCount % maxFrameCol;

    yPos += (row * frameHeight) + ((row-1) * borderWidth);
    xPos += (col * frameWidth) + ((col-1) * borderWidth);

    return {xPos, yPos, frameWidth, frameHeight};
}

void SelectScreenView::OnMousePressed(Point mousePos)
{
    for( size_t i = 0; i < m_gameInfos.size(); i++)
    {
        Rect rect = CalculateFrameRect(FrameGroupPos.x, FrameGroupPos.y, i);
        if( Collision::InRect(mousePos, rect) )
        {
            std::cout << "You clicked frame : " << m_gameInfos[i].gameID << "\n";
        }
    }
}

void SelectScreenView::OnMouseReleased(Point mousePos)
{

}

void SelectScreenView::OnKeyPressed(int keyID)
{
    std::cout << "KeyPressed : " << keyID << std::endl;
}

void SelectScreenView::OnKeyReleased(int keyID)
{
    std::cout << "KeyReleased : " << keyID << std::endl;
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
        Rect rect = CalculateFrameRect(FrameGroupPos.x, FrameGroupPos.y, i);
        GetContext().renderer.DrawRect( rect, true );
    }
}

void SelectScreenView::Show()
{
    UpdateScene();
}

void SelectScreenView::Hide()
{
    UpdateScene();
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
