#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    string s, t;
    map<string, string> mp;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        bool ok = false;

        // заменяем for(auto it : mp) на обычный итераторный цикл
        for (map<string, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
            if (it->second == s) {
                mp[it->first] = t;
                ok = true;
            }
        }

        if (!ok) mp[s] = t;
    }

    cout << mp.size() << '\n';

    for (map<string, string>::iterator it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ' ' << it->second << '\n';
    }

    return 0;
}
