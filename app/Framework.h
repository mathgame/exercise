#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include "ILogic.h"
#include "IView.h"
#include <map>
#include <list>
#include <memory>

class Framework
{
public:
    int id;
    ILogicPtr logic;
    IViewPtr view;
    Framework() = default;
    Framework(int _id, ILogic* _logic, IView* _view) :
        id(_id), logic(_logic), view(_view) {}

    bool operator> (const Framework& other)
    {
        return id > other.id;
    }
};

using FrameworkPtr = std::shared_ptr<Framework>;
using FrameworkMap = std::map<int, FrameworkPtr>;
using FrameworkList = std::list<FrameworkPtr>;

#endif //FRAMEWORK_H
