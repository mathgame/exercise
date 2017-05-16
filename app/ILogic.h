#ifndef ILOGIC_H
#define ILOGIC_H

#include <memory>
class Msg;
class ILogic
{
public:
    ILogic() = default;
    virtual ~ILogic() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Deinit() = 0;
    virtual void RecieveMsg(const Msg& msg) = 0;
};
using ILogicPtr = std::shared_ptr<ILogic>;
#endif //ILOGIC_H
