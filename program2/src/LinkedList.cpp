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
    //delete tempNode;
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

void LinkedList::showNumerical()
{
    NumicalNode* currentNode = this->head;
    for(unsigned int i = 0; i < this->getSize(); ++i) {
        std::cout << "\t- " << currentNode->data << std::endl; 
        if(currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
    }
    //delete currentNode;
}

void LinkedList::sortNumicalList()
{
    NumicalNode* currentNode = new NumicalNode;
    NumicalNode* nextNode = new NumicalNode;
    //NumicalNode* tempNode = new NumicalNode;

    currentNode = this->head;
    nextNode = this->head->next;
    
    //std::cout << "-- [Before Sort] --" << std::endl;

    //this->showNumerical();
    
    //std::cout << "-- [Starting Sort] --" << std::endl;
    unsigned int counter = 0;
    while(counter <= 2048) {
        currentNode = this->head;
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





