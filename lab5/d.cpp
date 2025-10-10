#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    int ops = 0;
    while (pq.top() < k && pq.size() > 1) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + 2 * b);
        ops++;
    }

    if (pq.top() >= k) cout << ops;
    else cout << -1;
}