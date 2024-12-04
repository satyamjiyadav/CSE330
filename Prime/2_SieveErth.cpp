#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector<int>prime(n+1, true);

    prime[0] = prime[1] = false;

    for(int i=2; i*i <= n; i++){
        if(prime[i] == true){
            // mark all multiple of i false
            for(int j = i*i; j<=n; j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i=0; i<=n; i++){
        if(prime[i]==true)cout<<i<<" ";
    }
}

// t.c = O(nlog(log(n)))