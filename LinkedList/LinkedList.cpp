#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList(int value) {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while(head != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::append(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void LinkedList::prepend(int value) {
    Node* newNode = new Node(value);
    if (length == 0) {
        head = newNode;
        tail = newNode;
    } else {
        newNode = head->next;
        head->next = newNode;
    }
    length++;
}

Node* LinkedList::get(int index) {
    if (index < 0 || index >= length) return nullptr;
    if (index == 0) return head;
    if (index == length - 1) return tail;
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

void LinkedList::deleteLast() {
    if (length == 0) return;
    Node* temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node* pre = head;
        while (temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void LinkedList::deleteFirst() {
    if (length == 0) return;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    length--;
}

bool LinkedList::set(int index, int value) {
    Node* temp = get(index);
    if (temp) {
        temp->value = value;
        return true;
    }
    return false;
}

bool LinkedList::insert(int index, int value) {
    if (index < 0 || index > length) return false;
    if (index == 0) {
        prepend(value);
        return true;
    }
    if (index == length) {
        append(value);
        return true;
    }
    Node* temp = get(index - 1);
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
    length++;
    return true;
    return false;
}

void LinkedList::deleteNode(int index) {
    if (index < 0 || index >= length) return;
    if (index == 0) return deleteFirst();
    if (index == length - 1) return deleteLast();

    Node* prev = get(index - 1);
    Node* temp = prev->next;

    prev->next = temp->next;
    delete temp;
    length--;
}

void LinkedList::reverse() {
    Node* temp = head;
    head = tail;
    tail = temp;
    Node* after = temp->next;
    Node* before = nullptr;
    for (int i = 0; i < length; i++) {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
} 

void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        std::cout << temp->value << std::endl;
        temp = temp->next;
    }
}