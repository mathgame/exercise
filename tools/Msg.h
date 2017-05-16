#ifndef MSG_H
#define MSG_H
#include <string>
#include <map>
#include "utils/AnyValue.h"

class Msg
{
    std::map<std::string, Any_t> m_values;
public:
    std::string name;
    std::string description;
    std::string type;

    template<typename T>
    void AddValue( const std::string& valueName, const T& value )
    {
        m_values[valueName] = value;
    }

    template<typename T>
    bool GetValue( const std::string& valueName, T& value) const
    {
        const auto& iter = m_values.find(valueName);
        if( iter == m_values.end() )
        {
            return false;
        }
        value = (*iter).second._<T>();
        return true;
    }

    bool HasValue(const std::string& valueName) const;
};

#endif //MSG_H
