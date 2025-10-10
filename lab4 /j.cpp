#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result;

void buildBalanced(const vector<int>& arr, int l, int r) {
    if (l > r) return;
    int mid = (l + r) / 2;
    result.push_back(arr[mid]);
    buildBalanced(arr, l, mid - 1);
    buildBalanced(arr, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 
    int len = (1 << n) - 1; // 2^n - 1
    vector<int> arr(len);

    for (int i = 0; i < len; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    buildBalanced(arr, 0, len - 1);

    for (int i = 0; i < len; i++) {
        cout << result[i];
        if (i + 1 != len) cout << " ";
    }
    cout << "\n";

    return 0;
}