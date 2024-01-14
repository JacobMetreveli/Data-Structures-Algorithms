#include <iostream>


void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
    // Split the array into 2 sub-arrays equal in size.
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    // Populate the 2 sub-arrays.
    for (int i = 0; i < leftArraySize; i++) {
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++) {
        rightArray[j] = array[midIndex + 1 + j];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;

    //While loop runs until one of the 2 arrays is empty
    while (i < leftArraySize && j < rightArraySize) {
        if (leftArray[i] <= rightArray[j]) {
            array[index] = leftArray[i];
            index++;
            i++;
        } else {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

    // Run one of these while loops to finish itterating through items.
    while (i < leftArraySize) {
        array[index] = leftArray[i];
        index++;
        i++;
    }

    while (j < rightArraySize) {
        array[index] = rightArray[j];
        index++;
        j++;
    }
}


void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;

    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex + 1, rightIndex);

    merge(array, leftIndex, midIndex, rightIndex);
}


int main() {
    int myArray[] = {3, 1, 4, 2};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(myArray, leftIndex, rightIndex);

    for (int value : myArray) {
        std::cout << value << " ";
    }
}