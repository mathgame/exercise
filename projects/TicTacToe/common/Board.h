#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class MarkType { X, O, None };

class Square
{
public:
    int id;
    MarkType m_markType;
    Square() = default;
    Square(MarkType _type) : m_markType(_type){}
};

using Row = std::vector<Square>;
using Board = std::vector<Row>;

#endif //GAME_INFO_H
