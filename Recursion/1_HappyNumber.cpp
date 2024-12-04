#include<bits/stdc++.h>
using namespace std;

// A number is called happy if it leads to 1 after a 
// sequence of steps wherein each step number is 
// replaced by the sum of squares of its digit that
// is if we start with Happy Number and keep replacing
// it with digits square sum, we reach 1. 


int sumOfSquares(int n){
    int sum = 0;
    while(n > 0){
        int digit = n%10;
        sum += (digit*digit);
        n /= 10;
    }

    return sum;
}

bool isHappy(int n, set<int>&visited){
    if(n==1) return true;
    // to detect cycle
    if(visited.find(n) != visited.end()) return false;

    visited.insert(n);

    return isHappy(sumOfSquares(n), visited);
}

int nextHappyNumber(int n){
    // start from next number
    n++;

    while(true){
        set<int>visited;
        if(isHappy(n,visited)){
            return n;
        }
        n++;
    }
}

int main(){
    int n;
    cin>>n;

    int ans = nextHappyNumber(n);

    cout<<ans;
}