#include<bits/stdc++.h>
using namespace std;

bool f(int i, int sum, vector<int>&arr, vector<vector<int>>&dp){

    if(sum == 0) return 0;
    if(i==0) return arr[i] == sum;

    if(dp[i][sum] != -1) return dp[i][sum];

    bool notTake = f(i-1, sum, arr, dp);
    bool take=false;

    if(arr[i] <= sum){
        take = f(i-1, sum-arr[i], arr, dp);
    }

    return dp[i][sum] = take || notTake;
}

int main(){
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }


    int totalSum = 0;
    for(auto it : arr) totalSum += it;

    int target = totalSum/2;
    bool ans = true;

    if(totalSum%2!=0) ans = false;
    else{
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        ans = f(n-1, target, arr, dp);
    }

    if(ans==1)cout<<"true";
    else cout<<"false";
}