#include "LinkedList.h"
#include <iostream>

int main() {
    LinkedList* LL = new LinkedList(1);
    
    LL->append(2);
    LL->append(3);
    LL->append(4);
    LL->reverse();
    LL->printList();

    
}