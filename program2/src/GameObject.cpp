#include "../include/GameObject.h"

#include <sstream>
#include <string>

GameObject::GameObject()
{
    this->gameTitle = "";
    this->gameType = "";
    this->gameStatus = "";
    this->gameId = 0;
}

GameObject::GameObject(const std::string& _gameTitle, const std::string& _gameType, const std::string& _gameStatus, const std::string& _gameId)
{
    this->gameTitle = _gameTitle;
    this->gameType = _gameType;
    this->gameStatus = _gameStatus;
    this->gameId = std::stoi(_gameId);
}

void GameObject::setTitle(const std::string& _gameTitle) 
{
    this->gameTitle = _gameTitle;
}

void GameObject::setType(const std::string& _gameType)
{
    this->gameType = _gameType;
}

void GameObject::setStatus(const std::string& _gameStatus)
{
    this->gameStatus = _gameStatus;
}

void GameObject::setGameId(const std::string& _gameId)
{
    this->gameId = std::stoi(_gameId);
}

std::string GameObject::getGameTitle() const
{
    return this->gameTitle;
}

std::string GameObject::getGameType() const
{
    return this->gameType;
}

std::string GameObject::getGameStatus() const 
{
    return this->gameStatus;
}

int GameObject::getGameId() const
{
    return this->gameId;
}

std::string GameObject::showInfo()
{
    std::stringstream ss;
    ss << "| " << this->getGameTitle() << " | " << this->getGameId() << " | " << this->getGameType() << " | " << this->getGameStatus() << " |";

    return ss.str();
}
