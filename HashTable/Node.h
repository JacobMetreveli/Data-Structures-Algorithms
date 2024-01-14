#pragma once
#include <string>

class Node {
    public:
        std::string key;
        int value;
        Node* next;

        Node(std::string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};