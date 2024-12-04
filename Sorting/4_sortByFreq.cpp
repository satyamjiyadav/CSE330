#include <bits/stdc++.h>
using namespace std;

void sortByFrequency(vector<int>& arr) {
    // Step 1: Count the frequency of each element using an unordered map
    unordered_map<int, int> freq_map;
    for (int num : arr) {
        freq_map[num]++;
    }

    // Step 2: Create a vector of pairs (element, frequency)
    vector<pair<int, int>> freq_vec;
    for (auto& entry : freq_map) {
        freq_vec.push_back(entry);
    }

    // Step 3: Sort the vector by frequency in descending order, and by element in ascending order if frequencies are the same
    sort(freq_vec.begin(), freq_vec.end(), [](pair<int, int>& a, pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second > b.second;  // Sort by frequency in descending order
        }
        return a.first < b.first;  // If frequencies are the same, sort by element in ascending order
    });

    // Step 4: Repopulate the array based on sorted frequency
    arr.clear();  // Clear the original array to repopulate it
    for (auto& entry : freq_vec) {
        int num = entry.first;
        int freq = entry.second;
        while (freq--) {
            arr.push_back(num);  // Add the element according to its frequency
        }
    }

    // Print the sorted array
    for (int num : arr) {
        cout << num << " ";
    }
}

int main() {
    int n;
    cin >> n;  // Input size of array

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // Input elements of array
    }

    sortByFrequency(arr);  // Call the function to sort by frequency

    return 0;
}
