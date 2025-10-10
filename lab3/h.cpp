#include <iostream>
#include <vector> 
#include <algorithm> 
#include <numeric>

using namespace std;

int Binarysearch(vector<int> &arr, int n){
    int left = 0;
    int right = arr.size() - 1;

    while(left < right){
        int mid = left + (right - left) / 2; 
        if(arr[mid] >= n){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left + 1; 
}


int main() {
    int N, M; cin >> N >> M; 
    vector<int> prefix(N);
    for (int i = 0; i < N; i++) {
        int s; cin >> s;
        prefix[i] = s + (i > 0 ? prefix[i - 1] : 0);
    }

    while(M--){
        int m; cin >> m; 
        cout << Binarysearch(prefix, m) << endl; 
    }
}
