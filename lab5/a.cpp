#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n; 
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    long long ans = 0;
    while (pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans;
}