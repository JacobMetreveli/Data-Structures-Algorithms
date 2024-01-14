#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

int main() {
    Stack* newStack = new Stack(10);
    newStack->push(9);
    newStack->printStack();

    std::cout << "Popped value: " << newStack->pop() << std::endl;
    std::cout << "Popped value: " << newStack->pop() << std::endl;
    std::cout << "Popped value: " << newStack->pop() << std::endl;



    return 0;
}