#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int sum = 0;
void transform(Node* root) {
    if (!root) return;
    transform(root->right);
    sum += root->val;
    root->val = sum;
    transform(root->left);
}

void collect(Node* root, vector<int>& arr) {
    if (!root) return;
    collect(root->left, arr);
    arr.push_back(root->val);
    collect(root->right, arr);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    transform(root);

    vector<int> arr;
    collect(root, arr);

    // сортировать необязательно, но на всякий случай
    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i + 1 < arr.size()) cout << " ";
    }
    cout << endl;
    return 0;
}