#ifndef TABLE_BOARD_H
#define TABLE_BOARD_H

#include "../common/Board.h"

class TableBoard
{
private:
    Board m_board;

    Square& GetSquareById( int squareId );
    bool IsLegalMove( int squareId );
public:

    void Init();
    bool MarkSquare( int squareId, MarkType markType );
    MarkType GetWinner() const;

    const Board& GetRawBoard() const;
};

#endif //TABLE_BOARD_H
