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

    string s, t;
    int n;
    cin >> s;

    string check(s.size(), '0');

    auto h = prefix_hash(s);
    vector<long long> p(s.size() + 1, 1);
    for (int i = 1; i <= (int)s.size(); i++)
        p[i] = (p[i - 1] * BASE) % MOD;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        long long hash_t = 0;
        for (char c : t)
            hash_t = (hash_t * BASE + (c - 'a' + 1)) % MOD;

        for (int j = 0; j + (int)t.size() <= (int)s.size(); j++) {
            long long substr_hash = get_hash(h, p, j, j + t.size());
            if (substr_hash == hash_t)
                for (int k = j; k < j + (int)t.size(); k++)
                    check[k] = '1';
        }
    }

    for (char c : check) {
        if (c == '0') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    solve();
    return 0;
}
