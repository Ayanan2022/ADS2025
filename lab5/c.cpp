#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        pq.push(x);
    }

    long long money = 0;
    for (int i = 0; i < m; i++) {
        int top = pq.top(); pq.pop();
        money += top;
        pq.push(top - 1);
    }

    cout << money;
}
