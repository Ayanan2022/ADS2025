#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int v) {
    if (!root) return new Node(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    Node* root = NULL;
    for (int v : a) root = insert(root, v);

    if (!root) return 0;

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    vector<long long> levelSum;

    while (!q.empty()) {
        Node* cur = q.front().first;
        int level = q.front().second;
        q.pop();
        if (level >= (int)levelSum.size()) levelSum.push_back(0);
        levelSum[level] += cur->val;
        if (cur->left) q.push({cur->left, level + 1});
        if (cur->right) q.push({cur->right, level + 1});
    }

    cout << levelSum.size() << "\n";
    for (long long s : levelSum) cout << s << " ";
    cout << "\n";
    return 0;
}