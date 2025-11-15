#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    long long ans = 0;

    for (int i = 1; 2 * i < n; i++) {
        
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (s[j] != s[i + j]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }

    cout << ans << "\n";
    return 0;
}
