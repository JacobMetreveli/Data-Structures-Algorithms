#pragma once
#include "Node.h"
#include <iostream>

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while(temp) {
                std::cout << temp->value << std::endl;
                temp = temp->next;
            }
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            length++;
        }

        void deleteLast() {
            Node* temp = tail;
            if (length == 0) return;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;
            if (index >= length / 2) {
                Node* temp = tail;
                for (int i = length - 1; i > index; i--) {
                    temp = temp->prev;
                }
                return temp;
            } else {
                Node* temp = head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp;
            }
        }

        bool set(int index, int value) {
            if (index < 0 || index >= length) return false;
            Node* temp = get(index);
            if (temp) {
                temp->value = value;
                return true;
            }
            return false;
        }

        bool insert(int index, int value) {
            if (index < 0 || index > length) return false;
            if (index == 0) {
                prepend(value);
                return true;
            }
            if (index == length) {
                append(value);
                return true;
            }
            Node* newNode = new Node(value);
            Node* before = get(index - 1);
            Node* after = before->next;
            before->next = newNode;
            newNode->prev = before;
            newNode->next = after;
            after->prev = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            Node* temp = get(index);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
        }
};