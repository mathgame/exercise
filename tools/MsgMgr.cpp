#include "MsgMgr.h"


MsgMgr &MsgMgr::Get()
{
    static MsgMgr msgMgr;
    return msgMgr;
}

void MsgMgr::SendViewMsg(const Msg &msg)
{
    Msg viewMsg = msg;
    viewMsg.type = "view";
    m_messages.push(viewMsg);
}

void MsgMgr::SendLogicMsg(const Msg &msg)
{
    Msg logicMsg = msg;
    logicMsg.type = "logic";
    m_messages.push(logicMsg);
}

bool MsgMgr::CheckForMsg(Msg &msg)
{
    if( m_messages.empty() )
    {
        return false;
    }

    msg = m_messages.front();
    m_messages.pop();
    return true;
}
