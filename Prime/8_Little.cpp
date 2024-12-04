#include <bits/stdc++.h>
using namespace std;

// 3^(7-5) = 3^5
// ans  = 5
// a^(p-2) = mod p
// x = a^(p-2) mod p
// 3^(7-2)%7
// 3^5%7
// 243%7 = 5

// Function to calculate (base^exp) % mod using modular exponentiation
long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1; // Initialize result as 1
    base = base % mod;    // Update base if it is >= mod

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // exp must be even now
        exp = exp / 2;        // Reduce exp by half
        base = (base * base) % mod; // Square the base
    }

    return result;
}

// Function to find the modular inverse of 'a' under modulo 'p' using Fermat's Little Theorem
// Works only if 'p' is prime
long long modularInverse(long long a, long long p) {
    // a^(p-1) ≡ 1 (mod p) => a^(p-2) ≡ a^(-1) (mod p)
    return modularExponentiation(a, p - 2, p);
}

int main() {
    long long a, p;

    // Input the number 'a' and the prime modulus 'p'

    cin >> a;
    cin >> p;

    if (__gcd(a, p) != 1) {
        cout << "Modular inverse doesn't exist as gcd(a, p) != 1.\n";
    } else {
        // Calculate modular inverse using Fermat's Little Theorem
        long long inverse = modularInverse(a, p);
        cout << inverse << endl;
    }

    return 0;
}
