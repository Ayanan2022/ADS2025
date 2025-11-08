#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <climits>
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

string get_common_substring(const vector<string> &v, int len, int k) {
    if (len == 0) return "";

    auto [h1, p1] = prefix_hash(v[0], MOD1, PW1);
    auto [h2, p2] = prefix_hash(v[0], MOD2, PW2);

    unordered_set<uint64_t> common;
    for (int i = 0; i + len <= v[0].size(); i++) {
        long long x1 = get_hash(h1, p1, i, i + len, MOD1);
        long long x2 = get_hash(h2, p2, i, i + len, MOD2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        common.insert(key);
    }

    for (int idx = 1; idx < k; idx++) {
        auto [h1c, p1c] = prefix_hash(v[idx], MOD1, PW1);
        auto [h2c, p2c] = prefix_hash(v[idx], MOD2, PW2);

        unordered_set<uint64_t> cur;
        for (int i = 0; i + len <= v[idx].size(); i++) {
            long long x1 = get_hash(h1c, p1c, i, i + len, MOD1);
            long long x2 = get_hash(h2c, p2c, i, i + len, MOD2);
            uint64_t key = ((uint64_t)x1 << 32) ^ x2;
            cur.insert(key);
        }

        unordered_set<uint64_t> next;
        for (auto &x : common)
            if (cur.count(x)) next.insert(x);

        common.swap(next);
        if (common.empty()) return "";
    }

    auto [ha1, pa1] = prefix_hash(v[0], MOD1, PW1);
    auto [ha2, pa2] = prefix_hash(v[0], MOD2, PW2);

    for (int i = 0; i + len <= v[0].size(); i++) {
        long long x1 = get_hash(ha1, pa1, i, i + len, MOD1);
        long long x2 = get_hash(ha2, pa2, i, i + len, MOD2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        if (common.count(key)) return v[0].substr(i, len);
    }

    return "";
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    vector<string> v(k);
    int r = INT_MAX;
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        r = min(r, (int)v[i].size());
    }

    string ans = "";
    int l = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        string temp = get_common_substring(v, mid, k);
        if (!temp.empty()) {
            ans = temp;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}
