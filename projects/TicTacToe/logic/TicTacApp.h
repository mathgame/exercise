#ifndef TIC_TAC_APP_H
#define TIC_TAC_APP_H

#include "app/ILogic.h"
#include "../common/Board.h"
#include "PlayerController.h"

class TicTacApp : public ILogic
{
private:
    Board m_board;
    PlayersController m_playersController;
public:

    void Init() final override;
    void Update() final override;
    void Deinit() final override;
    void RecieveMsg(const Msg& msg ) final override;
};

#endif //TIC_TAC_APP_H
