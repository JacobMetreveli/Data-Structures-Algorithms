#include <iostream>



void selectionSort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}


int main() {
    int myArray[] = {6, 4, 2, 5, 1, 3};

    int size = sizeof(myArray) / sizeof(myArray[0]);

    selectionSort(myArray, size);

    for (int value : myArray) {
        std::cout << value << " ";
    }

    return 0;
}