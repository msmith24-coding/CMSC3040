#include "../include/LinkedList.h"
#include <iostream>

LinkedList::~LinkedList()
{
    NumicalNode* tempNode = this->head;
    while(tempNode != nullptr) {
        this->head = tempNode;
        tempNode = tempNode->next;
        delete this->head;
    }

    StringNode* tempStrNode = this->strHead;
    while(tempStrNode != nullptr) {
        this->strHead = tempStrNode;
        tempStrNode = tempStrNode->next;
        delete this->strHead;
    }
}

unsigned int LinkedList::getSize() const
{
    return this->size;
}

void LinkedList::addNumericalElement(int element)
{
    NumicalNode* tempNode = new NumicalNode;
    tempNode->data = element;
    tempNode->next = this->head;
    this->head = tempNode;
    if(this->tail == nullptr) {
        this->tail = tempNode;
    }
    ++this->size;
}

void LinkedList::addStringElement(const std::string& element)
{
    StringNode* tempNode = new StringNode;
    tempNode->data = element;
    tempNode->next = this->strHead;
    this->strHead = tempNode;
    if(this->strTail == nullptr) {
        this->strTail = tempNode;
    }
    ++this->size;
}

void LinkedList::showNumerical()
{
    NumicalNode* currentNode = this->head;
    for(unsigned int i = 0; i < this->getSize(); ++i) {
        std::cout << "\t- " << currentNode->data << std::endl; 
        if(currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
    }
}

void LinkedList::showString()
{
    StringNode* currentNode = this->strHead;
    for(unsigned int i = 0; i < this->getSize(); ++i) {
        std::cout << "\t- " << currentNode->data << std::endl; 
        if(currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
    }
}

void LinkedList::sortNumicalList()
{
    NumicalNode* currentNode = new NumicalNode;
    NumicalNode* nextNode = new NumicalNode;

    currentNode = this->head;
    nextNode = this->head->next;
    
    //std::cout << "-- [Before Sort] --" << std::endl;
    //this->showNumerical(); 
    //std::cout << "-- [Starting Sort] --" << std::endl;
    unsigned int counter = 0;
    while(counter <= 2048) {
        currentNode = this->head;
        nextNode = this->head->next; // <-- Fixes everything
        for(unsigned int i = 0; i < this->getSize() - 1; ++i) {
            //std::cout << "[" << i << "] : (" << currentNode->data << " > " << nextNode->data << ") = " << (currentNode->data > nextNode->data) << std::endl; 
            if(currentNode->data > nextNode->data) {
                //tempNode = currentNode;
                //std::cout << "(tempNode = currentNode) : " << tempNode->data << std::endl;
            
                //currentNode = nextNode;
                //std::cout << "(currentNode = nextNode) : " << currentNode->data << std::endl;
            
                std::swap(currentNode->data, nextNode->data);

                if(nextNode->next != nullptr) {
                    nextNode = nextNode->next;
                    //std::cout << "(nextNode = nextNode->next) : " << nextNode->data << std::endl; 
                }
            } else { 
                if(currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                    //std::cout << "new currentNode : " << currentNode->data << std::endl;
                }
        
                if(nextNode->next != nullptr) {
                    nextNode = nextNode->next;
                    //std::cout << "new nextNode : " << nextNode->data << std::endl;
                }
            }
            //std::cout << std::endl;
        }
        counter++;
    }
}

void LinkedList::sortStringList()
{
    StringNode* currentNode = new StringNode;
    StringNode* nextNode = new StringNode;

    currentNode = this->strHead;
    nextNode = this->strHead->next;
    
    //std::cout << "-- [Before Sort] --" << std::endl;
    //this->showString();
    //std::cout << "-- [Starting Sort] --" << std::endl;
    
    unsigned int counter = 0;
    while(counter <= 2048) {
        currentNode = this->strHead;
        nextNode = this->strHead->next; // <-- Fixes everything
        
        for(unsigned int i = 0; i < this->getSize() - 1; ++i) {
            //std::cout << "[" << i << "] : (" << currentNode->data << " > " << nextNode->data << ") = " << (currentNode->data > nextNode->data) << std::endl; 
            
            if(currentNode->data.compare(nextNode->data) > 0) {
                //tempNode = currentNode;
                //std::cout << "(tempNode = currentNode) : " << tempNode->data << std::endl;
            
                //currentNode = nextNode;
                //std::cout << "(currentNode = nextNode) : " << currentNode->data << std::endl;
            
                std::swap(currentNode->data, nextNode->data);

                if(nextNode->next != nullptr) {
                    nextNode = nextNode->next;
                    //std::cout << "(nextNode = nextNode->next) : " << nextNode->data << std::endl; 
                }
            } else { 
                if(currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                    //std::cout << "new currentNode : " << currentNode->data << std::endl;
                }
        
                if(nextNode->next != nullptr) {
                    nextNode = nextNode->next;
                    //std::cout << "new nextNode : " << nextNode->data << std::endl;
                }
            }
            //std::cout << std::endl;
        }
        counter++;
    }
}

