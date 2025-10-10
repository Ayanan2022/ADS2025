#include <iostream>
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

int countTriangles(Node* root) {
    if (!root) return 0;
    int cnt = 0;
    if (root->left && root->right) cnt++;
    cnt += countTriangles(root->left);
    cnt += countTriangles(root->right);
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = NULL;
    for (int v : arr) root = insert(root, v);

    cout << countTriangles(root) << "\n";
    return 0;
}
