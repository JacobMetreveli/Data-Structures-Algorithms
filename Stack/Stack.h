#pragma once
#include "Node.h"
#include <iostream>

class Stack {
    private:
        Node* top;
        int height;
    
    public:
        Stack(int value) {
            top = new Node(value);
            height = 1;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next = top;
            top = newNode;
            height++;
        }

        int pop() {
            if (height == 0) return INT32_MIN;
            
            Node* temp = top;
            int poppedValue = top->value;
            top = top->next;
            delete temp;
            height--;

            return poppedValue;
        }

        void printStack() {
            Node* temp = top;
            while(temp) {
                std::cout << temp->value << std::endl;
                temp = temp->next;
            }
        }

        void getHight() {
            std::cout << "Height: " << height << std::endl;
        }
};