// Given a “2 x n” board and tiles of size “2 x 1”,
// count the number of ways to tile the given board using the 2 x 1 tiles.
// A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. 

#include<bits/stdc++.h>
using namespace std;

int rec(int n){
    if(n<=2){
        return n;
    }

    return rec(n-1) + rec(n-2);
}

int main(){
    int n;
    cin>>n;

    // int count = rec(n);
    // cout<<count;

    vector<int>dp(n+1,0);
    dp[0] = 1;
    if(n>=1) dp[1] = 1;

    for(int i = 2 ; i <= n ; ++i){
        dp[i] = dp[i-1]+ dp[i-2];
        // cout<<dp[i]<<" ";
    }

    cout<<dp[n];
}