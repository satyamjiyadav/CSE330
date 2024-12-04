#include <bits/stdc++.h>
using namespace std;

// Function to perform Sieve of Atkins
void sieveOfAtkins(int limit) {
    // Create a boolean array "prime[0..limit]" and initialize all entries as false
    vector<bool> prime(limit + 1, false);

    // Mark the first few primes
    if (limit > 2) prime[2] = true;
    if (limit > 3) prime[3] = true;

    // Loop through all values of x, y
    for (int x = 1; x * x <= limit; ++x) {
        for (int y = 1; y * y <= limit; ++y) {
            // First condition: x^2 + y^2 is a prime number and it's <= limit
            int n = 4 * x * x + y * y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
                prime[n] = !prime[n];
            }
            
            // Second condition: 3x^2 + y^2
            n = 3 * x * x + y * y;
            if (n <= limit && n % 12 == 7) {
                prime[n] = !prime[n];
            }

            // Third condition: x^2 + 3y^2
            n = x * x + 3 * y * y;
            if (n <= limit && n % 12 == 11) {
                prime[n] = !prime[n];
            }
        }
    }

    // Mark all multiples of squares of primes as non-prime
    for (int r = 5; r * r <= limit; ++r) {
        if (prime[r]) {
            for (int i = r * r; i <= limit; i += r * r) {
                prime[i] = false;
            }
        }
    }

    // Print the primes
    for (int n = 2; n <= limit; ++n) {
        if (prime[n]) {
            cout << n << " ";
        }
    }
}

// Driver code to test the sieve
int main() {
    int n;
    cin >> n;
    sieveOfAtkins(n);
    return 0;
}
