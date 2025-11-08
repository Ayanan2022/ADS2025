#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long MOD = 1e9 + 7;
const long long BASE = 31;


vector<long long> prefix_hash(const string &s) {
    int n = s.size();
    vector<long long> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * BASE + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * BASE) % MOD;
    }
    return h;
}


long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, t;
    cin >> s1 >> s2 >> t;

    int n = s1.size(), m = t.size();

    auto h1 = prefix_hash(s1);
    auto h2 = prefix_hash(s2);

    vector<long long> p(n + 1, 1);
    for (int i = 1; i <= n; i++)
        p[i] = (p[i - 1] * BASE) % MOD;

    // Хэш строки t
    long long hash_t = 0;
    for (char c : t)
        hash_t = (hash_t * BASE + (c - 'a' + 1)) % MOD;

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        long long h_s1 = get_hash(h1, p, i, i + m);
        long long h_s2 = get_hash(h2, p, i, i + m);
        if (h_s1 == hash_t && h_s2 == hash_t)
            count++;
    }

    cout << count << '\n';
}

int main() {
    solve();
    return 0;
}
