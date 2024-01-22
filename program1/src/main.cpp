#include <iostream>
#include <string>

#include <Structure.h>

void testStack();
void testQueue();
void testPriorityQueue();

int main()
{
    testStack();
    testQueue();
    testPriorityQueue();
    return 0;
}

void testStack()
{
    // Setup.
    Stack<std::string> stack;
    std::string result;
    
    std::cout << "-- Testing Stack --" << std::endl;

    // Execution.
    stack.add("Kobe");
    stack.add("Milo");
    stack.add("Izzy");
    stack.add("Benji");
    
    result = stack.remove();
    std::cout << result << std::endl;

    stack.add("Ruby");

    result = stack.remove();
    std::cout << result << std::endl;

    stack.add("Delilah");
    stack.add("Benny");

    result = stack.remove();
    std::cout << result << std::endl;

    result = stack.remove();
    std::cout << result << std::endl;

    result = stack.remove();
    std::cout << result << std::endl;

    stack.add("Sugar");
    stack.add("Katie");
    stack.add("Harley");

    result = stack.remove();
    std::cout << result << std::endl;

}

void testQueue()
{
    // Setup.
    Queue<std::string> queue;
    std::string result;

    std::cout << "-- Testing Queue --" << std::endl;

    // Execution.
    queue.put("Kobe");
    queue.put("Milo");
    queue.put("Izzy");
    queue.put("Benji");

    result = queue.get();
    std::cout << result << std::endl;

    queue.put("Ruby");

    result = queue.get();
    std::cout << result << std::endl;

    queue.put("Delilah");
    queue.put("Benny");

    result = queue.get();
    std::cout << result << std::endl;

    result = queue.get();
    std::cout << result << std::endl;

    result = queue.get();
    std::cout << result << std::endl;

    queue.put("Sugar");
    queue.put("Katie");
    queue.put("Harley");

    result = queue.get();
    std::cout << result << std::endl;
}

void testPriorityQueue()
{
    // Setup.
    PriorityQueue<std::string> heap;
    std::string result;

    std::cout << "-- Testing Priority Queue --" << std::endl;
    
    // Execution.
    heap.put("Kobe");
    heap.put("Milo");
    heap.put("Izzy");
    heap.put("Benji");

    result = heap.get();
    std::cout << result << std::endl;

    heap.put("Ruby");

    result = heap.get();
    std::cout << result << std::endl;

    heap.put("Delilah");
    heap.put("Benny");

    result = heap.get();
    std::cout << result << std::endl;

    result = heap.get();
    std::cout << result << std::endl;

    result = heap.get();
    std::cout << result << std::endl;

    heap.put("Sugar");
    heap.put("Katie");
    heap.put("Harley");

    result = heap.get();
    std::cout << result << std::endl;
    
}
