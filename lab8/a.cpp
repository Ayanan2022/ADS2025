#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

const long long MOD = 1e9 + 7;

string hashing(const string &s) {
    long long h = 0, p = 1;
    for (char c : s) {
        h = (h + ((c - 47) * p) % MOD) % MOD;
        p = (p * 11) % MOD;
    }
    return to_string(h);
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    vector<string> v;
    unordered_set<string> st;

    cin >> n;
    for (int i = 0; i < n * 2; i++) {
        cin >> s;
        v.push_back(s);
        st.insert(s);
    }

    int count = 0;

    for (int i = 0; i < (int)v.size(); i++) {
        if (count == n) break;
        string hs = hashing(v[i]);
        if (st.find(hs) != st.end()) { 
            cout << "Hash of string \"" << v[i] << "\" is " << hs << '\n';
            count++;
        }
    }
}

int main() {
    solve();
    return 0;
}
