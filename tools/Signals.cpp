#include "Signals.h"

Signals& Signals::Get()
{
    static Signals m_signals;
    return m_signals;
}

void Signals::Connect(const std::string &signalName, PointFunction funct)
{
    const auto& iter = m_functions.find(signalName);
    if(iter != m_functions.end())
    {
        iter->second.push_back(funct);
    }
    else
    {
        m_functions[signalName].push_back(funct);
    }
}

void Signals::DispatchSignal(const std::string &signalName, const Point& point)
{
    const auto& iter = m_functions.find(signalName);

    if(iter == m_functions.end())
        return;

    for(const auto& funct : iter->second)
    {
        if(funct != nullptr)
            funct(point);
    }
}
