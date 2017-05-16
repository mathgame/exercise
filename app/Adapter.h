#ifndef ADAPTER_H
#define ADAPTER_H

#include "ILogic.h"
#include "IView.h"
#include <map>
#include "IController.h"
class Context;
class Msg;

//TODO - better way to add game ids.
namespace ControllerID
{
    const int SelectScreen = -1;
    const int TicTacToe = 0;
    const int Checkers = 1;
}

class Adapter
{
private:
    std::map <int, IControllerPtr> m_controllerMap;
    IControllerPtr m_current;
    IControllerPtr m_requestedNext;
public:
    Adapter() = default;

    void Init(Context& context);
    void RequestChangeController(int id);
    const IControllerPtr GetCurrentController();

    void RecieveMsg( const Msg& msg );
};

#endif //ADAPTER_H
