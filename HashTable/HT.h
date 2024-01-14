#pragma once
#include <iostream>
#include "Node.h"
#include <vector>


class HashTable {
    private:
        static const int SIZE = 7;
        Node* dataMap[SIZE];

        int hash(std::string key) {
            int hash = 0;
            for (int i = 0; i < key.size(); i++) {
                int asciiValue = int(key[i]);
                hash = (hash + asciiValue * 23) % SIZE;
            }
            return hash;
        }
    
    public:
        void printTable() {
            for(int i = 0; i < SIZE; i++) {
                std::cout << i << ":" << std::endl;
                if (dataMap[i]) {
                    Node* temp = dataMap[i];
                    while(temp) {
                        std::cout << "\t{" << temp->key << ", " << temp->value << "}" << std::endl;
                        temp = temp->next;
                    }
                }
            }
        }

        void set(std::string key, int value) {
            int index = hash(key);
            Node* newNode = new Node(key, value);
            if (dataMap[index] == nullptr) {
                dataMap[index] = newNode;
            } else {
                Node* temp = dataMap[index];
                while(temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        int get(std::string key) {
            int index = hash(key);
            Node* temp = dataMap[index];
            while (temp) {
                if (temp->key == key) return temp->value;
                temp = temp->next;
            }
            return 0;
        }

        std::vector<std::string> keys() {
            std::vector<std::string> keys {};
            for (Node* temp: dataMap) {
                while(temp) {
                    keys.push_back(temp->key);
                    temp = temp->next;
                }
            }
            return keys;
        }
};