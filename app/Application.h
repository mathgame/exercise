#ifndef APPLICATION_H
#define APPLICATION_H

#include "Context.h"
#include "InputMgr.h"
#include "Adapter.h"

class Application
{
private:
    Adapter m_adapter;
    Context m_context;
    InputMgr m_inputMgr;
public:
    bool Init();
    void Run();
    void Deinit();
};

#endif //APPLICATION_H
