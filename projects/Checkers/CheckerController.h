

#ifndef CHECKER_CONTROLLER_H
#define CHECKER_CONTROLLER_H
#include <app/IController.h>

class CheckerController : public IController
{
public:
    CheckerController() = default;
    ~CheckerController() = default;

    void Init(Context& context) final override;
};

#endif //CHECKER_CONTROLLER_H

