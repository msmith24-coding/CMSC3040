#ifndef GAMEOBJECTCOLLECTION_H_
#define GAMEOBJECTCOLLECTION_H_ 

#include "GameObject.h"

class GameObjectCollection 
{
    private:
        unsigned int capacity;
        unsigned int size;
        GameObject* games;
    public:
        GameObjectCollection();
    public:
        unsigned int getCapacity() const;
        unsigned int getSize() const;
    public:
        GameObject& getByIndex(unsigned int index) const;
        bool addGame(GameObject& game);
        bool removeGame(unsigned int index);
        void clean();
};

#endif // !GAMEOBJECTCOLLECTION_H_
