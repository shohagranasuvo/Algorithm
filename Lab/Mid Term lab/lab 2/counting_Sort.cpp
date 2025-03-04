#include <iostream>
#include <algorithm>

using namespace std;

void countingSort(int arr[], int size) {
    if (size <= 0) return;

    
    int maxElement = arr[0];
    int minElement = arr[0];
    for (int i = 1; i < size; i++) {
        maxElement = max(maxElement, arr[i]);
        minElement = min(minElement, arr[i]);
    }
    
    int range = maxElement - minElement + 1;
   int shift;
if (minElement < 0) {
    shift = -minElement;
} else {
    shift = 0;
}

    
    int* count = new int[range]();
    int* output = new int[size];

    
    for (int i = 0; i < size; i++) {
        count[arr[i] + shift]++;
    }

    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i] + shift] - 1] = arr[i];
        count[arr[i] + shift]--;
    }

    
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    
    delete[] count;
    delete[] output;
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {4, 2, -1, 8, 3, 9, 2, -5, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, size);
    
    countingSort(arr, size);
    
    cout << "Sorted array: ";
    printArray(arr, size);
    
    return 0;
}