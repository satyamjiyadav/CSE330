#include<bits/stdc++.h>
using namespace std;


int f(int i, int prev, vector<int>&arr, vector<vector<int>>&dp){
    int n = arr.size();

    if(i==n) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int notTake = f(i+1, prev, arr, dp);

    int take = 0;

    if(prev==-1 || arr[i] > arr[prev]){
        take = 1 + f(i+1, i, arr, dp);
    }

    return dp[i][prev+1] = max(take, notTake);
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    int ans = f(0, -1, arr, dp);

    cout<<ans;
}