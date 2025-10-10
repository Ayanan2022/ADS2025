#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insert(Node* root, int val) {
    if (root == NULL) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* findNode(Node* root, int target) {
    if (root == NULL) return NULL;
    if (root->val == target) return root;
    if (target < root->val) return findNode(root->left, target);
    else return findNode(root->right, target);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int target;
    cin >> target;

    Node* subRoot = findNode(root, target);
    preorder(subRoot);
    cout << "\n";

    return 0;
}