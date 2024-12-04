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

// Iterative merge sort
void mergeSortIterative(vector<int> &arr) {
    int n = arr.size();

    for (int currSize = 1; currSize < n; currSize *= 2) {
        for (int left = 0; left < n - 1; left += 2 * currSize) {
            int mid = min(left + currSize - 1, n - 1);
            int right = min(left + 2 * currSize - 1, n - 1);

            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];
    
    mergeSortIterative(arr);

    // Print the sorted array
    for (int x : arr) cout << x << " ";
    return 0;
}
