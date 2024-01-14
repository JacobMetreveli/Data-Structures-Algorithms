#include "DoublyLinkedList.h"
#include <iostream>
#include "Node.h"


int main() {
    DoublyLinkedList* DLL = new DoublyLinkedList(10);
    DLL->append(11);
    DLL->prepend(9);
    DLL->append(12);



    DLL->printList();

    DLL->deleteNode(2);
    DLL->printList();

    return 0;
}