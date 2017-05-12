#include "MsgMgr.h"


MsgMgr &MsgMgr::Get()
{
    static MsgMgr msgMgr;
    return msgMgr;
}

void MsgMgr::SendMsg(const Msg &msg)
{
    m_messages.push(msg);
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
