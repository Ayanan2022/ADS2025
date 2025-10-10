#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    int count; // количество одинаковых ключей
    Node* left;
    Node* right;
    Node(int x) : key(x), count(1), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key == root->key) {
        root->count++; // увеличиваем кратность
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* remove(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->key) {
        root->left = remove(root->left, key);
    } else if (key > root->key) {
        root->right = remove(root->right, key);
    } else {
        // нашли ключ
        if (root->count > 1) {
            root->count--; // уменьшаем кратность
            return root;
        }

        // если count == 1, удаляем узел
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // два потомка
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->count = temp->count;
            temp->count = 1; // сбросить, чтобы удалить только 1 копию
            root->right = remove(root->right, temp->key);
        }
    }
    return root;
}

int countKey(Node* root, int key) {
    if (!root) return 0;
    if (key == root->key) return root->count;
    else if (key < root->key) return countKey(root->left, key);
    else return countKey(root->right, key);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    Node* root = nullptr;

    while (q--) {
        string cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == "insert") {
            root = insert(root, x);
        } else if (cmd == "delete") {
            root = remove(root, x);
        } else if (cmd == "cnt") {
            cout << countKey(root, x) << "\n";
        }
    }
    return 0;
}