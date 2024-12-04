#include<bits/stdc++.h>
using namespace std;



int f(int ind, int W, vector<int>&wt, vector<int>&val, int n, vector<vector<int>>&dp){
    if (ind == n-1){
        if(W >= wt[ind]){
            return val[ind];
        }
        return 0;
    }

    if(dp[ind][W] != -1) return dp[ind][W];

    int notTake = f(ind+1, W, wt, val, n, dp);

    int take = 0;

    if(W >= wt[ind]){
        take = val[ind] + f(ind+1, W-wt[ind], wt, val, n, dp);
    }

    return dp[ind][W] = max(take, notTake);
}

int main(){
    int n;
    cin>>n;

    vector<int>profit(n);
    vector<int>weight(n);

    for(int i=0; i<n; i++){
        cin>>profit[i];
    }
    for(int i=0; i<n; i++){
        cin>>weight[i];
    }
    int capacity;
    cin>>capacity;
    vector<vector<int>>dp(n, vector<int>(capacity+1, -1));

    int ans = f(0, capacity, weight, profit, n, dp);

    cout<<ans;
}