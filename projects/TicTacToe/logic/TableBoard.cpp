#include "TableBoard.h"
#include <algorithm>
#include <iostream>

Square &TableBoard::GetSquareById(int squareId)
{
    for( auto& row : m_board )
    {
        auto res = std::find_if(row.begin(), row.end(), [squareId](Square& sqr)
        {
            return sqr.id == squareId;
        });
        if( res != row.end() )
        {
            return (*res);
        }
    }
    //ASSERT
    std::cout << "Error: GetSquareById trying to get with id that doesn't exist: " << squareId << std::endl;
    static Square emptySquare;
    return emptySquare;
}

bool TableBoard::IsLegalMove(int squareId)
{
    const auto& square = GetSquareById(squareId);
    return square.markType == MarkType::None;
}


void TableBoard::Init()
{
    for(int i = 0; i < 3; i++)
    {
        Row row;
        for(int j = 0; j < 3; j++)
        {
            row.push_back(Square((3 * i)+j, MarkType::None));
        }
        m_board.push_back(row);
    }
}

bool TableBoard::MarkSquare(int squareId, MarkType markType)
{
    if( false == IsLegalMove(squareId) )
    {
        return false;
    }
    auto& square = GetSquareById( squareId );
    square.markType = markType;
    return true;
}

MarkType TableBoard::GetWinner() const
{
    return MarkType::None;
}

const Board &TableBoard::GetRawBoard() const
{
    return m_board;
}
