#include <bits/stdc++.h>
using namespace std;

// Function to merge two subarrays
void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Create temporary subarrays
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    // Merge the subarrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Recursive function to sort array using merge sort
void mergeSortRecursive(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort the left and right halves
        mergeSortRecursive(arr, left, mid);
        mergeSortRecursive(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cin>>n;
    
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    mergeSortRecursive(arr, 0, arr.size() - 1);

    // Print the sorted array
    for (int x : arr) cout << x << " ";
    return 0;
}
