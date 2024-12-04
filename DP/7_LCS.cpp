#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
    if(i==0 || j==0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    // if character matches
    if(s1[i-1] == s2[j-1]){
        dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
    }
    else{
        dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }

    return dp[i][j];
}

int main(){
    string s1, s2;

    cin>>s1;
    cin>>s2;

    int n = s1.size(), m=s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    int ans = f(n,m,s1,s2,dp);

    cout<<ans;
}