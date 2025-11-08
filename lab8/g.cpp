#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    auto [h1, p1] = prefix_hash(s, MOD1, PW1);
    auto [h2, p2] = prefix_hash(s, MOD2, PW2);

    unordered_map<uint64_t, int> mp;

   
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = i + 1; j <= (int)s.size(); j++) {
            long long x1 = get_hash(h1, p1, i, j, MOD1);
            long long x2 = get_hash(h2, p2, i, j, MOD2);
            uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            mp[key]++;
        }
    }

   
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--; 

        long long x1 = get_hash(h1, p1, l, r, MOD1);
        long long x2 = get_hash(h2, p2, l, r, MOD2);
        uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;

        cout << mp[key] << '\n';
    }
}

int main() {
    solve();
    return 0;
}