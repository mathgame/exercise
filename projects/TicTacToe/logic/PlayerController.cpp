#include "PlayerController.h"

void PlayersController::Init(int playersCount)
{
    m_currentPlayer = 0;
    m_players.push_back(MarkType::O);
    m_players.push_back(MarkType::X);
}

void PlayersController::NextPlayer()
{
    m_currentPlayer++;
    if( m_currentPlayer >= m_players.size())
    {
        m_currentPlayer = 0;
    }
}

Player &PlayersController::GetCurrentPlayer()
{
    return m_players.at(m_currentPlayer);
}

Player::Player(MarkType markType)
    : m_markType(markType)
{

}

MarkType Player::GetMark() const
{
    return m_markType;
}
