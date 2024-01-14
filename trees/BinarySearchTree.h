#pragma once
#include "Node.h"
#include <iostream>
#include <queue>

class BinarySearchTree {
    private:
        Node* root;

    public:
        BinarySearchTree() {
            root = nullptr;
        }

        bool insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return true;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return false;
                if (newNode->value > temp->value) {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return true;
                    }
                    temp = temp->right;
                } else {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return true;
                    }
                    temp = temp->left;
                }
            }
        }

        bool contains(int value) {
            Node* temp = root;
            while(temp) {
                if (temp->value < value) {
                    temp = temp->left;
                } 
                else if(temp->value > value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }

        void BFS() {
            std::queue<Node*> myQueue;
            myQueue.push(root);

            while (myQueue.size() > 0) {
                Node* currentNode = myQueue.front();
                myQueue.pop();
                std::cout << currentNode->value << " ";
                if (currentNode->left != nullptr) {
                    myQueue.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    myQueue.push(currentNode->right);
                }
            }
        }

        // Depth first search pre order with overloaded callable funcion.
        void DFSPreOrder(Node* currentNode) {
            std::cout << currentNode->value << " ";
            if (currentNode->left) {
                DFSPreOrder(currentNode->left);
            }
            if (currentNode->right) {
                DFSPreOrder(currentNode->right);
            }
        }
        void DFSPreOrder() { DFSPreOrder(root); }

        // Depth first search post order with overloaded callable function.
        // Only difference from the pre order search is that we output the values after the initial search.
        void DFSPostOrder(Node* currentNode) {
            if (currentNode->left) {
                DFSPostOrder(currentNode->left);
            }
            if (currentNode->right) {
                DFSPostOrder(currentNode->right);
            }
            std::cout << currentNode->value << " ";
        }
        void DFSPostOrder() { DFSPostOrder(root);}

        // DFS In order with overloaded callable function.
        // This time we output the value in the middle -> Go left, Output, Go right.
        void DFSInOrder(Node* currentNode) {
            if(currentNode->left) {
                DFSInOrder(currentNode->left);
            }
            std::cout << currentNode->value << " ";
            if(currentNode->right) {
                DFSInOrder(currentNode->right);
            }
        }
        void DFSInOrder() { DFSInOrder(root);}

};