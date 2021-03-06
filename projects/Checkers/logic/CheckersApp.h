#ifndef CHECKERS_APP_H
#define CHECKERS_APP_H

#include "app/ILogic.h"
#include "projects/Checkers/common/Board.h"

class CheckersApp : public ILogic
{
private:
    Board m_board;

    void _initBoard();
public:
    void Init() final override;
    void Update() final override;
    void Deinit() final override;
    void RecieveMsg(const Msg& msg ) final override;
};

#endif //CHECKERS_APP_H
