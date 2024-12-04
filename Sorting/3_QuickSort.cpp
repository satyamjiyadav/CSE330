#include <bits/stdc++.h>
using namespace std;

// Function to partition the array into two halves
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index for the smaller element

    // Rearrange elements to ensure elements smaller than pivot are on the left
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment index for smaller element
            swap(arr[i], arr[j]);  // Swap smaller element with element at i
        }
    }
    swap(arr[i + 1], arr[high]);  // Move pivot to the correct position
    return i + 1;  // Return the partition index
}

// Function to sort the array using quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);  // Left part
        quickSort(arr, pi + 1, high); // Right part
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);  // Example array

    for(int i=0; i<n; i++)cin>>arr[i];

    quickSort(arr, 0, arr.size() - 1);  // Call quickSort function

    // Print the sorted array
    for (int i : arr) {
        cout << i << " ";
    }
    return 0;
}
