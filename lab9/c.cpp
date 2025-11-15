#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int n = S.size();
    string SS = S + S;

    // KMP: pattern = T, text = SS
    string tmp = T + "#" + SS;
    vector<int> pi = prefix_function(tmp);

    for (int i = 0; i < (int)pi.size(); i++) {
        if (pi[i] == n) {
            int pos = i - 2*n; // position in SS where T starts
            if (0 <= pos && pos < n) {
                int k = (n - pos) % n; // right shift
                cout << k;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
