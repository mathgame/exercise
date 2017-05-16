

#ifndef SELECT_SCREEN_CONTROLLER_H
#define SELECT_SCREEN_CONTROLLER_H
#include <app/IController.h>

class SelectScreenController : public IController
{
public:
    SelectScreenController() = default;
    ~SelectScreenController() = default;

    void Init(Context& context) final override;
};

#endif //SELECT_SCREEN_CONTROLLER_H

