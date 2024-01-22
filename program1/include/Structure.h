#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include <vector>
#include <algorithm>

template<typename T>
class Stack
{
    private: // Utility Variables.
        std::vector<T> data;
    private: // Utility Methods.
        bool isEmpty() const;
    public: // Control Methods.
        void add(const T& value);
        T remove();
};

template<typename T>
class Queue
{
    private: // Utility Variables.
        std::vector<T> data;
    private: // Utility Methods.
        bool isEmpty() const;
    public: // Control Methods.
        void put(const T& value);
        T get();
};

template<typename T>
class PriorityQueue
{
    private: // Utility Variables.
        std::vector<T> data;
    private: // Utility Methods.
        bool isEmpty() const;
    public: // Control Methods.
        void put(const T& value);
        T get();

};

template<typename T>
class Dequeue
{
    private: // Utility Variables.
        std::vector<T> data;
    private: // Utility Methods.
        bool isEmpty() const;
    public: // Control Methods.
        void add(const T& value);
        T remove();
};

//
//  STACK CLASS
//

// Utility Methods:
template<typename T>
bool Stack<T>::isEmpty() const
{
    return this->data.empty();
}

// Control Methods: 
template<typename T>
void Stack<T>::add(const T& value)
{
    this->data.push_back(value);
}

template<typename T>
T Stack<T>::remove()
{
    if(this->isEmpty()) {
        return nullptr;
    }
    T result = this->data.back();
    this->data.pop_back();

    return result;
}

//
// QUEUE CLASS
//

// Utility Methods:
template<typename T>
bool Queue<T>::isEmpty() const
{
    return this->data.empty();
}

// Control Methods:
template<typename T>
void Queue<T>::put(const T& value)
{
    this->data.push_back(value);
}

template<typename T>
T Queue<T>::get()
{
    if(this->isEmpty()) {
        return nullptr;
    }
    T result = this->data.front();
    this->data.erase(this->data.begin());

    return result;
}

//
// PRIORITY QUEUE CLASS (HEAP)
//

// Utility Methods:
template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
    return this->data.empty();
}

// Control Methods:
template<typename T>
void PriorityQueue<T>::put(const T& value)
{
    this->data.push_back(value);
    std::sort(this->data.begin(), this->data.end());
}

template<typename T>
T PriorityQueue<T>::get()
{
    if(this->isEmpty()) {
        return nullptr;
    }
    T result = this->data.front();
    this->data.erase(this->data.begin());

    return result;
}

//
// DEQUEUE CLASS
//
template<typename T>
bool Dequeue<T>::isEmpty() const
{
    return this-data.empty();
}

// Control Methods:
template<typename T>
void Dequeue<T>::add(const T& value)
{

}

template<typename T>
T Dequeue<T>::remove()
{
    
}


#endif
