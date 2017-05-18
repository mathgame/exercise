#ifndef BOARD_H
#define BOARD_H

#include <vector>

enum class MarkType { X, O, None };

class Square
{
public:
    int id;
    MarkType markType;

    Square() = default;
    Square(int _id, MarkType _type)
        : id(_id)
        , markType(_type){}
};

using Row = std::vector<Square>;
using Board = std::vector<Row>;



#endif //GAME_INFO_H
