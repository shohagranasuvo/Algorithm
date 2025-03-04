#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum element to determine range
    int maxElement = *max_element(arr.begin(), arr.end());
    
    // Handle negative numbers by shifting if needed
    int minElement = *min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;
    int shift = (minElement < 0) ? -minElement : 0;

    // Create counting array
    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Count occurrences of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] + shift]++;
    }

    // Calculate cumulative count
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] + shift] - 1] = arr[i];
        count[arr[i] + shift]--;
    }

    // Copy the sorted elements back to original array
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the counting sort
int main() {
    vector<int> arr = {4, 2, -1, 8, 3, 9, 2, -5, 7};
    
    cout << "Original array: ";
    printArray(arr);
    
    countingSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}