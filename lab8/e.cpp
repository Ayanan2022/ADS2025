#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n), power(55, 1);

    for (int i = 1; i <= 51; i++) {
        power[i] = power[i - 1] * 2;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        long long cur;
        if (i > 0)
            cur = (a[i] - a[i - 1]) / power[i] + 97;
        else
            cur = a[i] + 97;
        cout << char(cur);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
