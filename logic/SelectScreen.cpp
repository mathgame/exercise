#include "SelectScreen.h"
#include "../tools/MsgMgr.h"

void SelectScreen::Init()
{
    for(int i = 0; i < 20; i++)
    {
        GameInfo info;
        info.gameID = i;
        m_gameInfos.push_back(info);
    }

    Msg msg;
    msg.name = "select_view";
    msg.AddValue("games", m_gameInfos);

    MsgMgr::Get().SendViewMsg(msg);
}

void SelectScreen::Deinit()
{

}

void SelectScreen::RecieveMsg(const Msg &msg)
{

}
