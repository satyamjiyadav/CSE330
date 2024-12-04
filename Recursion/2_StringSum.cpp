#include<bits/stdc++.h>
using namespace std;


// Given a string of digits, determine whether it is a
// ‘sum-string’. A string S is called a sum-string if
// the rightmost substring can be written as the sum
// of two substrings before it and the same is 
// recursively true for substrings before it. 

// “12243660” is a sum string. 
// Explanation : 24 + 36 = 60, 12 + 24 = 36


string string_sum(string str1, string str2){
    int n1 = 0;
    for(auto it : str1){
        int dig = it-'0';
        n1 = n1*10 + dig;
    }

    int n2 = 0;
    for(auto it : str2){
        int dig = it-'0';
        n2 = n2*10 + dig;
    }

    int sum = n1+n2;
    string ans = "";

    while(sum>0){
        char ch = (sum%10+'0');
        sum = sum/10;
        ans += ch;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

bool checkSumStrUttil(string str, int beg, int len1, int len2){
    string s1 = str.substr(beg, len1);
    string s2 = str.substr(beg+len1, len2);
    string s3 = string_sum(s1,s2);
    // cout<<s3<<" ";

    

    int s3_len = s3.size();

    if(s3_len > str.size() - len1 - len2 - beg){
        return false;
    }

    if(s3 == str.substr(beg+len1+len2 , s3_len)){
        if(beg+len1+len2+s3_len == str.size()) return true;

        return checkSumStrUttil(str, beg+len1, len2, s3_len);
    }

    return false;

}


// Returns true if str is sum string, else false.
bool isSumStr(string s){
    int n = s.size();

    // choosing first two numbers and checking
    // whether it is sum-string or not.  

    for(int i=1; i<n; i++){
        for(int j=1; i+j < n; j++){
            if(checkSumStrUttil(s, 0, i, j)){
                return true;
            }
        }
    } 

    return false; 
}

int main(){
    string s;

    cin>>s;

    bool ans = isSumStr(s);

    if(ans == 1)cout<<"true";
    else cout<<"false";
}