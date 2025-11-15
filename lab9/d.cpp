#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string prev;
    cin >> prev;
    int n;
    cin >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; ++i) cin >> cities[i];

    int L = prev.size();
    vector<int> match(n, 0);

    
    for (int i = 0; i < n; ++i) {
        const string &city = cities[i];
        int cityLen = city.size();

        int best = 0;
        
        for (int len = min(L, cityLen); len > 0; --len) {
            if (prev.substr(L - len) == city.substr(0, len)) {
                best = len;
                break;
            }
        }
        match[i] = best;
    }

    
    int maxMatch = 0;
    for (int x : match) maxMatch = max(maxMatch, x);

    
    cout << count(match.begin(), match.end(), maxMatch) << "\n";
    for (int i = 0; i < n; ++i) {
        if (match[i] == maxMatch)
            cout << cities[i] << "\n";
    }

    return 0;
}
