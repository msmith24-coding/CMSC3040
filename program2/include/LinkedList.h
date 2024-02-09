#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>

// This should spell NumericalNode.
// I do not feel like changing it beacause
// refactoring is dumb. Same with thePluralOfStatus variable.
struct NumicalNode 
{
    int data;
    NumicalNode* next = nullptr;
};

struct StringNode
{
    std::string data;
    StringNode* next = nullptr;
};

class LinkedList
{
    public:
        LinkedList() = default;
        ~LinkedList();
    private:
        NumicalNode* head = nullptr;
        NumicalNode* tail = nullptr;

        StringNode* strHead = nullptr;
        StringNode* strTail = nullptr;

        unsigned int size;
    private:
    public:
        unsigned int getSize() const;
    public:
        void addNumericalElement(int element); 
        void addStringElement(const std::string& element);
        
        void showNumerical(); 
        void showString();
        
        void sortNumicalList();
        void sortStringList();
};

#endif // !NUMERICALLINKEDLIST_H_

