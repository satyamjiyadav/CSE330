// Given an integer values n and k,
// the task is to find the value of Binomial Coefficient C(n, k).


// fact(n) / fact(n-k)*fact(k);
// recursive relaion c(n,k) = c(n-1, k-1) + c(n-1, k);
// Base case c(n,0) = 1;
// c(n,n) = 1;

#include<bits/stdc++.h>
using namespace std;

int bin(int n, int k, vector<vector<int>>&dp){
    // k can not be grater then k so we return 0 here
    if(k>n) return 0;

    if(k==0 || k==n) return 1;

    if(dp[n][k] != -1) return dp[n][k];

    return dp[n][k] =  bin(n-1, k-1, dp) + bin(n-1, k, dp);
}

int main(){
    int n,k;
    cin>>n>>k;

    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    int ans = bin(n,k,dp);
    cout<<ans;
}
