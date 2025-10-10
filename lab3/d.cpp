#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    for(int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        auto it1 = lower_bound(a.begin(), a.end(), l1);
        auto it2 = upper_bound(a.begin(), a.end(), r1);
        int cnt1 = it2 - it1;

        auto it3 = lower_bound(a.begin(), a.end(), l2);
        auto it4 = upper_bound(a.begin(), a.end(), r2);
        int cnt2 = it4 - it3;

        int l_overlap = max(l1, l2);
        int r_overlap = min(r1, r2);
        int cnt_overlap = 0;
        if(l_overlap <= r_overlap) {
            auto it5 = lower_bound(a.begin(), a.end(), l_overlap);
            auto it6 = upper_bound(a.begin(), a.end(), r_overlap);
            cnt_overlap = it6 - it5;
        }

        int total = cnt1 + cnt2 - cnt_overlap;
        cout << total << endl;
    }
}
