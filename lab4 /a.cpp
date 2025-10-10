#include <iostream>
#include <string>
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

bool checkPath(Node* root, const string& path) {
    Node* current = root;
    for (char dir : path) {
        if (current == NULL) return false;
        if (dir == 'L') current = current->left;
        else current = current->right;
    }
    return current != NULL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    for (int i = 0; i < m; i++) {
        string path;
        cin >> path;
        cout << (checkPath(root, path) ? "YES\n" : "NO\n");
    }

    return 0;
}