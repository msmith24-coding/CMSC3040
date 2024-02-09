#include "../include/GameObjectCollection.h"

GameObjectCollection::GameObjectCollection()
{
    this->capacity = 1000;
    this->size = 0;
    this->games = new GameObject[this->capacity];
}

unsigned int GameObjectCollection::getCapacity() const
{
    return this->capacity;
}

unsigned int GameObjectCollection::getSize() const
{
    return this->size;
}

bool GameObjectCollection::addGame(GameObject& game)
{
    if(this->getSize() <= 0) {
        this->games[this->size] = game;
        this->size++;
        return true;
    }
    if(this->getSize() >= this->getCapacity()) {
        return false;
    }
    this->games[this->size] = game;
    this->size++;
    return true;
}

bool GameObjectCollection::removeGame(unsigned int index)
{
    if(this->getSize() <= 0) {
        return false;
    }

    for(unsigned int i = index; i < this->getSize() - 1; ++i) {
        this->games[i] = this->games[i + 1];
    }    

    this->size--;

    GameObject* tempGames = new GameObject[this->capacity];
    for(unsigned int i = 0; i < this->getSize(); ++i) {
        tempGames[i] = this->games[i];
    }

    delete [] this->games;

    this->games = tempGames;
    
    // delete [] tempGames;

    return true; 
}

GameObject& GameObjectCollection::getByIndex(unsigned int index) const
{
    return this->games[index]; 
}

void GameObjectCollection::clean()
{
    delete [] this->games;
}
