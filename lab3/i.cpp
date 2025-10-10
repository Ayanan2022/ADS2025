#include <iostream>
#include <vector> 
#include <algorithm> 
#include <numeric>

using namespace std;

string binarySearch(vector<int> &arr, int x) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return "Yes";

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return "No";
}


int main() {
    int n; cin >> n;
    vector<int> arr; 
    while(n--){
        int m; cin >> m; 
        arr.push_back(m); 
    }
    sort(arr.begin(), arr.end()); 
    int t; cin >> t;

    cout << binarySearch(arr, t);
}
