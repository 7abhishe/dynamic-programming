#include <iostream>
#include <vector>
using namespace std;

// Helper function to swap two elements in an array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Function to heapify a subtree with root at index i in a vector
void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // Left child
    int r = 2 * i + 2; // Right child

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    heapSort(arr);

    cout << "Sorted array: ";
    for (auto x : arr) {
        cout << x << " ";
    }

    return 0;
}
