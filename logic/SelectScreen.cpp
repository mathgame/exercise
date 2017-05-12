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

    MsgMgr::Get().SendMsg(msg);
}

void SelectScreen::Deinit()
{

}
