#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string &s1, string &s2,vector<vector<int>>&dp){
    int n = s1.size(), m=s2.size();

    if(i==0) return j;
    if(j==0) return i;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i-1] == s2[j-1]){
        dp[i][j] = f(i-1, j-1, s1, s2, dp); 
    }
    else{
        int insert = 1 + f(i, j-1, s1, s2, dp);
        int del = 1 + f(i-1, j, s1, s2, dp);
        int replace = 1 + f(i-1, j-1, s1, s2, dp);

        dp[i][j] = min({insert, del, replace});
    }
    
    return dp[i][j];
}

int main(){
    // find minimum numbers of steps to convert s1 into s2
    // insert remove and replace

    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1,-1));

    int ans = f(n,m,s1,s2,dp);

    cout<<ans;
}