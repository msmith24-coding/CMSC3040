#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// This should spell NumericalNode.
// I do not feel like changing it beacause
// refactoring is dumb. Same with thePluralOfStatus variable.
struct NumicalNode 
{
    int data;
    NumicalNode* next = nullptr;
};

class LinkedList
{
    public:
        LinkedList() = default;
        ~LinkedList();
    private:
        NumicalNode* head = nullptr;
        NumicalNode* tail = nullptr;
        unsigned int size;
    private:
    public:
        unsigned int getSize() const;
    public:
        void addNumericalElement(int element); 
        void showNumerical(); 
        void showString();
        void sortNumicalList();
};

#endif // !NUMERICALLINKEDLIST_H_

