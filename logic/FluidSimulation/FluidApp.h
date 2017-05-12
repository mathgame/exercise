#ifndef FLUID_APP_H
#define FLUID_APP_H

#include "../ILogic.h"
#include <vector>

class FluidApp : public ILogic
{
private:

public:

    void Init() final override;
    void Deinit() final override;
    void RecieveMsg(const Msg& msg ) final override;
};

#endif //FLUID_APP_H
