#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int>freq(26,0);

    for(auto it : s){
        int ch = it-'a';
        freq[ch]++;
    }

    string ans="";

    for(int i=0; i<26; i++){
        while(freq[i]--){
            ans += char(i+'a');
        }
    }

    cout<<ans;
}