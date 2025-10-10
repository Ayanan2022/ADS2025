#include <iostream>
#include <vector> 
#include <algorithm> 
#include <numeric>

using namespace std;
int flights(int C, vector<int> &arr, int k){
    int s = 0; 
    for(int &x : arr){
        s += (x + C - 1) / C; 
        if( s > k )return s;
    }

    return s;

}

int search(vector<int> &arr, int k){
    int sum =  accumulate(arr.begin(), arr.end(), 0);
    int left = max(1, (sum + k - 1) / k); 
    int right = *max_element(arr.begin(), arr.end());;

    while(left < right){
        int mid = (left + right) / 2; 
        if(flights(mid, arr, k) <= k){
            right = mid; 
        }
        else left = mid + 1; 
    }
    return left; 
}


int main() {
    int n, k; 
    cin >> n >> k; 
    vector<int> ch; 
    int res = 0; 
    while(n--){
        int p; 
        cin >> p; 
        ch.push_back(p);
    }
    
    cout << search(ch, k);
    
}
