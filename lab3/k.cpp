#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t; 
    cin >> n >> t;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // Строим префиксы
    vector<int> prefix(n+1, 0);
    for(int i = 0; i < n; i++) prefix[i+1] = prefix[i] + arr[i];

    int ans = n+1; // пока максимальная длина
    for(int left = 0; left < n; left++) {
        // бинарный поиск right
        int low = left+1, high = n;
        while(low <= high) {
            int mid = (low + high)/2;
            if(prefix[mid] - prefix[left] >= t) high = mid - 1;
            else low = mid + 1;
        }
        if(low <= n) ans = min(ans, low - left);
    }

    if(ans == n+1) cout << 0 << endl; // если нет подмассива
    else cout << ans << endl;
    return 0;
}