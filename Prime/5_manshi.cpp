#include <bits/stdc++.h>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;       // 0 and 1 are not prime
    if (n <= 3) return true;        // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

    // Check divisors from 5 to sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        // only check 6k+1 -> 5 7 11 13
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to generate a series of prime numbers up to 'limit'
void primeSeries(int limit) {
    for (int i = 2; i <= limit; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cin>>n;

    primeSeries(n);
}
