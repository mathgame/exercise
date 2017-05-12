#ifndef MSG_MGR_H
#define MSG_MGR_H
#include "Msg.h"
#include <queue>

class MsgMgr
{
private:
    MsgMgr() = default;
    MsgMgr(const MsgMgr&) = default;
    MsgMgr(MsgMgr&&) = default;

    std::queue<Msg> m_messages;
public:
    static MsgMgr& Get();

    void SendViewMsg( const Msg& msg );
    void SendLogicMsg( const Msg& msg);

    bool CheckForMsg( Msg& msg );
};

#endif //MSG_MGR_H
