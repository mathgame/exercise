#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class CheckerType { Light, Dark };

class CheckerCoin
{
    CheckerType type;
};

class Field
{
public:
    int id;
    CheckerType type;
    CheckerCoin coins;

    Field() = default;
};

using Row = std::vector<Field>;
using Board = std::vector<Row>;

#endif //BOARD_H
