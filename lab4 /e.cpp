#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int left = -1;
    int right = -1;
};

int main() {
    int n;
    cin >> n;

    vector<Node> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) tree[x].left = y;
        else tree[x].right = y;
    }

    queue<pair<int, int>> q; 
    q.push({1, 1});
    vector<int> levelCount(n + 1, 0);

    while (!q.empty()) {
        auto [v, level] = q.front();
        q.pop();
        levelCount[level]++;
        if (tree[v].left != -1) q.push({tree[v].left, level + 1});
        if (tree[v].right != -1) q.push({tree[v].right, level + 1});
    }

    cout << *max_element(levelCount.begin(), levelCount.end()) << "\n";
    return 0;
}