#include <bits/stdc++.h>
using namespace std;

int findLengthOfSmallestSubarray(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left + 1 < n && arr[left] <= arr[left + 1]) {
        left++;
    }
    
    if (left == n - 1) {
        return 0;
    }

    while (right - 1 >= 0 && arr[right - 1] <= arr[right]) {
        right--;
    }

    int result = min(n - left - 1, right);

    // Check for merging the prefix and suffix
    int i = 0, j = right;
    while (i <= left && j < n) {
        if (arr[i] <= arr[j]) {
            result = min(result, j - i - 1);
            i++;
        } else {
            j++;
        }
    }

    return result;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++)cin>>arr[i];
    cout << findLengthOfSmallestSubarray(arr) << endl;
    
}
