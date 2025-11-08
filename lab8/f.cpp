#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cstdint>

using namespace std;

const long long MOD1 = 1000000007;
const long long MOD2 = 1000000009;
const long long PW1 = 31;
const long long PW2 = 37;

pair<vector<long long>, vector<long long>> prefix_hash(const string &s, long long mod, long long pw) {
    int n = s.size();
    vector<long long> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return {h, p};
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r, long long mod) {
    long long res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    auto [h1, p1] = prefix_hash(s, MOD1, PW1);
    auto [h2, p2] = prefix_hash(s, MOD2, PW2);

    unordered_set<uint64_t> substr_hashes;

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            long long x1 = get_hash(h1, p1, i, i + len, MOD1);
            long long x2 = get_hash(h2, p2, i, i + len, MOD2);
            uint64_t key = ((uint64_t)x1 << 32) ^ x2;
            substr_hashes.insert(key);
        }
    }

    cout << substr_hashes.size() << "\n";
    return 0;
}
