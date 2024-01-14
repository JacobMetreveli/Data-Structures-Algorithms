#pragma once
#include "Node.h"
#include <iostream>


class Queue {
    private:
        Node* first;
        Node* last;
        int length;
    
    public:
        Queue(int value) {
            Node* newNode = new Node(value);
            first = newNode;
            last = newNode;
            length = 1;
        }

        void enqueue(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                first = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
            length++;
        }

        int dequeue(int value) {
            if (length == 0) return INT32_MIN;
            Node* temp = first;
            int dequeuedValue = first->value;
            if (length == 1) {
                first = nullptr;
                last = nullptr;
                delete temp;
            } else {
                first = first->next;
            }
            delete temp;
            length--;        
            return dequeuedValue;
        }

        void printQueus() {
            Node* temp = first;
            while(temp) {
                std::cout << temp->value;
                temp = temp->next;
            }
        }
};