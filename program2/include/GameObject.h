#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include <string>

class GameObject
{
    private:
        std::string gameTitle;
        std::string gameType;
        std::string gameStatus;
        int gameId;
    public:
        GameObject();
        GameObject(const std::string& gameTitle, const std::string& gameType, const std::string& gameStatus, const std::string& gameId);
    public: // Setters
        void setTitle(const std::string& gameTitle);
        void setType(const std::string& gameType);
        void setStatus(const std::string& gameStatus); 
        void setGameId(const std::string& gameId);
    public: // Getters
        std::string getGameTitle() const;
        std::string getGameType() const;
        std::string getGameStatus() const;
        int getGameId() const;
    public: // Utility Methods
        std::string showInfo();
        
};

#endif // !GAMEOBJECT_H_
