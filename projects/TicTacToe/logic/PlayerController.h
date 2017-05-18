#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>
#include "../common/Board.h"

class Msg;
class Player
{
private:
    MarkType m_markType;
public:
    Player(MarkType markType);

    MarkType GetMark() const;
};

class PlayersController
{
private:
    int m_currentPlayer;
    std::vector<Player> m_players;
public:
    PlayersController() = default;

    void Init( int playersCount );
    void NextPlayer();
    Player& GetCurrentPlayer();

};

#endif //PLAYER_CONTROLLER_H
