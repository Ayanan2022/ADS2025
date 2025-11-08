#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const long long MOD = 1e9 + 7;
const long long PW = 31;

vector<long long> prefix_hash(const string& s, vector<long long>& p) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    p.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * PW + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * PW) % MOD;
    }
    return h;
}

long long get_hash(const vector<long long>& h, const vector<long long>& p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

void solve(int n) {
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    string long_str;
    cin >> long_str;

    vector<long long> p;
    auto h = prefix_hash(long_str, p);

    vector<long long> str_cnt(n + 1, 0);
    long long mx = 0;

    for (int i = 1; i <= n; i++) {
        long long hash_s = 0, cnt = 0;
        for (char c : s[i]) hash_s = (hash_s * PW + (c - 'a' + 1)) % MOD;

        for (int j = 0; j + s[i].size() <= long_str.size(); j++) {
            long long substr_hash = get_hash(h, p, j, j + s[i].size());
            if (substr_hash == hash_s) cnt++;
        }
        mx = max(mx, cnt);
        str_cnt[i] = cnt;
    }

    cout << mx << '\n';
    for (int i = 1; i <= n; i++) {
        if (str_cnt[i] == mx) cout << s[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    while (cin >> tt && tt != 0) {
        solve(tt);
    }

    return 0;
}
