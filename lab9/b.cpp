#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int k;
    cin >> s >> k;
    cin.ignore();
    getline(cin, t);

    string combined = s + "#" + t;
    vector<int> pi = prefix_function(combined);

    int count = 0;
    int len = s.size();
    for(int i = len + 1; i < combined.size(); i++) {
        if(pi[i] == len) count++;
    }

    if(count >= k) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
