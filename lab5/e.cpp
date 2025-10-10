#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    long long total = 0;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "insert") {
            long long x;
            cin >> x;
            if ((int)heap.size() < k) {
                heap.push(x);
                total += x;
            } else if (k > 0 && x > heap.top()) {
                total -= heap.top();
                heap.pop();
                heap.push(x);
                total += x;
            }
        } else { // print
            cout << total << "\n";
        }
    }
}
