

#ifndef TIC_TAC_TOE_CONTROLLER_H
#define TIC_TAC_TOE_CONTROLLER_H

#include <app/IController.h>

class TicTacToeController : public IController
{
public:
    TicTacToeController() = default;
    ~TicTacToeController() = default;

    void Init(Context& context) final override;
};

#endif //TIC_TAC_TOE_CONTROLLER_H

