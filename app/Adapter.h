#ifndef ADAPTER_H
#define ADAPTER_H

#include "../logic/ILogic.h"
#include "../view/IView.h"
#include <map>

class Context;
class Framework
{
public:
    int id;
    ILogic* logic;
    IView* view;
    Framework() = default;
    Framework(int _id, ILogic* _logic, IView* _view) :
        id(_id), logic(_logic), view(_view) {}

    bool operator> (const Framework& other)
    {
        return id > other.id;
    }
};

class Adapter
{
private:
    std::map <int, Framework> m_mapping;
    Framework m_current;
public:
    Adapter() = default;

    void Init(Context& context);
    void Deinit();
    void ChangeFramework(int id);
    const Framework& GetCurrentFramework() const;
};

#endif //ADAPTER_H
