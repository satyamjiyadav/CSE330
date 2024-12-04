#include <bits/stdc++.h>
using namespace std;

// find unique pair
// Input: arr[ ] = {1, 5, 3, 4, 2}, K = 3
// Output: 2
// Explanation: There are 2 distinct pairs with difference 3, the pairs are {1, 4} and {5, 2} 



int main(){
    int n;
    cin>>n;

    vector<int>arr(n);

    for(int i=0; i<n; i++)cin>>arr[i];

    int k;
    cin>>k;

    unordered_map<int,int>mp;

    int ans=0;

    for(auto it:arr){
        mp[it]++;
    }

    if(k==0){
        for(auto it : mp){
            if(it.second>1)ans++;
        }
    }
    else{
        for(auto it : mp){
            if(mp.find(it.first+k) != mp.end()){
                ans++;
            }
        }        
    }

    cout<<ans;
}