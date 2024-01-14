#include <iostream>
#include "Node.h"


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while(head != nullptr) {
                head = head->next;
                delete temp;
                temp = head;
            } 
        }

        void append(int value) {
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

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteLast() {
            if (length == 0) return;
            Node* temp = tail;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                Node* pre = tail;
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

        void deleteFirst() {
            if (length == 0) return;
            if (length == 1) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index>= length) {
                return nullptr;
            } else {
                if (index == 0) {
                    return head;
                } else {
                    Node* temp = head;
                    for (int i = 0; i < index; i++) {
                        temp = temp->next;
                    }
                    return temp;
                }
            }
        }

        bool set(int index, int value) {
            Node* temp = get(index);
            if (temp != nullptr) {
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
            Node* temp = get(index - 1);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }

        void deleteNode(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) return deleteFirst();
            if (index == length - 1) return deleteLast();
            
            Node* prev = get(index - 1);
            Node* temp = prev->next;
            
            prev->next = temp->next;
            delete temp;
            length--;
            return;
        }

        void reverse() {
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

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                std::cout << temp->value << std::endl;
                temp = temp->next;
            }
        }

        void printLength() {
            std::cout << "Length: " << length << std::endl;
        }
};




int main() {
    LinkedList* newlist = new LinkedList(0);
    newlist->append(1);
    newlist->append(2);
    newlist->append(3);
    newlist->append(4);
    newlist->append(5);
    newlist->printList();

    newlist->reverse();
    newlist->printList();




    return 0;
}