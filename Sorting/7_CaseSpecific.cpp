#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> lower(26, 0), upper(26, 0);

    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            lower[ch - 'a']++;
        } else if (ch >= 'A' && ch <= 'Z') {
            upper[ch - 'A']++;
        }
    }

    string ans = "";
    int l = 0, u = 0;


    for (char ch : s) {
        if (ch >= 'a' && ch <= 'z') {
            while (l < 26 && lower[l] == 0) l++;
            if (l < 26) {
                ans += (char)(l + 'a');
                lower[l]--;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            while (u < 26 && upper[u] == 0) u++;
            if (u < 26) {
                ans += (char)(u + 'A');
                upper[u]--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
