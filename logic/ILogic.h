#ifndef ILOGIC_H
#define ILOGIC_H

class ILogic
{
public:
    ILogic() = default;
    virtual ~ILogic() = default;

    virtual void Init() = 0;
    virtual void Deinit() = 0;
};

#endif //ILOGIC_H
