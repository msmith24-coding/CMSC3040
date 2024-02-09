#include <iostream>
#include <ostream>
#include <sched.h>
#include <string>
#include "../include/CSVParser.h"
#include "../include/GameObject.h"
#include "../include/GameObjectCollection.h"
#include "../include/LinkedList.h"

void populateCollection(CSVParser& parser, GameObjectCollection* collection);

bool loadDataFile(GameObjectCollection* collection);

unsigned int showMainMenu(); // DONE: This is obvious.
unsigned int showAddGameMenu(GameObjectCollection* collection); // DONE: Shows menu to add game.
unsigned int showRemoveGameMenu(GameObjectCollection* collection); // DONE: Shows menu to remove game.
unsigned int showListGamesByTitle(GameObjectCollection* collection); // TODO: Show game titles in alphabetical order. 
unsigned int showListGamesById(GameObjectCollection* collection); // TODO: Show game ids in numerical order.
unsigned int showStatusMenu(GameObjectCollection* collection); // DONE: Shows menu to change the status.  
unsigned int showGameInfoById(GameObjectCollection* collection); // TODO: User enters an id and info about that game is shown.
unsigned int showGameInfoByTitle(GameObjectCollection* collection); // DONE: User enters a title and info aouttaht game is shown.
unsigned int showAllGameInfo(GameObjectCollection* collection); // DONE:

enum MainMenuOptions
{
    ADD_GAME,
    REMOVE_GAME,
    LIST_GAMES_BY_ID,
    LIST_GAMES_BY_TITLE,
    CHANGE_STATUS,
    SHOW_GAME_BY_ID,
    SHOW_GAME_BY_TITLE,
    SHOW_ALL,
    EXIT
};

int main()
{
    GameObjectCollection collection = GameObjectCollection();
    bool err = loadDataFile(&collection);
    if(err) {
        return 1;
    }
    bool isRunning = true;

    while(isRunning) {
        unsigned int option = showMainMenu();
        switch (option) {
            case MainMenuOptions::ADD_GAME: showAddGameMenu(&collection); break;
            case MainMenuOptions::REMOVE_GAME: showRemoveGameMenu(&collection); break;
            case MainMenuOptions::LIST_GAMES_BY_ID: showListGamesById(&collection); break;
            case MainMenuOptions::LIST_GAMES_BY_TITLE: return 1;
            case MainMenuOptions::CHANGE_STATUS: showStatusMenu(&collection); break;
            case MainMenuOptions::SHOW_GAME_BY_ID: showGameInfoById(&collection); break;
            case MainMenuOptions::SHOW_GAME_BY_TITLE: showGameInfoByTitle(&collection); break;
            case MainMenuOptions::SHOW_ALL: showAllGameInfo(&collection); break;
            case MainMenuOptions::EXIT: return 0;
        }
    }

    return 0;
}

bool loadDataFile(GameObjectCollection* collection)
{
    std::string filePath;
    std::cout << "Enter a file name ending with .csv > ";
    std::getline(std::cin, filePath);
    
    CSVParser parser = CSVParser(filePath, 1000, 3);

    bool err = parser.openFile();
    if(err) {
        std::cerr << "Failed to open." << std::endl;
        return true;
    }
    
    std::cout << std::endl;

    parser.readFile();

    populateCollection(parser, collection);

    parser.closeFile();

    return false;
}

void populateCollection(CSVParser& parser, GameObjectCollection* collection)
{
    unsigned int MAX_COLS = 4;
    unsigned int MAX_ROWS = parser.getSize() / MAX_COLS;

    for(unsigned int row = 1; row < MAX_ROWS; ++row) {
        GameObject* tempObject = new GameObject(); 
        tempObject->setTitle(parser.getData(row, 0));
        tempObject->setGameId(parser.getData(row, 1));
        tempObject->setType(parser.getData(row, 2));
        tempObject->setStatus(parser.getData(row, 3));
        collection->addGame(*tempObject);
        //tempObject->showInfo();
    }
}

unsigned int showListGamesById(GameObjectCollection* collection)
{
    std::cout << std::endl;
    std::cout << "Listing all game IDs (Numeriaclly)" << std::endl;

    LinkedList list = LinkedList();
    
    

    for(unsigned int i = collection->getSize() - 1; i > 0; --i) {
        std::cout << "Adding: " << collection->getByIndex(i).getGameId() << std::endl;
        list.addNumericalElement(collection->getByIndex(i).getGameId());
    }
    
    list.addNumericalElement(collection->getByIndex(0).getGameId());

    list.sortNumicalList();

    list.showNumerical(); 

    return 0;
}

