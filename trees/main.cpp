#include "BinarySearchTree.h"
#include <iostream>


int main() {
    BinarySearchTree* myBT = new BinarySearchTree();
    int arr[] = {47, 21, 76, 18, 27, 52, 82};

    for (int num: arr) {
        myBT->insert(num);
    }

    myBT->BFS();
    std::cout << "\n\n";
    myBT->DFSInOrder();

    return 0;
}