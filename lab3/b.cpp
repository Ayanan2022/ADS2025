#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool canSplit(const vector<ll>& arr, ll maxSum, int bl){
    int cnt = 1;
    ll cur = 0;
    for (ll x : arr) {
        if (cur + x > maxSum) {
            cnt++;
            cur = x;
            if (cnt > bl) return false;
        } else {
            cur += x;
        }
    }
    return true;
}

ll binarySearch(const vector<ll>& arr, int bl) {
    ll left = *max_element(arr.begin(), arr.end());
    ll right = accumulate(arr.begin(), arr.end(), 0LL);

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (canSplit(arr, mid, bl)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> gs(n);
    for (int i = 0; i < n; ++i) cin >> gs[i];

    cout << binarySearch(gs, k) << '\n';
    return 0;
}