unsigned int showAllGameInfo(GameObjectCollection* collection)
{
    std::cout << std::endl;
    std::cout << "Showing all game info:" << std::endl;
    
    for(unsigned int i = 0; i < collection->getSize(); ++i) {
        std::cout << "\t" << collection->getByIndex(i).showInfo() << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

unsigned int showAddGameMenu(GameObjectCollection* collection)
{
    std::cout << std::endl;
    
    std::cout << "Adding a new game:" << std::endl;
    std::cout << "\tEnter a game title > ";

    std::string gameTitle;

    std::cin.ignore();
    std::getline(std::cin, gameTitle);
   
    std::string gameId;
    std::cout << "\tEnter a game id > "; 
    std::getline(std::cin, gameId);

    std::string gameType;
    std::cout << "\tEnter a game type > ";
    std::getline(std::cin, gameType);
    
    std::string thePluralForStatus[] = { "Want", "NeedFaq", "GoodToGo", "GetRidOf" };
    for(unsigned int i = 0; i <= 3; ++i) {
        std::cout << "\t[" << (i + 1) << "] " << thePluralForStatus[i] << std::endl; 
    }

    unsigned int statusOption = 1024;
    while(statusOption > 4 || statusOption <= 0) {
        std::cout << "\t\tEnter a numbered option > ";
        std::cin >> statusOption;
    }
    
    std::string gameStatus = thePluralForStatus[statusOption - 1];

    GameObject* gameObject = new GameObject(gameTitle, gameType, gameStatus, gameId);
    collection->addGame(*gameObject);
    
    std::cout << "Added \"" << gameObject->getGameTitle() << "\" to the database." << std::endl;
    std::cout << std::endl;
    return 0;
}

unsigned int showRemoveGameMenu(GameObjectCollection* collection)
{
    std::cout << std::endl;

    std::cout << "Removing a game:" << std::endl;
    for(unsigned int i = 0; i < collection->getSize(); ++i) {
        std::cout << "\t[" << (i + 1) << "] " << collection->getByIndex(i).getGameTitle() << std::endl;
    } 
    
    unsigned int option = 1024;
    while((option > (collection->getSize() + 1)) || (option <= 0)) {
        std::cout << "\t\tEnter a numbered option > ";
        std::cin >> option;
    }
    
    option--;

    std::cout << "Removing all data for \"" << collection->getByIndex(option).getGameTitle() << "\"" << std::endl; 

    bool result = collection->removeGame(option); 
    if(!result) {
        std::cerr << "[ERR] : Failed to remove game from the collection." << std::endl;
        return 1;
    }
     
    std::cout << std::endl;
    
    return 0;
}

unsigned int showStatusMenu(GameObjectCollection* collection)
{
    std::cout << std::endl;
    for(unsigned int i = 0; i < collection->getSize(); ++i) {
        std::cout << "[" << (i + 1) << "] " << collection->getByIndex(i).getGameTitle() << std::endl;
    } 

    unsigned int option = 1024;
    while((option > (collection->getSize() + 1)) || (option <= 0)) {
        std::cout << "Enter a numbered option > ";
        std::cin >> option;
    }
    
    option--;

    std::cout << std::endl;
    std::cout << "Enter a new status for \"" << collection->getByIndex(option).getGameTitle() << "\" (Currently: " << collection->getByIndex(option).getGameStatus() << ")" << std::endl;
    
    std::string thePluralForStatus[] = { "Want", "NeedFaq", "GoodToGo", "GetRidOf" };
    for(unsigned int i = 0; i <= 3; ++i) {
        std::cout << "[" << (i + 1) << "] " << thePluralForStatus[i] << std::endl; 
    }

    unsigned int statusOption = 1024;
    while(statusOption > 4 || statusOption <= 0) {
        std::cout << "Enter a numbered option > ";
        std::cin >> statusOption;
    }
    
    std::string newStatus = thePluralForStatus[statusOption - 1];

    collection->getByIndex(option).setStatus(newStatus);
    std::cout << "Changed the status of " << collection->getByIndex(option).getGameTitle() << " to " << collection->getByIndex(option).getGameStatus() << "." << std::endl;
    std::cout << std::endl;

    return 0;
}

unsigned int showGameInfoById(GameObjectCollection* collection)
{
    std::cout << std::endl;
    std::cout << "Showing all IDs:" << std::endl;
    for(unsigned int i = 0; i < collection->getSize(); ++i) {
        std::cout << "\t- " << collection->getByIndex(i).getGameId() << std::endl;
    }

    int selectedId;
    unsigned int selectedIndex;
    bool isValid = false;
     
    while(!isValid) {
        std::cout << "\t\tEnter a game ID > ";
        std::cin >> selectedId;
        
        for(unsigned int i = 0; i < collection->getSize(); ++i) {
            if(collection->getByIndex(i).getGameId() == selectedId) {
                selectedIndex = i;
                isValid = true;
            }
        }
        selectedId = 0;
    }

    std::cout << collection->getByIndex(selectedIndex).showInfo() << std::endl;
    std::cout << std::endl;

    return 0;
}

unsigned int showGameInfoByTitle(GameObjectCollection* collection)
{
    std::cout << std::endl;
    std::cout << "Showing all titles:" << std::endl;
    for(unsigned int i = 0; i < collection->getSize(); ++i) {
        std::cout << "\t- \"" << collection->getByIndex(i).getGameTitle() << "\"" << std::endl;
    }

    std::string selectedTitle;
    unsigned int selectedIndex;
    bool isValid = false;
     
    std::cin.ignore();
    while(!isValid) {
        std::cout << "\t\tEnter a game title > ";
        std::getline(std::cin, selectedTitle);
        
        for(unsigned int i = 0; i < collection->getSize(); ++i) {
            if(collection->getByIndex(i).getGameTitle() == selectedTitle) {
                selectedIndex = i;
                isValid = true;
            }
        }
        selectedTitle.clear();
    }

    std::cout << collection->getByIndex(selectedIndex).showInfo() << std::endl;
    std::cout << std::endl;

    return 0;
}

unsigned int showMainMenu()
{
    std::string options[] = { "Add a game", "Remove a game", "List game IDs", "List game titles", "Change Status", "Show game info (Id)", "Show game info (title)", "Show all game info", "Exit"};
    
    std::cout << "---------------------------------------" << std::endl; 
    for(unsigned int i = 0; i < (EXIT + 1); ++i) {
        std::cout << "[" << (i + 1) << "] " << options[i] << std::endl;
    }
        
    unsigned int option = 100;
    
    while((option > (EXIT + 1)) || (option <= 0)) {
        std::cout << "\tEnter a numbered option > ";
        std::cin >> option;     
    } 

    return option - 1;
}
