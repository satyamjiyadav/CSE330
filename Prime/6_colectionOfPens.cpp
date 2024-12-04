// There are three piles of pens. A pens in the first 
// pile and B pens in the second Pile.Find 
// the minimum number of pens that should be there 
// in the third pile so that sum of all three piles
//  produces either a prime number or unity. 
// Note: there should be atleast one pen in the third p


#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false; // Numbers <= 1 are not prime
    if (n <= 3) return true; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Function to find the minimum pens in the third pile
int findMinPens(int A, int B) {
    int sum = A + B; // Sum of first two piles
    int C = 1; // Start checking from C = 1

    while (true) {
        int total = sum + C; // Total pens across all piles
        if (total == 1 || isPrime(total)) {
            return C; // Return C if the condition is met
        }
        C++; // Increment C and try again
    }
}

int main() {
    int A, B;
    cin >> A >> B; // Input number of pens in the first two piles
    cout << findMinPens(A, B) << endl;
   
}
