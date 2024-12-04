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

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// Function to find the next prime palindrome
int nextPrimePalindrome(int n) {
    while (true) {
        if (isPalindrome(n) && isPrime(n)) {
            return n; // Return if n is both prime and palindrome
        }
        n++; // Check the next number
    }
}

// Main function
int main() {
    int n;
    cin >> n;

    int result = nextPrimePalindrome(n + 1); // Start checking from the next number
    cout<<result;

}
