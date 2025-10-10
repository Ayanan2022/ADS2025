#include <iostream>
#include <vector>
#include <algorithm>
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
    else if (v > root->val) root->right = insert(root->right, v);
    return root;
}

int diameter = 0;

int depth(Node* root) {
    if (!root) return 0;
    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);
    diameter = max(diameter, leftDepth + rightDepth + 1);
    return max(leftDepth, rightDepth) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = NULL;
    for (int v : arr) root = insert(root, v);

    depth(root);
    cout << diameter << "\n";
    return 0;
}