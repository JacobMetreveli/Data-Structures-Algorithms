#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.h"

class LinkedList {
    private:
        int length;
        Node* head;
        Node* tail;
    public:
        LinkedList(int value);
        ~LinkedList();
        void append(int value);
        void prepend(int value);
        void deleteFirst();
        void deleteLast();
        void deleteNode(int index);
        Node* get(int index);
        bool set(int index, int value);
        bool insert(int index, int value);
        void reverse();
        void printList();
};

#endif // _LINKEDLIST_H_