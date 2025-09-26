#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    queue<int> qs, qk;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') qs.push(i);
        else qk.push(i);
    }

    while (!qs.empty() && !qk.empty()) {
        int si = qs.front(); qs.pop();
        int ki = qk.front(); qk.pop();

        if (si < ki) {
            
            qs.push(si + n);
        } else {
            
            qk.push(ki + n);
        }
    }

    if (!qs.empty()) cout << "SAKAYANAGI\n";
    else cout << "KATSURAGI\n";

    return 0;
}
