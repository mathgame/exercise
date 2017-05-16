#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <map>
#include <vector>
#include "Framework.h"

class Context;

class IController
{
protected:
    FrameworkMap m_mapping; // all frameworks for this project
    FrameworkPtr m_current; // Current visualize framework
    FrameworkPtr m_main; // framework who start at init
    //FrameworkList m_frameworkList; // background frameworks who you want to be updated anyway
public:
    IController() = default;
    virtual ~IController() = default;

    virtual void Init(Context& context) = 0;

    void ChangeFramework(int id);
    const FrameworkPtr GetMainFramework() const;
    const FrameworkPtr GetCurrentFramework() const;
    //TODO - Background update list
    //const FrameworkList GetFrameworkList() const;
};
using IControllerPtr = std::shared_ptr<IController>;

#endif //CONTROLLER_H
