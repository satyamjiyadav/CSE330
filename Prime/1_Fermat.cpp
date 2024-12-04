#include<bits/stdc++.h>
using namespace std;


// Fermat's factorization method is an efficient algorithm 
// to factorize a number n (n=odd)
// into two factors p and q such that n = p*q
// n = x^2-y^2 => n = (x+y)(x-y)

bool perfectSquare(int num){
    int root = sqrt(num);
    return root * root == num;
}

pair<int,int> fermats(int n){
    int x = ceil(sqrt(n));
    int y2;

    while(true){
        y2 = x*x - n;
        if(perfectSquare(y2)){
            int y = sqrt(y2);
            return {x+y, x-y};
        }
        x++;
    }
}

int main(){
    int n;
    cin>>n;

    if(n%2 == 0){
        cout<<"Fermets is only for odd number";
    }
    else{
        pair<int,int>factors = fermats(n);
        cout<<factors.first<<" "<<factors.second;
    }
}