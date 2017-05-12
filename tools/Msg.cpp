#include "Msg.h"


bool Msg::HasValue(const std::string &valueName) const
{
    const auto& iter = m_values.find( valueName );
    if( iter == m_values.end() )
    {
        return false;
    }
    return true;
}
