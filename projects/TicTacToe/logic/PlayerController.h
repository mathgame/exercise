#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include <vector>

class Msg;
class Player
{
private:

public:
    Player() = default;

};

class PlayersController
{
private:
    std::vector<Player> m_players;
public:
    PlayersController() = default;

    void Init( int playersCount );
    void NextPlayer();
    void RecieveMsg(const Msg& msg);
};

#endif //PLAYER_CONTROLLER_H
