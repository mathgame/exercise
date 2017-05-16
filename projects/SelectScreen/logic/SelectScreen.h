#ifndef SELECT_SCREEN_H
#define SELECT_SCREEN_H

#include "app/ILogic.h"
#include <vector>
#include "projects/SelectScreen/common/GameInfo.h"

class SelectScreen : public ILogic
{
private:
    std::vector<GameInfo> m_gameInfos;
public:

    void Init() final override;
    void Update() final override;
    void Deinit() final override;
    void RecieveMsg(const Msg& msg ) final override;
};

#endif //SELECT_SCREEN_H
